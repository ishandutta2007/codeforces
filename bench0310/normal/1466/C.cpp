#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        int n=s.size();
        auto go=[&](int l,int r)->string
        {
            string bad;
            for(int i=max(0,l);i<=min(n-1,r);i++) bad+=s[i];
            return bad;
        };
        vector<bool> vis(26,0);
        int res=0;
        for(int i=0;i<n;i++)
        {
            if((i>=1&&s[i]==s[i-1])||(i>=2&&s[i]==s[i-2]))
            {
                string bad=go(i-5,i+5);
                for(char c:bad) vis[c-'a']=1;
                for(int j=0;j<26;j++)
                {
                    if(vis[j]==0)
                    {
                        s[i]=char(j+'a');
                        break;
                    }
                }
                for(char c:bad) vis[c-'a']=0;
                res++;
            }
        }
        cout << res << "\n";
    }
    return 0;
}