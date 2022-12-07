#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    string str="abacaba";
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        string s;
        cin>>n>>s;
        bool fo=0;
        for(int a=0; a+7<=n; a++)
        {
            string t=s;
            for(int b=0; b<7; b++)
            {
                if(t[a+b]=='?') t[a+b]=str[b];
            }
            for(int b=0; b<n; b++) if(t[b]=='?') t[b]='z';
            int q=0;
            for(int b=0; b+7<=n; b++)
            {
                if(t.substr(b, 7)==str) q++;
            }
            if(q==1)
            {
                fo=1;
                s=t;
                break;
            }
        }
        if(fo) cout<<"Yes\n"<<s<<"\n";
        else cout<<"No\n";
    }
}