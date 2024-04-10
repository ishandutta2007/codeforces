#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

string gt(string s)
{
        string res;
        for(int i=0;i<s.size();i++)
        {
                if(s[i]=='u')
                {
                        res+="oo";
                        continue;
                }
                if(s[i]=='k')
                {
                        int value=-1;
                        for(int j=i+1;j<s.size();j++)
                        {
                                if(s[j]!='k')
                                {
                                        if(s[j]!='h') break;
                                        value=j;
                                        break;
                                }
                        }
                        if(value!=-1)
                        {
                                i=value-1;
                                continue;
                        }
                }
                res+=s[i];
        }
        return res;
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int n;
        cin>>n;
        set<string>st;
        for(int i=1;i<=n;i++)
        {
                string s;
                cin>>s;
                //s=gt(s);
                ///cout<<" = "<<s<<" , "<<gt(s)<<"\n";
                s=gt(s);
                st.insert(s);
        }
        cout<<st.size()<<"\n";
        return 0;
        for(auto &it:st)
        {
                cout<<it<<" ";
        }
        cout<<"\n";
        return 0;
}
/**

u
oo <=> u

**/