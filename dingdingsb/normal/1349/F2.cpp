#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128_t;
using ull = unsigned long long;
using ld = long double;
using vi = vector<int>;
using pii = pair<int, int>;

#define _fore(i, a) for (ll i = head[(a)]; i; i = edge[i].nxt)
#define _dbg(...) 1
#define dbg(x) 1

ll rr() {
    ll s = 0, w = 1;
    char c = getchar();
    while (!isdigit(c))
        w = 1 - 2 * (c == '-'), c = getchar();
    while (isdigit(c))
        s = s * 10 + c - '0', c = getchar();
    return s * w;
}

const int P = 998244353;
int qpow(ll a, ll b = P - 2, ll m = P) {
    ll ret = m != 1;
    for (; b; b >>= 1) {
        if (b & 1)
            ret = ret * a % m;
        a = a * a % m;
    }
    return ret;
}

template <typename T> T tpow(T a, ll b) {
    T ret;
    for (; b; b >>= 1) {
        if (b & 1)
            ret = ret * a;
        a = a * a;
    }
    return ret;
}

inline int mo(int n) {
    return n >= P ? n - P : n;
}

inline int &momo(int &n) {
    return n >= P ? n -= P : n;
}

struct m32 {
    int v = 0;
    m32(int _v = 0) {
        v = _v;
    }
    m32 &operator=(const int &m) {
        v = m;
        return *this;
    }
    m32 &operator+=(const m32 &m) {
        v = (v += m.v) >= P ? v - P : v;
        return *this;
    }
    m32 &operator-=(const m32 &m) {
        v = (v -= m.v) < 0 ? v + P : v;
        return *this;
    }
    m32 operator-() const {
        return v == 0 ? 0 : P - v;
    }
    m32 &operator*=(const m32 &m) {
        v = ll(v) * m.v % P;
        return *this;
    }
    m32 operator+(const m32 &m) const {
        return m32(*this) += m;
    }
    m32 operator-(const m32 &m) const {
        return m32(*this) -= m;
    }
    m32 operator*(const m32 &m) const {
        return m32(*this) *= m;
    }
    m32 inv() const {
        return qpow(v);
    }
    m32 pow(int n) const {
        return qpow(v, n, P);
    }
    m32 sqrt() const {
#ifdef ACM_MATH_CIPOLLA_H
        return Cipolla(v, P).first;
#else
        return 1;
#endif
    }
};

inline int get_lim(int n) {
    int m = 1;
    while (m < n)
        m *= 2;
    return m;
}

struct Poly : std::vector<m32> {
    using vector::vector;
    bool isNTT = false;
    Poly(Poly::const_iterator pi, int len) : Poly(pi, pi + len) {
    }
    Poly rev() const {
        return Poly(rbegin(), rend());
    }
    int deg() const {
        return size();
    }
    Poly cut(int m) const {
        return Poly(begin(), begin() + min(deg(), m));
    }
    Poly &resize(int m) {
        vector::resize(m);
        return *this;
    }
    Poly &fillZeroL(int t) {
        fill_n(begin(), t / 2, 0);
        return *this;
    }
    Poly &fillZeroH(int t) {
        fill_n(begin() + t / 2, t / 2, 0);
        return *this;
    }
    friend Poly operator+(Poly f, Poly g);
    friend Poly operator-(Poly f, Poly g);
    friend Poly operator*(Poly f, Poly g);
    Poly &ntt(int m);
    Poly &nttD(int m);
    Poly &intt(int m);
    Poly &invD(Poly f2, Poly nx, int t);
    Poly inv() const;
    Poly div(Poly g) const;
    Poly deriv() const;
    Poly integr() const;
    Poly ln() const;
    Poly exp() const;
    Poly sqrt() const;
    Poly pow(int k) const;
    Poly mod() const;
};

Poly w, Inv;

void pre_w(int n, int w0 = 3) {
    static int lim = (w = {1, 1}, 2);
    n = get_lim(n);
    if (n <= lim)
        return;
    w.resize(n);
    for (int l = lim; l < n; l *= 2) {
        m32 p = m32(w0).pow((P - 1) / l / 2);
        for (int i = 0; i < l; i += 2) {
            w[(l + i)] = w[(l + i) / 2];
            w[l + i + 1] = w[l + i] * p;
        }
    }
    lim = n;
}

void pre_inv(int n) {
    static int LIM = (Inv = {1, 1}, 2);
    if (n <= LIM)
        return;
    Inv.resize(n);
    for (int i = LIM; i < n; i++) {
        Inv[i] = Inv[P % i] * (P - P / i);
    }
    LIM = n;
}

