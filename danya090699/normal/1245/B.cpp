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
        int n, r, p, s, q=0;
        cin>>n>>r>>p>>s;
        string ss;
        cin>>ss;
        char an[n];
        for(int a=0; a<n; a++)
        {
            if(ss[a]=='R')
            {
                if(p) an[a]='P', p--, q++;
                else an[a]=0;
            }
            if(ss[a]=='P')
            {
                if(s) an[a]='S', s--, q++;
                else an[a]=0;
            }
            if(ss[a]=='S')
            {
                if(r) an[a]='R', r--, q++;
                else an[a]=0;
            }
        }
        if(q*2>=n)
        {
            cout<<"YES\n";
            for(int a=0; a<n; a++)
            {
                if(an[a]==0)
                {
                    if(r) an[a]='R', r--;
                    else if(p) an[a]='P', p--;
                    else an[a]='S', s--;
                }
                cout<<an[a];
            }
            cout<<"\n";
        }
        else cout<<"NO\n";
    }
}