#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const int SMALL_SZ = 150;
const int MOD = 998244353; // (1 << 23) * 19 + 1;
int root;
int root_i;
int root_pw = 1<<23;
int itwo = 499122177;
int fac[600600];
int ifac[600600];
int iv[600600];
int tpow[600600];


static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
#if !defined(_WIN32) || defined(_WIN64)
    return x % m;
#endif
    // Optimized mod for Codeforces 32-bit machines.
    // x must be less than 2^32 * m for this to work, so that x / m fits in a 32-bit integer.
    unsigned x_high = x >> 32, x_low = (unsigned) x;
    unsigned quot, rem;
    asm("divl %4\n"
        : "=a" (quot), "=d" (rem)
        : "d" (x_high), "a" (x_low), "r" (m));
    return rem;
}

void setup() {
    int r = 3;
    int ri = 332748118;
    root = 1;
    root_i = 1;
    for (int i=0; i<119; ++i) {
        root = fast_mod((ll) root*r);
        root_i = fast_mod((ll) root_i*ri);
    }

    iv[0] = iv[1] = 1;
    for (int i=2; i<600600; ++i) {
        iv[i] = (MOD - (ll) (MOD/i) * iv[MOD%i] % MOD) % MOD;
    }
    
    fac[0] = 1;
    fac[1] = 1;
    ifac[0] = 1;
    ifac[1] = 1;
    tpow[0] = 1;
    tpow[1] = 2;
    for (ll i=2; i<600600; ++i) {
        fac[i] = (ll) fac[i-1]*i%MOD;
        ifac[i] = (ll) ifac[i-1]*iv[i]%MOD;
        tpow[i] = tpow[i-1]*2%MOD;
    }
}

namespace ntt {
    void rfft(vector<int> &v, int dir) {
        int n = v.size();
        for (int i=1,j=0; i<n; ++i) {
            int z = n/2;
            for (;j>=z; z/=2) j -= z;
            j += z;
            if (i<j) swap(v[i], v[j]);
        }
        for (int j=2; j<=n; j *= 2) {
            int w = dir == 1 ? root : root_i;
            for (ll i = j; i < root_pw; i *= 2) {
                w = fast_mod((ll) w*w);
            }
            for (int i=0; i<n; i+=j) {
                int b = 1;
                for (int k=i; k<i+j/2; k++) {
                    int a1 = v[k], a2 = fast_mod((ll) b*v[k+j/2]);
                    v[k]=fast_mod(a1+a2);
                    v[k+j/2] = fast_mod(a1-a2+MOD);
                    b=fast_mod((ll)b*w);
                }
            }
        }
        if (dir == -1) {
            int w = 1;
            for (int z = 1; z < n; z<<=1) {
                w = fast_mod((ll) w*itwo);
            }
            for (int i=0; i<n; ++i) {
                v[i] = fast_mod((ll) v[i]*w);
            }
        }
    }
    vector<int> conv_small(const vector<int>& a, const vector<int>& b) {
        if (a.size() < b.size()) return conv_small(b, a);
        vector<int> ans(a.size()+b.size()-1, 0);
        for (int i=0; i<a.size(); ++i) {
            for (int j=0; j<b.size(); ++j) {
                ans[i+j] = fast_mod(ans[i+j]+(ll)a[i]*b[j]);
            }
        }
        return ans;
    }

    vector<int> conv(vector<int> a, vector<int> b) {
        if (a.size() < SMALL_SZ || b.size() < SMALL_SZ) {
            return conv_small(a, b);
        }
        int nn = a.size()+b.size()-2;
        int mm = a.size()+b.size()-1;
        nn = 1<<(32-__builtin_clz(nn));
        a.resize(nn, 0);
        b.resize(nn, 0);
        rfft(a, 1);
        rfft(b, 1);
        for(int i=0;i<nn;++i) a[i] = fast_mod((ll) a[i]*b[i]);
        rfft(a, -1);
        a.resize(mm);
        return a;
    }
};

map<int, int> mp;
int n;

vector<int> merge(const vector<vector<int>> &polys, int l, int r) {
    assert(l < r);
    if (r-l == 1) return polys[l];
    pii best(1e9, l+1);
    int h = 0, x = 0;
    for (int i=l; i<r; ++i) {
        h += polys[i].size();
    }
    for (int i=l; i<r-1; ++i) {
        h -= polys[i].size();
        x += polys[i].size();
        best = min(best, pii(max(x, h), i+1));
    }
    int m = best.second;
    vector<int> a = merge(polys, l, m);
    vector<int> b = merge(polys, m, r);
    return ntt::conv(a, b);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    setup();
    cin >> n;
    for (int i=0; i<n; ++i) {
        int p;
        cin >> p;
        mp[p]++;
    }
    vector<vector<int>> polys;
    for (auto& p : mp) {
        polys.push_back(vector<int>(p.second+1, 1));
    }
    auto g = merge(polys, 0, polys.size());
    cerr << g.size() << endl;
    cout << g[n/2] << endl;
    return 0;
}