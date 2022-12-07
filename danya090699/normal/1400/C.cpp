#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        int x;
        cin>>s>>x;
        int n=s.size();
        char an[n];
        for(int a=0; a<n; a++) an[a]='1';
        for(int a=0; a<n; a++)
        {
            if(s[a]=='0')
            {
                if(a-x>=0) an[a-x]='0';
                if(a+x<n) an[a+x]='0';
            }
        }
        bool ok=1;
        for(int a=0; a<n; a++)
        {
            if(s[a]=='1')
            {
                bool fo=0;
                if(a-x>=0 and an[a-x]=='1') fo=1;
                if(a+x<n and an[a+x]=='1') fo=1;
                if(!fo) ok=0;
            }
        }
        if(ok)
        {
            for(int a=0; a<n; a++) cout<<an[a];
            cout<<"\n";
        }
        else cout<<"-1\n";
    }
}