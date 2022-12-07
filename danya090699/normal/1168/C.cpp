#include <bits/stdc++.h>
using namespace std;
const int sz=19, inf=1e9;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, q;
    cin>>n>>q;
    int ar[n];
    for(int a=0; a<n; a++) scanf("%d", &ar[a]);
    int ne[n+1][sz], be[n+1][sz];
    for(int a=n-1; a>=0; a--)
    {
        for(int i=0; i<sz; i++)
        {
            if(a+1<n)
            {
                if(ar[a+1]&(1<<i)) ne[a][i]=a+1;
                else ne[a][i]=ne[a+1][i];
            }
            else ne[a][i]=-1;
        }
        for(int i=0; i<sz; i++) be[a][i]=inf;
        for(int i=0; i<sz; i++)
        {
            if(ar[a]&(1<<i))
            {
                be[a][i]=a;
                int nxt=ne[a][i];
                if(nxt!=-1)
                {
                    for(int j=0; j<sz; j++) be[a][j]=min(be[a][j], be[nxt][j]);
                }
            }
        }
    }
    for(int a=0; a<q; a++)
    {
        int x, y, ok=0;
        scanf("%d%d", &x, &y);
        x--, y--;
        for(int i=0; i<sz; i++)
        {
            if(ar[y]&(1<<i))
            {
                if(be[x][i]<=y) ok=1;
            }
        }
        if(ok) printf("Shi\n");
        else printf("Fou\n");
    }

}