#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

typedef vector<vector<ll>> res;

const int N = 11*100100;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;

int ncnt = 1;
int nxt[N][4];
res f[64];

ll n;
string s;
int dep;

res get_res(ll init = 0) {
    return res(4, vector<ll>(4, init));
}

inline int ord(char c) {
    return c - 'A';
}

void insert(const string &t, int start, int finish) {
    int u=1;
    for (int i=start; i<finish; ++i) {
        if (!nxt[u][ord(t[i])]) {
            nxt[u][ord(t[i])] = ++ncnt;
        }
        u = nxt[u][ord(t[i])];
    }
}

void dfs(int u, int d, int h, int begin, int cur) {
    if (u == 0) {
        f[0][begin][cur] = min(f[0][begin][cur], (ll) d-1);
        return;
    }
    if (d == h) return;
    for (int i=0; i<4; ++i) {
        dfs(nxt[u][i], d+1, h, begin, i);
    }
}

res res_mul(const res &a, const res &b) {
    res ans = get_res(INFLL);
    //cerr << " : " << a.size() << " " << b.size() << endl;
    for (int i=0; i<4; ++i) {
        for (int j=0; j<4; ++j) {
            for (int k=0; k<4; ++k) {
                ans[i][j] = min(ans[i][j], a[i][k]+b[k][j]);
            }
        }
    }
    return ans;
}

ll smallest(const res &x) {
    ll ans = INFLL;
    for (int i=0; i<4; ++i) {
        for (int j=0; j<4; ++j) {
            ans = min(ans, x[i][j]);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    cin >> s;
    dep = (33-__builtin_clz(s.size()+1))/2+2;

    for (int i=0; i<s.size(); ++i) {
        insert(s, i, min(i+dep, (int) s.size()));
    }

    for (int i=0; i<64; ++i) {
        f[i] = get_res(INFLL);
    }

    for (int i=0; i<4; ++i) {
        dfs(nxt[1][i], 1, dep, i, i);
    }

    for (int l=0; l<63; ++l) {
        f[l+1] = res_mul(f[l], f[l]);
    }

    ll amt = 0;
    res cur = get_res();
    for (int i=62; i>=0; --i) {
        res rm = res_mul(cur, f[i]);
        if (smallest(rm) < n) {
            amt += (1LL<<i);
            cur = rm;
        }
    }
    assert(smallest(cur) < n);
    cur = res_mul(cur, f[0]);
    ++ amt;
    assert(smallest(cur) >= n);
    cout << amt << "\n";
    
    return 0;
}