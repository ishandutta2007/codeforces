#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

const int MAXN = 200100;
const int MOD = 998244353;
int fact[MAXN];
int inv[MAXN];

template <typename T>
class SegTree {
public:
    vector <T> tree;

    SegTree(int size) {
        tree.resize(size, 0);
    }

    T func(T a, T b) {
        return a + b; // Segment tree for the sum
        // return min(a, b); // Segment tree for the minimum
    }

    void update(int node, int start, int end, int pos) {
        if(start == end) {
            tree[node] += 1; // Assign value here.
        } else {
            int mid = (start + end)/2;
            if(pos <= mid) {
                update(node*2, start, mid, pos);
            } else {
                update(node*2 + 1, mid + 1, end, pos);
            }
            tree[node] = func(tree[node*2], tree[node*2 + 1]);
        }
    }

    T query(int node, int start, int end, int l, int r) {
        if(l > r) {
            return 0; // Return appropriate value, for example INF for minimum.
        }
        if(l == start && r == end) {
            return tree[node];
        }
        int mid = (start + end)/2;
        return func(query(node*2, start, mid, l, min(mid, r)), query(node*2 + 1, mid + 1, end, max(l, mid + 1), r));
    }
};

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }   
    return res % MOD;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector <int> a(n), b(m);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }
    int f = 0; // Find first point of difference.
    SegTree<int> st(4*MAXN);
    {
        vector <int> cnt(MAXN, 0);
        for(int i = 0; i < n; i++) {
            cnt[a[i]]++;
        }
        for(int i = 0; i < m; i++) {
            if(cnt[b[i]] > 0) {
                cnt[b[i]]--;
                f++;
            } else {
                break;
            }
        }
        for(int i = 0; i < MAXN; i++) {
            for(int j = 0; j < cnt[i]; j++) {
                st.update(1, 0, MAXN - 1, i);
            }
        }
    }
    fact[0] = inv[0] = fact[1] = inv[1] = 1;
    for(int i = 2; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        inv[i] = binpow(fact[i], MOD - 2);
    }
    int upper = max(0ll, n - f);
    int lower = 1;
    int cnt;
    for(int i = 0; i < MAXN; i++) {
        int x = st.query(1, 0, MAXN - 1, i, i);
        lower = (lower * fact[x]) % MOD;
    }
    vector<int> ans(f + 1);
    {
        // ans[f], many cases.
        if(f == m && f == n) {
            ans[f] = 0;
        } 
        else if(f == n && f != m) {
            ans[f] = 1;
        } 
        else if(f == m && f != n) {
            ans[f] = 0;
        } else {
            cnt = st.query(1, 0, MAXN - 1, 0, b[f] - 1);
            ans[f] = fact[upper] * binpow(lower, MOD - 2) % MOD * cnt % MOD * binpow(upper, MOD - 2) % MOD;
        }
    }
    for(int i = f - 1; i >= 0; i--) {
        upper++;
        st.update(1, 0, MAXN - 1, b[i]);
        // cout << st.query(1, 0, MAXN - 1, 0, MAXN - 1) << " ";
        lower = (lower * st.query(1, 0, MAXN - 1, b[i], b[i])) % MOD;
        cnt = st.query(1, 0, MAXN - 1, 0, b[i] - 1);
        // cout << i << " " << upper << " " << lower << " " << cnt << endl;
        ans[i] = fact[upper] * binpow(lower, MOD - 2) % MOD * cnt % MOD * binpow(upper, MOD - 2) % MOD;
    }
    int x = 0;
    for(int i = 0; i <= f; i++) {
        // cerr << ans[i] << " ";
        x = (x + ans[i]) % MOD;
    }
    cout << x;
    return 0;
}