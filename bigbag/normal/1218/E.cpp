#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

namespace ntt {

const int max_lev = 15;
const int max_n = 1 << max_lev, mod = 998244353;

int mul(int x, int y) {
    return (1LL * x * y) % mod;
}

int power(int x, int y) {
    if (y == 0) {
        return 1;
    }
    if (y % 2 == 0) {
        return power(mul(x, x), y / 2);
    }
    return mul(x, power(x, y - 1));
}

int find_root() {
    for (int root = 2; ; ++root) {
        if (power(root, max_n) == 1) {
            int cur = 1;
            bool ok = true;
            for (int i = 1; i < max_n; ++i) {
                cur = mul(cur, root);
                if (cur == 1) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                return root;
            }
        }
    }
}

int pw[max_n], rpw[max_n], rev[max_n];

void init() {
    int root = find_root();
    int rroot = power(root, mod - 2);
    pw[0] = rpw[0] = 1;
    for (int i = 1; i < max_n; ++i) {
        pw[i] = mul(pw[i - 1], root);
        rpw[i] = mul(rpw[i - 1], rroot);
        rev[i] = (rev[i / 2] / 2) + ((i & 1) << (max_lev - 1));
    }
}

void fft(vector<int> &a, int pw[], int lg) {
    for (int i = 0; i < a.size(); ++i) {
        int r = (rev[i] >> (max_lev - lg)) & (a.size() - 1);
        if (i < r) {
            swap(a[i], a[r]);
        }
    }
    int pl = max_n / 2;
    for (int st = 1; st < a.size(); st *= 2) {
        for (int i = 0; i < a.size(); i += 2 * st) {
            int cur = 0;
            for (int j = i; j < i + st; ++j) {
                int y = mul(pw[cur], a[j + st]);
                a[j + st] = (a[j] + mod - y) % mod;
                a[j] = (a[j] + y) % mod;
                cur += pl;
            }
        }
        pl /= 2;
    }
}

const int max_triv = 36;

unsigned long long res[max_triv];

vector<int> triv_product(vector<int> &a, vector<int> &b) {
    for (int i = 0; i + 1 < a.size() + b.size(); ++i) {
        res[i] = 0;
    }
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < b.size(); ++j) {
            res[i + j] += 1LL * a[i] * b[j];
        }
    }
    vector<int> v(a.size() + b.size() - 1);
    for (int i = 0; i < v.size(); ++i) {
        v[i] = res[i] % mod;
    }
    return v;
}

vector<int> product(vector<int> &a, vector<int> &b) {
    if (a.size() + b.size() < max_triv) {
        return triv_product(a, b);
    }
    if (pw[0] == 0) {
        puts("NTT was not initialized");
        exit(228);
    }
    int sz = a.size() + b.size() - 1;
    int N = 1, lg = 0;
    while (N < sz) {
        N *= 2;
        ++lg;
    }
    while (a.size() < N) {
        a.push_back(0);
    }
    while (b.size() < N) {
        b.push_back(0);
    }
    fft(a, pw, lg);
    fft(b, pw, lg);
    for (int i = 0; i < a.size(); ++i) {
        a[i] = mul(a[i], b[i]);
    }
    fft(a, rpw, lg);
    int rn = power(N, mod - 2);
    vector<int> ans(sz);
    for (int i = 0; i < sz; ++i) {
        ans[i] = mul(a[i], rn);
    }
    return ans;
}

}

const int max_n = 20222, mod = 998244353;

int n, k, q, A[max_n], a[max_n];
int dp[max_n];

vector<int> solve(int l, int r) {
    if (l == r) {
        return {1, a[r]};
    }
    int mid = (l + r) / 2;
    vector<int> a = solve(l, mid);
    vector<int> b = solve(mid + 1, r);
    return ntt::product(a, b);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ntt::init();
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
    }
    scanf("%d", &q);
    while (q--) {
        copy(A, A + n, a);
        int tp, x;
        scanf("%d%d", &tp, &x);
        if (tp == 1) {
            int pos, d;
            scanf("%d%d", &pos, &d);
            --pos;
            a[pos] = d;
        } else {
            int l, r, d;
            scanf("%d%d%d", &l, &r, &d);
            --l;
            for (int i = l; i < r; ++i) {
                a[i] += d;
            }
        }
        for (int i = 0; i < n; ++i) {
            a[i] = ((x - a[i]) % mod + mod) % mod;
        }
        vector<int> ans = solve(0, n - 1);
        printf("%d\n", ans[k]);
    }
    return 0;
}