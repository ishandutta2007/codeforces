#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
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

struct FenwickTree {
    vector<int> bit;
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
} tree(N);

int n, m, cnt[N], arr[N];
int numer = 1, denom = 1, ans;

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0; i<n; ++i){
        int a; cin >> a;
        ++cnt[a]; tree.add(a, 1);
    }
    for(int i = 0; i<m; ++i)
        cin >> arr[i];
    for(int i = 1; i<=n; ++i)
        grow(numer, i);
    for(int i = 1; i<N; ++i)
        for(int j = 1; j<=cnt[i]; ++j)
            grow(denom, j);
    for(int i = 0; i<m; ++i){
        grow(numer, inv(n-i));
        inc(ans, mul(tree.sum(1, arr[i]-1), mul(numer, inv(denom))));
        if(tree.sum(1, N)==0) inc(ans, 1);
        if(!cnt[arr[i]]) break;
        grow(denom, inv(cnt[arr[i]])); --cnt[arr[i]];
        tree.add(arr[i], -1);
    }
    cout << ans << '\n';
}