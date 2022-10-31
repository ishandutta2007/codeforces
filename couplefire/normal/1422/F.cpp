#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

const int N = 100001;
const int SZ = 400 * N;

int n, q, lp[2 * N], tree[SZ], lc[SZ], rc[SZ], root[N], cn, mod = 1e9 + 7;
vector <int> a;

int powlog(int a, int b){
    if(b == 0) return 1;
    int ret = powlog(a, b / 2);
    if(b % 2) return 1LL * ret * ret % mod * a % mod;
    return 1LL * ret * ret % mod;
}
void build(int l, int r, int node){
    if(l == r){
        tree[node] = 1;
        return;
    }
    int mid = (l + r) / 2;
    lc[node] = ++cn;
    rc[node] = ++cn;
    build(l, mid, lc[node]);
    build(mid + 1, r, rc[node]);
    tree[node] = 1LL * tree[lc[node]] * tree[rc[node]] % mod;
}
void update(int l, int r, int node, int node2, int idx, int val){
    tree[node] = tree[node2];
    if(l == r){
        tree[node] = 1LL * tree[node] * val % mod;
        return;
    }
    int mid = (l + r) / 2;
    if(idx <= mid){
        lc[node] = ++cn;
        rc[node] = rc[node2];
        update(l, mid, lc[node], lc[node2], idx, val);
    }
    else{
        lc[node] = lc[node2];
        rc[node] = ++cn;
        update(mid + 1, r, rc[node], rc[node2], idx, val);
    }
    tree[node] = 1LL * tree[lc[node]] * tree[rc[node]] % mod;
}
int query(int l, int r, int node, int s, int e){
    if(r < l || r < s || l > e) return 1;
    if(s <= l && r <= e) return tree[node];
    int mid = (l + r) / 2;
    return 1LL *  query(l, mid, lc[node], s, e) * query(mid + 1, r, rc[node], s, e) % mod;
}
void change(int &root, int p, pair <int, int> &c, int x){
    if(x == 0) return;
    int new_root = ++cn;
    c.second += x;
    x = (x + mod - 1) % (mod - 1);
    update(0, n - 1, new_root, root, c.first, powlog(p, x));
    root = new_root;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 2 ; i < 2 * N ; i++){
        if(lp[i]) continue;
        for(int j = i ; j < 2 * N ; j += i){
            if(lp[j] == 0) lp[j] = i;
        }
    }
    cin >> n;
    a.resize(n);
    for(auto &i : a) cin >> i;
    build(0, n - 1, 0);
    vector <vector <pair <int, int> > > sts(2 * N);
    for(int i = 0 ; i < n ; i++){
        if(i > 0) root[i] = root[i - 1];
        else root[i] = 0;
        int x = a[i];
        while(x > 1){
            int p = lp[x];
            int cnt = 0;
            while(x % p == 0){
                x /= p;
                cnt++;
            }
            while(sts[p].size() > 0 && cnt > sts[p].back().second){
                int c = sts[p].back().second;
                change(root[i], p, sts[p].back(), -sts[p].back().second);
                sts[p].pop_back();
                if(sts[p].size() > 0){
                    change(root[i], p, sts[p].back(), c);
                }
            }
            if(sts[p].size() > 0){
                change(root[i], p, sts[p].back(), -cnt);
            }
            sts[p].push_back(make_pair(i, 0));
            change(root[i], p, sts[p].back(), cnt);
        }
    }
    cin >> q;
    int ans = 0;
    for(int i = 0 ; i < q ; i++){
        int l, r;
        cin >> l >> r;
        l = (l + ans) % n + 1;
        r = (r + ans) % n + 1;
        if(r < l) swap(l, r);
        ans = query(0, n - 1, root[r - 1], l - 1, r - 1);
        cout << ans << "\n";
    }
}