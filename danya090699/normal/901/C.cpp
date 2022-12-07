#include <bits/stdc++.h>
using namespace std;
const int sz=3e5+10, inf=1e9;
vector <int> sv[sz];
bool us[sz];
int ar[sz], pr[sz], h[sz];
void dfs(int v, int pre, int he)
{
    us[v]=1, pr[v]=pre, h[v]=he;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pre)
        {
            if(us[ne])
            {
                int v1=v, v2=ne, mi=inf, ma=-inf;
                while(v1!=v2)
                {
                    if(h[v1]>h[v2])
                    {
                        mi=min(mi, v1), ma=max(ma, v1), v1=pr[v1];
                    }
                    else
                    {
                        mi=min(mi, v2), ma=max(ma, v2), v2=pr[v2];
                    }
                }
                mi=min(mi, v1), ma=max(ma, v1);
                ar[mi]=min(ar[mi], ma);
            }
            else dfs(ne, v, he+1);
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, q;
    cin>>n>>m;
    for(int a=0; a<n; a++) ar[a]=n;
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    for(int a=0; a<n; a++)
    {
        if(us[a]==0) dfs(a, -1, 0);
    }
    for(int a=n-2; a>=0; a--) ar[a]=min(ar[a], ar[a+1]);
    long long pref[n];
    pref[0]=ar[0];
    for(int a=1; a<n; a++) pref[a]=pref[a-1]+(ar[a]-a);
    cin>>q;
    for(int a=0; a<q; a++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        l--, r--;
        int p=lower_bound(ar, ar+n, r+1)-ar;
        p=max(p, l);
        long long an=0;
        if(p!=0) an=pref[p-1];
        if(l!=0) an-=pref[l-1];
        int qq=r-p+1;
        an+=(1ll*(1+qq)*qq)/2;
        printf("%lld\n", an);
    }
}