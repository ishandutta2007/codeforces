#include <bits/stdc++.h>
using namespace std;
const int sz=2e6+10;
vector <int> sv[sz];
int va[sz], us[sz];
int maxi, maxi2, rq, vq;
void dfs(int v)
{
    us[v]=1, vq++, rq+=sv[v].size();
    if(va[v]>maxi)
    {
        maxi2=maxi, maxi=va[v];
    }
    else if(va[v]>maxi2) maxi2=va[v];
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(us[ne]==0) dfs(ne);
    }
}
int n, m=0;
int sp[sz][2], ar[sz], nu[sz];
int g_nu(int x)
{
    return nu[lower_bound(ar, ar+n*2, x)-ar];
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n;
    for(int a=0; a<n; a++)
    {
        scanf("%d%d", &sp[a][0], &sp[a][1]);
        ar[a*2]=sp[a][0], ar[a*2+1]=sp[a][1];
    }
    sort(ar, ar+n*2);
    int yk=0;
    while(yk<n*2)
    {
        int cu=ar[yk];
        nu[yk]=m, m++;
        while(yk<n*2)
        {
            if(ar[yk]==cu) yk++;
            else break;
        }
    }
    for(int a=0; a<n; a++)
    {
        int u=sp[a][0], v=sp[a][1];
        int u2=g_nu(u), v2=g_nu(v);
        va[u2]=u, va[v2]=v;
        sv[u2].push_back(v2), sv[v2].push_back(u2);
    }
    int an=0, ok=1;
    for(int a=0; a<m; a++)
    {
        if(us[a]==0)
        {
            maxi=0, maxi2=0, rq=0, vq=0, dfs(a), rq>>=1;
            if(rq<vq) an=max(an, maxi2);
            else if(rq==vq) an=max(an, maxi);
            else ok=0;
        }
    }
    if(ok) cout<<an;
    else cout<<-1;
}