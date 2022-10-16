#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;

using F = double; const int CUTOFF = 150, DIG = 1; const F PI = acos(-1);

template <class T> pair<T, T> operator + (const pair<T, T> &a, const pair<T, T> &b) {
    return make_pair(a.first + b.first, a.second + b.second);
}
template <class T> pair<T, T> operator - (const pair<T, T> &a, const pair<T, T> &b) {
    return make_pair(a.first - b.first, a.second - b.second);
}
template <class T> pair<T, T> operator * (const pair<T, T> &a, const pair<T, T> &b) {
    return make_pair(a.first * b.first - a.second * b.second, a.first * b.second + a.second * b.first);
}
template <class T> pair<T, T> conj(const pair<T, T> &a) {
    return make_pair(a.first, -a.second);
}

vector<int> ord; vector<pair<F, F>> roots;

void computeRoots(int N) {
    if (int(roots.size()) >= N) return;
    if (roots.empty()) roots = {{0, 0}, {1, 0}};
    int len = __builtin_ctz(int(roots.size())); roots.resize(N);
    for (; (1 << len) < N; len++) {
        double mnAngle = 2 * PI / (1 << (len + 1));
        for (int i = 0; i < (1 << (len - 1)); i++) {
            int ind = (1 << (len - 1)) + i; double ang = mnAngle * (2 * i + 1);
            roots[2 * ind] = roots[ind]; roots[2 * ind + 1] = make_pair(cos(ang), sin(ang));
        }
    }
}

void reorder(vector<pair<F, F>> &a) {
    int N = int(a.size());
    if (int(ord.size()) != N) {
        ord.assign(N, 0); int len = __builtin_ctz(N);
        for (int i = 0; i < N; i++) ord[i] = (ord[i >> 1] >> 1) + ((i & 1) << (len - 1));
    }
    for (int i = 0; i < N; i++) if (i < ord[i]) swap(a[i], a[ord[i]]);
}

void fft(vector<pair<F, F>> &a) {
    int N = int(a.size()); computeRoots(N); reorder(a);
    for (int len = 1; len < N; len <<= 1) for (int i = 0; i < N; i += len << 1) for (int j = 0; j < len; j++) {
                pair<F, F> u = a[i + j], v = a[len + i + j] * roots[len + j]; a[i + j] = u + v; a[len + i + j] = u - v;
            }
}

// Multiplies 2 big integers
template <class T> void multiplyInteger(const vector<T> &a, const vector<T> &b, vector<T> &res) {
    static_assert(is_integral<T>::value, "T must be an integral type"); static T BASE = 10;//pow2(T(10), T(DIG));
    if (max(int(a.size()), int(b.size())) <= CUTOFF) {
        vector<T> c(int(a.size()) + int(b.size()), 0); T carry = 0;
        for (int i = 0; i < int(a.size()); i++) for (int j = 0; j < int(b.size()); j++) c[i + j] += a[i] * b[j];
        res.resize(int(a.size()) + int(b.size()), 0);
        for (int i = 0; i < int(c.size()); i++) { res[i] = c[i] + carry; carry = res[i] / BASE; res[i] %= BASE; }
        while (int(res.size()) > 1 && res.back() == 0) res.pop_back();
        return;
    }
    int N = int(a.size()) + int(b.size());
    while (N & (N - 1)) N++;
    vector<pair<F, F>> f(N, make_pair(0, 0));
    for (int i = 0; i < int(a.size()); i++) f[i].first = a[i];
    for (int i = 0; i < int(b.size()); i++) f[i].second = b[i];
    fft(f); pair<F, F> r(0, -0.25 / N);
    for (int i = 0; i <= N / 2; i++) {
        int j = (N - i) & (N - 1);
        pair<F, F> prod = (f[j] * f[j] - conj(f[i] * f[i])) * r; f[i] = prod; f[j] = conj(prod);
    }
    fft(f); res.resize(N); T carry = 0;
    for (int i = 0; i < N; i++) { res[i] = (T) (f[i].first + 0.5) + carry; carry = res[i] / BASE; res[i] %= BASE; }
    while (int(res.size()) > 1 && res.back() == 0) res.pop_back();
}

// Multiplies 2 polynomials
template <class T> void multiplyPolynomial(const vector<T> &a, const vector<T> &b, vector<T> &res) {
    if (max(int(a.size()), int(b.size())) <= CUTOFF) {
        vector<T> c(int(a.size()) + int(b.size()) - 1, 0);
        for (int i = 0; i < int(a.size()); i++) for (int j = 0; j < int(b.size()); j++){
                c[i + j] += (a[i] * b[j]);
            }
        res.resize(int(a.size()) + int(b.size()), 0); copy(c.begin(), c.end(), res.begin());
        while (int(res.size()) > 1 && res.back() == 0) res.pop_back();
        return;
    }
    int N = int(a.size()) + int(b.size()) - 1;
    while (N & (N - 1)) N++;
    vector<pair<F, F>> f(N, make_pair(0, 0));
    for (int i = 0; i < int(a.size()); i++) f[i].first = a[i];
    for (int i = 0; i < int(b.size()); i++) f[i].second = b[i];
    fft(f); pair<F, F> r(0, -0.25 / N);
    for (int i = 0; i <= N / 2; i++) {
        int j = (N - i) & (N - 1); pair<F, F> prod = (f[j] * f[j] - conj(f[i] * f[i])) * r; f[i] = prod; f[j] = conj(prod);
    }
    fft(f); res.resize(N); bool isIntegral = is_integral<T>::value;
    for (int i = 0; i < N; i++) res[i] = isIntegral ? round(f[i].first) : f[i].first;
    while (int(res.size()) > 1 && res.back() == 0) res.pop_back();
}

const int MM = 2e5+5;

int n, x, a[MM];

int main(){
    scan(n, x);
    int p = 0, last = -1;
    ll f = 0;
    vector<ll> v(n+1), v2, ans;
    v[0] = 1;
    for(int i = 0; i < n; i++){
        scan(a[i]);
        p += a[i] < x;
        v[p]++;
        
        if(a[i] >= x){
            f += i-last;
        }
        else{
            last = i;
        }
    }
    v2 = v;
    reverse(all(v2));
    multiplyPolynomial(v, v2, ans);
    printf("%lld ", f);
    for(int i = n+1; i <= n+n; i++)
        printf("%lld ", ans[i]);
    
    return 0;
}