static int ntt_size = 0;

void ntt(Poly::iterator f, int deg) {
    pre_w(deg);
    ntt_size += deg;
    for (int l = deg >> 1; l; l >>= 1)
        for (auto fi = f; fi - f < deg; fi += l * 2)
            for (int j = 0; j < l; j++) {
                auto x = fi[j] + fi[j + l];
                fi[j + l] = w[j + l] * (fi[j] - fi[j + l]);
                fi[j] = x;
            }
}

void intt(Poly::iterator f, int deg) {
    ntt_size += deg;
    for (int l = 1; l < deg; l <<= 1)
        for (auto fi = f; fi - f < deg; fi += l * 2)
            for (int j = 0; j < l; j++) {
                auto x = fi[j], y = fi[j + l] * w[j + l];
                fi[j] = x + y, fi[j + l] = x - y;
            }
    const auto deg_inv = P - (P - 1) / deg;
    for (int i = 0; i < deg; i++)
        f[i] *= deg_inv;
    std::reverse(f + 1, f + deg);
}

void nttD(Poly::iterator f, int n) {
    std::copy_n(f, n, f + n);
    intt(f + n, n);
    for (int i = n; i < n * 2; i++)
        f[i] *= w[i];
    ntt(f + n, n);
}

Poly &Poly::ntt(int n) {
    if (!isNTT) {
        resize(n);
        ::ntt(begin(), n);
        isNTT = true;
    }
    return *this;
}

Poly &Poly::intt(int m) {
    ::intt(begin(), m);
    isNTT = false;
    return *this;
}

Poly &Poly::nttD(int n) {
    resize(n * 2);
    ::nttD(begin(), n);
    return *this;
}

Poly &mul(Poly &f, Poly &g, int t) {
    f.ntt(t), g.ntt(t);
    for (int i = 0; i < t; i++)
        f[i] *= g[i];
    return f.intt(t);
}

Poly operator*(Poly f, Poly g) {
    if (f.deg() < g.deg())
        swap(f, g);
    int t = f.deg() + g.deg() - 1;
    return mul(f, g, get_lim(t)).cut(t);
}

Poly operator+(Poly f, Poly g) {
    if (f.deg() < g.deg())
        std::swap(f, g);
    for (int i = 0; i < g.deg(); i++)
        f[i] += g[i];
    return f;
}

Poly operator-(Poly f, Poly g) {
    for (auto &i : g)
        i = -i;
    return std::move(f) + g;
}

m32 mulAt(const Poly f, const Poly g, int u) {
    int n = f.deg() - 1, m = g.deg() - 1;
    m32 ans = 0;
    for (int i = std::max(0, u - m); i <= std::min(u, n); i++)
        ans += f[i] * g[u - i];
    return ans;
}

struct PolySemi {
    using iter = Poly::iterator;
    const int B = 16;
    int n, m;
    Poly F, v1, v2, ret;
    std::function<void(int, m32 &)> relax;

    void run(int l, int r, iter g, iter h) {
        if (r - l <= 64) {
            for (int i = l; i < r; ++i) {
                relax(i, ret[i]);
                for (int j = i + 1; j < r; ++j)
                    ret[j] += ret[i] * F[j - i];
            }
            return;
        }
        int len = (r - l) / B, k = 2 * len;
        iter tg[B], th[B];
        for (int i = 0; i < B - 1; i++)
            tg[i] = g + i * k, th[i] = h + i * k;
        if (l == 0) {
            for (int i = 0; i < B - 1; i++) {
                if ((i + 1) * len >= n)
                    break;
                copy_n(F.begin() + i * len, k, th[i]);
                ntt(th[i], k);
            }
        }
        for (int i = 0; i < B; i++) {
            auto u = l + i * len;
            if (u >= n)
                break;
            Poly s(k);
            for (int j = 0; j < i; j++)
                for (int t = 0; t < k; t++)
                    s[t] += tg[j][t] * th[i - j - 1][t];
            s.intt(k);
            for (int t = 0; t < len; t++)
                ret[t + u] += s[t + len];
            run(u, u + len, g + k * B, h + k * B);
            if (i != B - 1) {
                copy_n(ret.begin() + u, len, tg[i]);
                ntt(tg[i], k);
            }
        }
        fill_n(g, k * B, 0);
    }

    PolySemi(Poly f) : F(f) {
        n = F.size();
        m = get_lim(n);
        F.resize(m), ret.resize(m);
        v1.resize(m * 4), v2.resize(m * 4);
        ret[0] = 1;
    }

