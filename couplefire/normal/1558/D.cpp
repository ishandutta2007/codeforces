#include <bits/stdc++.h>
using namespace std;

const int N = 400005;
const int MOD = 998244353;

inline int add(int a, int b){return (a+b>=MOD)?a+b-MOD:a+b;}
inline void inc(int& a, int b){a = add(a, b);}
inline int sub(int a, int b){return (a-b<0)?a-b+MOD:a-b;}
inline void dec(int &a, int b){a = sub(a, b);}
inline int mul(int a, int b){return 1ll*a*b%MOD;}
inline void grow(int &a, int b){a = mul(a, b);}

int bpow(int a, int b){
    int res = 1;
    for(; b; grow(a, a), b>>=1)
        if(b&1) grow(res, a);
    return res;
}

int inv(int a){return bpow(a, MOD-2);}

int fact[N], ifact[N];

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;
    FenwickTree(){}
    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }
    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }
    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }
    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
} tree;

int comb(int a, int b){
    return mul(fact[a], mul(ifact[b], ifact[a-b]));
}

void solve(){
    vector<array<int, 2>> arr;
    int n, m; cin >> n >> m;
    for(int i = 0; i<m; ++i){
        int a, b; cin >> a >> b;
        arr.push_back({a, b});
    }
    reverse(arr.begin(), arr.end());
    vector<array<int, 2>> res;
    vector<int> bad;
    for(auto [a, b] : arr){
        int lo = 1, hi = n;
        while(lo<hi){
            int mid = lo+(hi-lo)/2;
            if(mid-tree.sum(mid)>=b) hi = mid;
            else lo = mid+1;
        }
        res.push_back({lo, a});
        tree.add(lo, 1);
        bad.push_back(lo);
    }
    map<int, int> bruh;
    for(auto [a, b] : res)
        bruh[a] = b;
    int tmp = 0;
    for(auto [a, b] : bruh){
        ++tmp;
        if(a>1 && !bruh.count(a-1)) res.push_back({a-1, a-tmp});
        if(a<n && !bruh.count(a+1)) res.push_back({a+1, a-tmp+1});
    }
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    int cnt = 0;
    for(int i = 1; i<(int)res.size(); ++i)
        if(res[i][1]<res[i-1][1]) cnt++;
    cout << comb(2*n-1-cnt, n) << '\n';
    for(auto x : bad)
        tree.add(x, -1);
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    fact[0] = 1;
    for(int i = 1; i<N; ++i)
        fact[i] = mul(fact[i-1], i);
    for(int i = 0; i<N; ++i)
        ifact[i] = inv(fact[i]);
    tree = FenwickTree(N/2);
    int t; cin >> t;
    while(t--) solve();
}