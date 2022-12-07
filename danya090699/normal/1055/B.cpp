#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, l;
    cin>>n>>m>>l;
    int ar[n], q=0, nq=0;
    for(int a=0; a<n; a++)
    {
        scanf("%d", &ar[a]);
        if(ar[a]>l) q++;
    }
    for(int a=0; a+1<n; a++) if(ar[a]>l and ar[a+1]>l) nq++;
    for(int a=0; a<m; a++)
    {
        int ty;
        scanf("%d", &ty);
        if(ty)
        {
            int p, d;
            scanf("%d%d", &p, &d);
            p--;
            if(ar[p]<=l)
            {
                ar[p]+=d;
                if(ar[p]>l)
                {
                    q++;
                    if(p!=0)
                    {
                        if(ar[p-1]>l) nq++;
                    }
                    if(p+1<n)
                    {
                        if(ar[p+1]>l) nq++;
                    }
                }
                ar[p]=min(ar[p], l+1);
            }
        }
        else printf("%d\n", q-nq);
    }
}