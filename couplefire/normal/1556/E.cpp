#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1<<17;
const int INF = 1e17;

int n, q;
int a[N], b[N], arr[N], psum[N];
int mx[N<<1], mn[N<<1];

void build(int v = 1, int tl = 0, int tr = N-1){
    if(tl==tr){
        mx[v] = mn[v] = psum[tl];
        return;
    }
    int tm = (tl+tr)>>1;
    build(v<<1, tl, tm); build(v<<1|1, tm+1, tr);
    mx[v] = max(mx[v<<1], mx[v<<1|1]);
    mn[v] = min(mn[v<<1], mn[v<<1|1]);
}

array<int, 2> query(int l, int r, int v = 1, int tl = 0, int tr = N-1){
    if(tr<l || tl>r) return {INF, -INF};
    if(l<=tl && tr<=r) return {mn[v], mx[v]};
    int tm = (tl+tr)>>1;
    auto [a, b] = query(l, r, v<<1, tl, tm);
    auto [c, d] = query(l, r, v<<1|1, tm+1, tr);
    return {min(a, c), max(b, d)};
}

signed main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for(int i = 1; i<=n; ++i)
        cin >> a[i];
    for(int i = 1; i<=n; ++i)
        cin >> b[i];
    for(int i = 1; i<=n; ++i)
        arr[i] = b[i]-a[i];
    for(int i = 1; i<=n; ++i)
        psum[i] = psum[i-1]+arr[i];
    build();
    while(q--){
        int l, r; cin >> l >> r;
        if(psum[r]-psum[l-1]!=0){
            cout << -1 << '\n';
            continue;
        }
        auto [a, b] = query(l, r);
        a -= psum[l-1], b-=psum[l-1];
        if(a<0){
            cout << -1 << '\n';
            continue;
        }
        cout << b << '\n';
    }
}