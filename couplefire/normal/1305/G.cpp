#include <bits/stdc++.h>
using namespace std;

const int N = 1<<18;

int n, fa[N], siz[N], cnt[N];
long long ans;

int find(int v){return v==fa[v]?v:fa[v]=find(fa[v]);}

int unite(int u, int v){
    u = find(u), v = find(v);
    if(u==v) return 0;
    if(siz[u]>siz[v]) swap(u, v);
    int tmp = (siz[u]==1?cnt[u]:1)+(siz[v]==1?cnt[v]:1)-1;
    fa[u] = v; siz[v]+=siz[u];
    return tmp;
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i<n; ++i){
        int a; cin >> a; cnt[a]++; ans -= a;
    } cnt[0]++;
    for(int i = 0; i<N; ++i)
        fa[i] = i, siz[i] = 1;
    for(int i = N-1; i>=0; --i)
        for(int j = i; j; j = (j-1)&i)
            if(cnt[j] && cnt[i^j]) ans += 1ll*i*unite(j, i^j);
    cout << ans << '\n';
}