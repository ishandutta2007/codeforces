#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int MOD = 998244353; // (1 << 23) * 19 + 1;
int root;
int root_i;
int root_pw = 1<<23;
int itwo = 499122177;
int fac[600600];
int ifac[600600];
int iv[600600];
int tpow[600600];

void setup() {
    int r = 3;
    int ri = 332748118;
    root = 1;
    root_i = 1;
    for (int i=0; i<119; ++i) {
        root = (ll) root*r%MOD;
        root_i = (ll) root_i*ri%MOD;
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
                w = (ll) w*w % MOD;
            }
            for (int i=0; i<n; i+=j) {
                int b = 1;
                for (int k=i; k<i+j/2; k++) {
                    int a1 = v[k], a2 = (ll) b*v[k+j/2]%MOD;
                    v[k]=(a1+a2)%MOD;
                    v[k+j/2] = (a1-a2+MOD)%MOD;
                    b=(ll)b*w%MOD;
                }
            }
        }
        if (dir == -1) {
            int w = 1;
            for (int z = 1; z < n; z<<=1) {
                w = ((ll) w*itwo)%MOD;
            }
            for (int i=0; i<n; ++i) {
                v[i] = (ll) v[i]*w%MOD;
            }
        }
    }
    vector<int> conv(vector<int> a, vector<int> b) {
        int nn = a.size()+b.size()-2;
        int mm = a.size()+b.size()-1;
        nn = 1<<(32-__builtin_clz(nn));
        a.resize(nn, 0);
        b.resize(nn, 0);
        rfft(a, 1);
        rfft(b, 1);
        for(int i=0;i<nn;++i) a[i] = (ll) a[i]*b[i]%MOD;
        rfft(a, -1);
        a.resize(mm);
        return a;
    }
};

int n, k, qq;
vector<int> a, b, q, ans;

inline ll choose(int n, int k) {
    return (ll) ((ll) fac[n]*ifac[k]%MOD)*ifac[n-k]%MOD;
}

void solve(int singles, int doubles, int h) {
    vector<int> a(singles+1, 0), b(doubles*2+1, 0);
    for (int i=0; i<=singles; ++i) {
        a[i] = choose(singles, i)*tpow[i]%MOD;
    }
    for (int i=0; i<=doubles*2; ++i) {
        b[i] = choose(doubles*2, i);
    }
    vector<int> amts = ntt::conv(a, b);
    for (int i=0; i<qq; ++i) {
        int x = q[i];
        int y = (x-2*h-2)/2;
        if (y < 0 || y >= amts.size()) continue;
        ans[i] = (amts[y]+ans[i])%MOD;
    }
}

inline char get() {
    static char buf[100000], *S=buf, *T=buf;
    if (S == T) {
        T = (S=buf) + fread(buf, 1, 100000, stdin);
        if (S==T) return EOF;
    }
    return *S++;
}

template<typename T>
void read(T& x) {
    static char c; x = 0;
    for(c=get();c <'0' || c >'9'; c=get());
    for(;c>='0' && c<='9'; c=get()) x = x*10 + c-'0';
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    setup();
    solve(42, 31, 0);
    read(n); read(k);
    a = vector<int>(n);
    b = vector<int>(k);
    map<int, int> mp;
    for (auto& x : a) {
        read(x);
        ++mp[x];
    }
    for (auto& x : b) {
        read(x);
    }
    read(qq);
    q = vector<int>(qq);
    ans = vector<int>(qq, 0);
    for (auto& x : q) {
        read(x);
    } 

    ++mp[1e9];

    sort(b.begin(), b.end());
    int j = 0;

    int singles = 0, doubles = 0;

    for (auto& p : mp) {
        if (j == b.size()) break;
        while (j < b.size() && p.first >= b[j]) {
            ////cerr << " for " << j << " " << singles << " singles, " << doubles << " doubles" << endl;
            solve(singles, doubles, b[j]);
            ++j;
        }
        (p.second == 1 ? singles : doubles)++;
    }
    assert (j == b.size());
    for (auto& x : ans) {
        cout << x%MOD << "\n";
    }

    return 0;
}