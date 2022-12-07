#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        int r=n, c=m;
        bool usr[n], usc[m];
        for(int a=0; a<n; a++) usr[a]=0;
        for(int a=0; a<m; a++) usc[a]=0;
        for(int a=0; a<n; a++)
        {
            for(int b=0; b<m; b++)
            {
                int x;
                cin>>x;
                if(x)
                {
                    if(usr[a]==0) r--, usr[a]=1;
                    if(usc[b]==0) c--, usc[b]=1;
                }
            }
        }
        if(min(r, c)&1) cout<<"Ashish\n";
        else cout<<"Vivek\n";
    }
}