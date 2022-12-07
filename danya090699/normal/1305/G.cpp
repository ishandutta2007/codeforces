#include <bits/stdc++.h>
using namespace std;
int q[1<<18], pr[1<<18], si[1<<18], sp[100];
int find_pr(int v)
{
    int yk=0;
    while(pr[v]!=v) sp[yk++]=v, v=pr[v];
    for(int a=0; a<yk; a++) pr[sp[a]]=v;
    return v;
}
main()
{
    //freopen("input.txt", "r", stdin);
    q[0]=1;
    for(int a=0; a<(1<<18); a++) pr[a]=a, si[a]=1;
    int n;
    long long an=0;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        q[x]++, an-=x;
    }
    for(int w=(1<<18)-1; w>=0; w--)
    {
        for(int mask=w; ; mask=(mask-1)&w)
        {
            int u=mask, v=w^u;
            if(q[u] and q[v])
            {
                u=find_pr(u), v=find_pr(v);
                if(u!=v)
                {
                    if(si[u]==1 and si[v]==1) an+=1ll*w*(q[u]+q[v]-1);
                    else if(si[u]==1) an+=1ll*w*q[u];
                    else if(si[v]==1) an+=1ll*w*q[v];
                    else an+=w;

                    if(si[u]<si[v]) swap(u, v);
                    si[u]+=si[v];
                    pr[v]=u;
                }
            }
            if(mask==0) break;
        }
    }
    cout<<an;
}