#include <bits/stdc++.h>

using namespace std;


int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        int q;
        cin>>q;

        while(q--)
        {
                string s,t;
                cin>>s>>t;
                int a=0,b=0;
                for(int i=0;i<(int)s.size();i++)
                {
                        a|=(1<<(s[i]-'a'));
                        b|=(1<<(t[i]-'a'));
                }
                if(a&b)
                        cout<<"YES\n";
                else
                        cout<<"NO\n";
        }

        return 0;
}