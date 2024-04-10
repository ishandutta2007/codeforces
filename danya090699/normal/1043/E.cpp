#include <bits/stdc++.h>
#define int long long
using namespace std;
struct el
{
    int a, b, nu;
};
bool comp(el x, el y){return x.a-x.b<y.a-y.b;}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    int va[n], vb[n];
    el ar[n];
    int pref=0, suf=0;
    for(int a=0; a<n; a++)
    {
        scanf("%lld%lld", &ar[a].a, &ar[a].b);
        ar[a].nu=a;
        va[a]=ar[a].a, vb[a]=ar[a].b;
        suf+=ar[a].b;
    }
    sort(ar, ar+n, comp);
    vector <int> sv[n];
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    int an[n];
    for(int a=0; a<n; a++)
    {
        suf-=ar[a].b;
        int nu=ar[a].nu;
        an[nu]=vb[nu]*a+pref+va[nu]*(n-1-a)+suf;
        for(int b=0; b<sv[nu].size(); b++)
        {
            int ne=sv[nu][b];
            if(va[ne]-vb[ne]<va[nu]-vb[nu]) an[nu]-=vb[nu]+va[ne];
            else an[nu]-=va[nu]+vb[ne];
        }
        pref+=ar[a].a;
    }
    for(int a=0; a<n; a++) printf("%lld ", an[a]);
}