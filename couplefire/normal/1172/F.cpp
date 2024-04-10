#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>

const int N = 1<<20;
const ll INF = (ll)1e16;

int n, q, p, arr[N];
vll tree[N<<1]; ll psum[N];

vll merge(vll a, vll b, int tl, int tr){
    int tm = (tl+tr)>>1;
    vll res(a.size()+b.size()-1, INF);
    for(int i = 0, j = 0; i<(int)a.size(); ++i){
        ll lo = i==0?-INF:a[i]+psum[tm]-psum[max(0, tl-1)]-1ll*p*i,
           hi = i==(int)a.size()-1?INF:a[i+1]-1+psum[tm]-psum[max(0, tl-1)]-1ll*p*i;
        while(j>=0 && (j==(int)b.size() || b[j]>lo)) --j;
        while(j<(int)b.size() && b[j]<=hi) res[i+j] = min(res[i+j], max(a[i], b[j]-psum[tm]+psum[max(0, tl-1)]+1ll*p*i)), ++j;
    } res[0] = -INF;
    return res;
}

vll build(int v = 1, int tl = 0, int tr = N-1){
    if(tl==tr) return tree[v] = {-INF, p-arr[tl]};
    int tm = (tl+tr)>>1;
    return tree[v] = merge(build(v<<1, tl, tm), build(v<<1|1, tm+1, tr), tl, tr);
}

ll query(int l, int r, ll add = 0ll, int v = 1, int tl = 0, int tr = N-1){
    if(tr<l || tl>r) return add;
    if(l<=tl && tr<=r) return add+psum[tr]-psum[max(0, tl-1)]-1ll*p*(upper_bound(tree[v].begin(), tree[v].end(), add)-tree[v].begin()-1);
    int tm = (tl+tr)>>1;
    return query(l, r, query(l, r, add, v<<1, tl, tm), v<<1|1, tm+1, tr);
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q >> p;
    for(int i = 1; i<=n; ++i) cin >> arr[i];
    for(int i = 1; i<N; ++i) psum[i] = psum[i-1]+arr[i];
    build(); 
    while(q--){
        int l, r; cin >> l >> r;
        cout << query(l, r) << '\n';
    }
}