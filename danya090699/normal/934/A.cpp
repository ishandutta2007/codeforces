#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, an=2e18;
    cin>>n>>m;
    int ar[n], ar2[m];
    for(int a=0; a<n; a++) cin>>ar[a];
    for(int a=0; a<m; a++) cin>>ar2[a];
    for(int a=0; a<n; a++)
    {
        int cu=-2e18;
        for(int b=0; b<n; b++)
        {
            if(b!=a)
            {
                for(int c=0; c<m; c++) cu=max(cu, ar[b]*ar2[c]);
            }
        }
        an=min(an, cu);
    }
    cout<<an;
}