    Poly exp() {
        pre_inv(m);
        for (int i = 0; i < n; i++)
            F[i] *= i;
        relax = [&](int i, m32 &ri) {
            ret[i] = i == 0 ? 1 : ret[i] * Inv[i];
        };
        run(0, m, v1.begin(), v2.begin());
        return ret.cut(n);
    }

    Poly inv() {
        m32 iv = F[0].inv();
        relax = [&](int i, m32 &ri) {
            ri = i == 0 ? iv : -ri * iv;
        };
        run(0, m, v1.begin(), v2.begin());
        return ret.cut(n);
    }

    Poly quo(Poly h) {
        h.resize(m);
        m32 iv = F[0].inv();
        relax = [&](int i, m32 &ri) {
            ret[i] = i == 0 ? h[0] * iv : (h[i] - ret[i]) * iv;
        };
        run(0, m, v1.begin(), v2.begin());
        return ret.cut(n);
    }

    Poly sqrt() {
        Poly h = F;
        dbg(h);
        m32 iv = F[0].inv(), iv2 = (P + 1) / 2;
        relax = [&](int i, m32 &ri) {
            dbg(F), dbg(ret);
            F[i] = ret[i] = i == 0 ? F[0].sqrt() : (F[i] - ret[i] - h[i] * h[0]) * iv * iv2;
            dbg(F[i]);
        };
        run(0, m, v1.begin(), v2.begin());
        return ret.cut(n);
    }
};

Poly Poly::inv() const {
    return PolySemi(*this).inv();
}

Poly Poly::div(Poly g) const {
    return PolySemi(g.resize(deg())).quo(*this);
}

Poly Poly::ln() const {
    Poly f = *this;
    pre_inv(deg());
    for (int i = 0; i < deg(); i++)
        f[i] *= i;
    f = f.div(*this);
    for (int i = 0; i < deg(); i++)
        f[i] *= Inv[i];
    return f;
}

Poly Poly::exp() const {
    return PolySemi(*this).exp();
}

Poly Poly::pow(int k) const {
    Poly f = ln();
    for (int i = 0; i < size(); i++)
        f[i] *= k;
    return f.exp();
}
const int N=2e5+10;
int n;
m32 fac[N],ifac[N];
m32 f[N]; 
signed main(){
	fac[0]=1;for(int i=1;i<N;i++)fac[i]=fac[i-1]*i;
	ifac[N-1]=fac[N-1].inv();for(int i=N-1;i;i--)ifac[i-1]=ifac[i]*i;
	scanf("%d",&n);
//n=100000;
	Poly F,P,H;
	F.resize(n+5);
	P.resize(n+5);
	
	for(int i=2;i<(int)F.size();i++)F[i-2]=m32(0)-ifac[i];
	F=F.inv();
	//F.print();
	for(int i=1;i<(int)P.size();i++)if(i&1)P[i-1]=m32(i).inv();else P[i-1]=m32(0)-m32(i).inv();
	//P.print();
	H=P.inv();
	//H.print();
	Poly KK;KK.resize(n+5);
	for(int i=1;i<n+5;i++)KK[i-1]=m32(0)-H[i];
	KK=KK.inv();
	//KK.print();
	Poly tmp=H.pow(n+1);
	Poly tmp1=tmp*KK;
	for(int i=1;i<n+5;i++)H[i-1]=H[i]*i;
	Poly tmp2=H*tmp;
	tmp2.resize(n+5);
	tmp2=tmp2*KK;
	tmp2.resize(n+5);
	tmp2=tmp2*KK;
	for(int j=1;j<=n+1;j++){
		int m=n-j+1;
		f[j]=F[j+1]-m32(n+1).inv()*(tmp2[n-m+2]+(tmp1[n-m+2]*m));
		//printf("%d ",f[j]);
	}
	//printf("\n");
	Poly a,b;a.resize(n);b.resize(n);
	for(int j=0;j<n;j++)a[j]=fac[j]*f[j];
	for(int j=0;j<n;j++)if(j&1)b[j]=-ifac[j];else b[j]=ifac[j];
	//a.print();b.print();
	a=a.rev();a=a*b;a.resize(n);a=a.rev();
	//return 0;
	{
		//k=0
		m32 tmp=0;
		for(int i=1;i<=n;i++)
			tmp+=fac[n]*ifac[i];
		printf("%d ",tmp.v);
	}
	for(int k=1;k<n;k++){
		m32 ans=fac[n]*ifac[k];
		ans*=a[k];
		printf("%d ",ans.v);
	}
	printf("\n");
}