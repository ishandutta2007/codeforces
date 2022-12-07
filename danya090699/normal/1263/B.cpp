#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t)
    {
        t--;
        int n;
        cin>>n;
        int us[10];
        for(int a=0; a<10; a++) us[a]=0;
        set <string> se;
        string s[n];
        for(int a=0; a<n; a++)
        {
            cin>>s[a];
            us[s[a][0]-'0']=1;
        }
        int an=0;
        for(int a=0; a<n; a++)
        {
            if(se.find(s[a])!=se.end())
            {
                an++;
                for(int b=0; ; b++)
                {
                    if(us[b]==0)
                    {
                        us[b]=1;
                        s[a][0]='0'+b;
                        break;
                    }
                }
            }
            se.insert(s[a]);
        }
        cout<<an<<"\n";
        for(int a=0; a<n; a++) cout<<s[a]<<"\n";
    }
}