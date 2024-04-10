#include <bits/stdc++.h>
using namespace std;
const int sz=1e6+10;
vector <int> dot[sz];
vector <long long> pref[sz];
int n, m, re[sz], x;
void build(int v)
{
    vector <int> l, r;
    if(v*2<=n)
    {
        build(v*2);
        l.insert(l.begin(), dot[v*2].begin(), dot[v*2].end());
        for(int a=0; a<l.size(); a++) l[a]+=re[v*2];
    }
    if(v*2+1<=n)
    {
        build(v*2+1);
        r.insert(r.begin(), dot[v*2+1].begin(), dot[v*2+1].end());
        for(int a=0; a<r.size(); a++) r[a]+=re[v*2+1];
    }
    dot[v].resize(1+l.size()+r.size());
    dot[v][0]=0;
    merge(l.begin(), l.end(), r.begin(), r.end(), dot[v].begin()+1);
    pref[v].resize(dot[v].size()), pref[v][0]=dot[v][0];
    for(int a=1; a<pref[v].size(); a++) pref[v][a]=pref[v][a-1]+dot[v][a];
}
long long count(int v, int di)
{
    int p=upper_bound(dot[v].begin(), dot[v].end(), x-di)-dot[v].begin();
    if(p>0) return (1ll*(x-di)*p)-pref[v][p-1];
    else return 0;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>m;
    for(int a=2; a<=n; a++) scanf("%d", &re[a]);
    build(1);
    for(int a=0; a<m; a++)
    {
        int v, di=0;
        scanf("%d%d", &v, &x);
        long long an=count(v, di);
        while(v!=1)
        {
            di+=re[v];
            if(di<x) an+=x-di;
            if(v&1) an+=count(v-1, di+re[v-1]);
            else if(v+1<=n) an+=count(v+1, di+re[v+1]);
            v=(v>>1);
        }
        printf("%lld\n", an);
    }
}