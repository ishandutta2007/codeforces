// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define fi first
#define se second
#define pb push_back
 
#define ll long long
#define pii pair<int, int>
//#define int ll
const int MOD = 1000000007;

void upd(int idx, int l, int r, int i, int v, vector<int>& dt) {
    if(!(l <= i && i < r)) return;
    assert(r-l);
    if(r-l == 1) { 
        assert(l == i);
        dt[idx] = max(dt[idx], v);
        return;
    }
    upd(idx*2, l, (l+r)/2, i, v, dt);
    upd(idx*2+1, (l+r)/2, r, i, v, dt);
    dt[idx] = max(dt[idx*2], dt[idx*2+1]);
}
int qry(int idx, int l, int r, int L, int R, vector<int>& dt) {
    if(L <= l && r <= R) return dt[idx];
    if(R <= l || r <= L) return 0;
    assert(r-l);
    return max(qry(idx*2, l, (l+r)/2, L, R, dt),
               qry(idx*2+1, (l+r)/2, r, L, R, dt));
}

int cf[100005];
int dp1[100005];
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    rep(i, n) {
        int u, v; cin >> u >> v;
        cf[u]++; cf[v+1]--;
    }
    rep1(i, m) cf[i] += cf[i-1];
    vector<int> Seg(1<<20);
    int qj = 0, pfb = 0;
    n = max(n, m);
    rep1(i, m) {
        dp1[i] = qry(1, 0, 1<<17, 0, cf[i]+1, Seg) + 1;
        upd(1, 0, 1<<17, cf[i], dp1[i], Seg);
    }
    Seg = vector<int>(1<<20);
    for(int i=m; i>=1; i--) {
        qj = max(qj, dp1[i] + pfb);
        int cur = qry(1, 0, 1<<17, 0, cf[i]+1, Seg) + 1;
        upd(1, 0, 1<<17, cf[i], cur, Seg);
        pfb = max(pfb, cur);
    }
    cout << qj;
}