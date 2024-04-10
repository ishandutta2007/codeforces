#include <bits/stdc++.h>
using namespace std;
const int sz=256;
int pr[sz], si[sz], mi[sz];
int find_se(int v)
{
    if(pr[v]!=v) pr[v]=find_se(pr[v]);
    return pr[v];
}
void merge(int u, int v)
{
    //u=find_se(u), v=find_se(v);
    if(u!=v)
    {
        if(si[u]<si[v]) swap(u, v);
        si[u]+=si[v], mi[u]=min(mi[u], mi[v]);
        pr[v]=u;
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    for(int a=0; a<sz; a++)
    {
        pr[a]=a, si[a]=1, mi[a]=a;
    }
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        int cu=mi[find_se(x)];
        while(cu>0)
        {
            int u=find_se(cu), v=find_se(cu-1);
            if(si[u]+si[v]<=k)
            {
                cu=mi[v];
                merge(u, v);
            }
            else break;
        }
        printf("%d ", cu);
    }
}