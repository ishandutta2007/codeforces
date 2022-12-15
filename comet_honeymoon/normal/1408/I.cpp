#include<bits/stdc++.h>
using namespace std;

const int p = 998244353;
const int maxn = 17, maxl = 66000;
struct Z {int x; Z(int x0 = 0) : x(x0) {}};
int inline check(int x) { return x >= p ? x - p : x; }
Z operator +(const Z a, const Z b) { return check(a.x + b.x); }
Z operator -(const Z a, const Z b) { return check(a.x - b.x + p); }
Z operator -(const Z a) {return check(p - a.x);}
Z operator *(const Z a, const Z b) { return 1LL * a.x * b.x % p; }
Z& operator +=(Z &a, const Z b) { return a = a + b; }
Z& operator -=(Z &a, const Z b) { return a = a - b; }
Z& operator *=(Z &a, const Z b) { return a = a * b; }
Z qpow(Z a, int k) {
	Z ans = 1;
	for (; k; a *= a, k >>= 1) if(k & 1) ans *= a;
	return ans;
}
Z fac[maxn], inv[maxn], ifac[maxn];
void init() {
    fac[0] = fac[1] = inv[1] = ifac[0] = ifac[1] = 1;
    for (int i = 2; i < maxn; i++)
        fac[i] = fac[i - 1] * i,
        inv[i] = -inv[p % i] * (p / i),
        ifac[i] = ifac[i - 1] * inv[i];
}

#define forj for(Z *jf = f + 1, *jg = i - 1; jg >= g; jf++, jg--)
void Ln(Z f[], Z g[], int n) {
	memset(g, 0, (n + 1) * sizeof(Z));
	g[0] = 0;
	for (Z *i = g + 1; i <= g + n; i++) {
		*i = (i - g) * f[i - g];
		forj *i -= (jg - g) * *jf * *jg;
		*i *= inv[i - g];
	}
}
void Exp(Z f[], Z g[], int n) {
	memset(g, 0, (n + 1) * sizeof(Z));
	g[0] = 1;
	for (Z *i = g + 1; i <= g + n; i++) {
		forj *i += (jf - f) * *jf * *jg;
		*i *= inv[i - g];
	}
}
#undef forj
void FWT(Z f[][maxn], int dim, int n) {
    for (int i = 0; i < dim; i++)
    for (int s = 0; s < 1 << dim; s++) if (!((s >> i) & 1))
    for (int j = 0; j <= n; j++) {
        Z a0 = f[s][j], a1 = f[s | (1 << i)][j];
        f[s][j] = a0 + a1, f[s | (1 << i)][j] = a0 - a1;
    }
}
void iFWT(Z f[][maxn], int dim, int n) {
    FWT(f, dim, n);
    Z invx = qpow(1 << dim, p - 2);
    for (int s = 0; s < 1 << dim; s++)
    for (int j = 0; j <= n; j++)
        f[s][j] *= invx;
}
int n, k, c;

map<vector<int>, int> hsh; 

namespace BASE {
int B[maxn];
vector<int> main_V;
int id[maxn];
void init() {
    for (int i = 0; i < c; i++) B[i] = 0, id[i] = -1;
    main_V.clear();
}
void insert(int x) {
    for (int i = 0; i < c; i++) if ((x >> i) & 1)
        if (!B[i]) {
            B[i] = x, id[i] = main_V.size(), main_V.push_back(x);
            break;
        }
        else x ^= B[i];
}
int rep(int x) {
    int ans = 0;
    for (int i = 0; i < c; i++) if ((x >> i) & 1)
        x ^= B[i], ans |= 1 << id[i];
    return ans;
}
};

Z ans[maxl][maxn], tans[maxl][maxn];

namespace SOLVER {
int rep_to_real[1 << 6];
Z f[1 << 6][maxn], g[1 << 6][maxn];
void solve(vector<int> a, int powk) {
    // printf("solve %d\n", a[0]);
    // if (a[0] != 7) return;
    BASE::init();
    for (int i = 0; i < k; i++) BASE::insert(a[i]);
    int dim = BASE::main_V.size();
    assert(dim <= 6);
    rep_to_real[0] = 0;
    for (int s = 0; s < 1 << dim; s++)
    for (int i = 0; i < dim; i++) if (!((s >> i) & 1))
        rep_to_real[s | (1 << i)] = rep_to_real[s] ^ BASE::main_V[i];
    
    memset(f, 0, sizeof(f));
    f[0][0] = 1;
    for (int i = 0; i < k; i++)
        f[BASE::rep(a[i])][i + 1] = ifac[i + 1];
    FWT(f, dim, k);
    for (int s = 0; s < 1 << dim; s++) Ln(f[s], g[s], k);
    iFWT(g, dim, k);
    for (int s = 0; s < 1 << dim; s++) 
    for (int i = 0; i <= k; i++)
        ans[rep_to_real[s]][i] += g[s][i] * powk;
}
};

int main() {
    init();
    int sum = 0;
    scanf("%d%d%d", &n, &k, &c);
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x); sum ^= x;
        vector<int> a;
        for (int j = 1; j <= k; j++)
            a.push_back(x ^ (x - j));
        hsh[a]++;
    }
    for (auto x : hsh) SOLVER::solve(x.first, x.second);

    FWT(ans, c, k);
    for (int s = 0; s < 1 << c; s++)
        Exp(ans[s], tans[s], k);
    iFWT(tans, c, k);
    
    Z qaq = qpow(qpow(n, k), p - 2);
    for (int s = 0; s < 1 << c; s++)
        printf("%d ", fac[k] * tans[sum ^ s][k] * qaq);
}