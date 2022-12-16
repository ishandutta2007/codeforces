#include <cassert>
#include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <queue>
#include <list>
#include <deque>
#include <stack>
#include <random>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

const int NMAX = 200200;

struct segtree {
    vector<int> t;
    int n, h;
    segtree() {}
    segtree(int sz) { 
        h = 32 - __builtin_clz(sz);
        n = 1<<h;
        t = vector<int>(n<<1, 0);
    }
    int& operator[] (const int& i) { return t[i+n]; }
    void build() {
        for(int i=n-1; i>0; --i) {
            t[i] = max(t[i<<1], t[i<<1|1]);
        }
    }
    int query(int l, int r) {
        int ans = 0;
        for(l+=n, r+=n; l<r; l/=2, r/=2) {
            if(l%2) ans = max(ans, t[l++]);
            if(r%2) ans = max(ans, t[--r]);
        }
        return ans;
    }
};

int l[NMAX], r[NMAX], p[NMAX], inv[NMAX];
ll ans = 0;
int n;

segtree st;

void solve(int l, int r) {
    if(r-l < 3) return;
    int m = inv[st.query(l, r)];
    solve(l, m);
    solve(m+1, r);
    if(m-l > r-m-1) {
        for(int i=m+1; i<r; ++i) {
            if(p[i] > p[m]) continue;
            if(inv[p[m]-p[i]] < m && inv[p[m]-p[i]] >= l) ++ans;
        }
    } else {
        for(int i=l; i<m; ++i) {
            if(p[i] > p[m]) continue;
            if(inv[p[m]-p[i]] < r && inv[p[m]-p[i]] > m) ++ans;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    st = segtree(n+1);
    for(int i=1; i<=n; ++i) {
        cin >> p[i];
        st[i] = p[i];
        inv[p[i]] = i;
    }
    st.build();
    solve(1, n+1);
    cout << ans << endl;
    return 0;
}