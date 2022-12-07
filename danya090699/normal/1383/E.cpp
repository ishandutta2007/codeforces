#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    cin>>s;
    int pref=0, suf=0;
    while(pref<s.size() and s[pref]=='0') pref++;
    while(suf<s.size() and s[s.size()-1-suf]=='0') suf++;

    if(pref==s.size()) cout<<s.size();
    else
    {
        s.erase(s.begin(), s.begin()+pref);
        s.erase(s.end()-suf, s.end());

        string s2=s;

        int n=s.size(), pr=-1, ne[n];
        vector <pair <int, int> > st;
        while(s.size())
        {
            char c=s.back();
            int q=0;
            while(s.size() and s.back()==c) s.pop_back(), q++;

            if(c=='0')
            {
                for(int a=s.size(); a<s.size()+q-1; a++)
                {
                    if(s.size()+q<n) ne[a]=s.size()+q;
                    else ne[a]=-1;
                }
                while(st.size() and st.back().first<=q) st.pop_back();

                if(st.size()) ne[s.size()+q-1]=st.back().second+q;
                else ne[s.size()+q-1]=-1;

                st.push_back({q, s.size()});
            }
            else
            {
                for(int a=s.size(); a<s.size()+q-1; a++)
                {
                    if(s.size()+q<n) ne[a]=s.size()+q;
                    else ne[a]=-1;
                }
                ne[s.size()+q-1]=pr, pr=s.size();
            }
        }

        int dp[n], an=0;
        for(int a=0; a<n; a++) dp[a]=0;
        dp[0]=1;
        for(int a=0; a+1<n; a++)
        {
            dp[a+1]=(dp[a+1]+dp[a])%mod;
            if(ne[a]!=-1) dp[ne[a]]=(dp[ne[a]]+dp[a])%mod;
        }
        for(int a=0; a<n; a++)
        {
            if(s2[a]=='1') an=(an+dp[a])%mod;
        }
        an=1ll*an*(pref+1)%mod;
        an=1ll*an*(suf+1)%mod;
        cout<<an;
    }
}