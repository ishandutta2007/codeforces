#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 100005;
const int K = 18;

int q, phi[N];
ll dp[K][N], tree[1<<18], lazy[1<<18];
vector<int> ds[N];

void build(int k, int v = 1, int tl = 0, int tr = N-1){
    tree[v] = dp[k][tl], lazy[v] = 0;
    if(tl==tr) return;
    int tm = (tl+tr)>>1;
    build(k, v<<1, tl, tm); build(k, v<<1|1, tm+1, tr);
    tree[v] = min(tree[v<<1], tree[v<<1|1]);
}

void upd(int r, int val, int v = 1, int tl = 0, int tr = N-1){
    if(tr<=r) {tree[v] += val; lazy[v] += val; return;}
    int tm = (tl+tr)>>1;
    upd(r, val, v<<1, tl, tm);
    if(r>tm) upd(r, val, v<<1|1, tm+1, tr);
    tree[v] = min(tree[v<<1], tree[v<<1|1])+lazy[v];
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    for(int i = 0; i<N; ++i) phi[i] = i;
    for(int i = 2; i<N; ++i) if(phi[i]==i)
        for(int j = i; j<N; j+=i)
            phi[j] -= phi[j]/i;
    for(int i = 1; i<N; ++i)
        for(int j = i; j<N; j+=i)
            ds[j].push_back(i);
    for(int i = 1; i<N; ++i) dp[0][i] = 1e18;
    for(int i = 1; i<K; ++i){
        build(i-1);
        upd(0, 0, 0);
        for(int j = 0; j<N; ++j){
            for(auto x : ds[j]) upd(x-1, phi[j/x]);
            dp[i][j] = tree[1];
        }
    } cin >> q;
    while(q--){
        int n, k; cin >> n >> k;
        if(k>=K) cout << n << '\n';
        else cout << dp[k][n] << '\n';
    }
}