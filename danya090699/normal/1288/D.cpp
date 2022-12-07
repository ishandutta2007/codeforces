#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    int ar[n][m];
    for(int a=0; a<n; a++) for(int b=0; b<m; b++) scanf("%d", &ar[a][b]);
    int l=-1, r=1e9+10, i, j;
    while(r-l>1)
    {
        int mid=(l+r)>>1, p[1<<m], ok=0;
        for(int a=0; a<(1<<m); a++) p[a]=-1;
        for(int a=0; a<n; a++)
        {
            int mask=0;
            for(int b=0; b<m; b++) mask+=((ar[a][b]>=mid)<<b);
            p[mask]=a;
        }
        for(int m1=0; m1<(1<<m); m1++)
        {
            for(int m2=m1; m2<(1<<m); m2++)
            {
                if(p[m1]!=-1 and p[m2]!=-1 and (m1|m2)==(1<<m)-1)
                {
                    ok=1, i=p[m1], j=p[m2];
                }
            }
        }
        if(ok) l=mid;
        else r=mid;
    }
    cout<<i+1<<" "<<j+1;
}