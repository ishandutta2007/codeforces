#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
using namespace std;
typedef double LD;
typedef long long LL;
 
const int maxn = (1 << 19) | 10;
const int base = 1000;
const LD PI = acos(-1);
struct C {
    LD r, i;
    C (LD _r = 0, LD _i = 0) {
        r = _r; i = _i;
    }
    friend C operator + (const C a, const C b) {
        return C(a.r + b.r, a.i + b.i);
    }
    friend C operator - (const C a, const C b) {
        return C(a.r - b.r, a.i - b.i);
    }
    friend C operator * (const C a, const C b) {
        return C(a.r * b.r - a.i * b.i, a.r * b.i + a.i * b.r);
    }
} a[maxn], b[maxn], tmp;
vector<int> R[20];
vector<C> w[20];
int bin[20];
 
void prepare() {
    bin[0] = 1;
    rep (k, 1, 19) {
        bin[k] = bin[k-1] << 1;
        w[k].resize(bin[k] + 1);
        R[k].resize(bin[k] + 1);
        rep (i, 0, bin[k]-1)
            w[k][i] = C(cos(2*i*PI/bin[k]), sin(2*i*PI/bin[k]));
        w[k][bin[k]] = w[k][0];
        rep (i, 0, bin[k]-1)
            R[k][i] = (R[k][i>>1]>>1) | ((i&1)<<(k-1));
    }
}
 
void FFT(C a[maxn], int l, int flag) {
    rep (i, 0, bin[l]-1)
        if (i < R[l][i]) swap(a[i], a[R[l][i]]);
    for (int d = 1, t = bin[l] >> 1; d < bin[l]; d <<= 1, t >>= 1)
        for (int i = 0; i < bin[l]; i += (d << 1)) rep (j, 0, d-1) {
            tmp = w[l][flag ? bin[l]-t*j : t*j] * a[i+j+d];
            a[i+j+d] = a[i+j] - tmp;
            a[i+j] = a[i+j] + tmp;
        }
    if (!flag) return;
    rep (i, 0, bin[l]-1) a[i].r /= bin[l];
}
 
void mul(vector<int> &A, vector<int> &B, vector<int>&R) {
    int l = 1, nA = A.size(), nB = B.size();
    while (bin[l] <= nA + nB) l++;
    rep (i, 0, bin[l]-1)
        a[i] = C(i < nA ? A[i] : 0, 0);
    rep (i, 0, bin[l]-1)
        b[i] = C(i < nB ? B[i] : 0, 0);
    FFT(a, l, 0); FFT(b, l, 0);
    rep (i, 0, bin[l]-1)
        a[i] = a[i] * b[i];
    FFT(a, l, 1);
    int limit = bin[l]-1;
    while (limit && fabs(a[limit].r) < 0.5) limit--;
    vector<LL> T;
    T.resize(limit + 1); T[0] = 0;
    rep (i, 0, limit-1) {
        T[i] += LL(a[i].r + 0.5);
        T[i+1] = T[i] / base;
        T[i] %= base;
    }
    T[limit] += LL(a[limit].r + 0.5);
    while (T[limit] >= base) {
        T.push_back(T[limit] / base);
        T[limit++] %= base;
    }
    R.resize(T.size());
    rep (i, 0, limit) R[i] = T[i];
}
 
void quickpower3(vector<int> &RES, int p) {
    vector<int> A;
    A.push_back(3);
    RES.push_back(1);
    while (p) {
        if (p & 1) mul(RES, A, RES);
        if (p >= 2) mul(A, A, A); p >>= 1;
    }
}
 
void mulnum(vector<int> &A, int num) {
    int n = A.size();
    rep (i, 0, n-1) A[i] *= num;
    rep (i, 0, n-2)
        while (A[i] >= base)
            A[i] -= base, A[i+1]++;
    while (A[n-1] >= base) {
        A.push_back(A[n-1] / base);
        A[(n++)-1] %= base;
    }
}
 
vector<int> p3[10], now, need;
int n, ans, bbb;
char s[maxn*3];
 
bool check() {
    int n = now.size();
    if (n > need.size()) return 1;
    if (n < need.size()) return 0;
    per (i, n-1, 0)
        if (now[i] > need[i]) return 1;
        else if (now[i] < need[i]) return 0;
    return 1;
}
 
void solve(int need) {
    int pow3[10]; pow3[0] = 1;
    rep (i, 1, 9) pow3[i] = pow3[i-1] * 3;
    int ans = 0, now;
    while (1) {
        ans++;
        if (ans == 1) now = 1;
        else if (ans % 3 == 0) now = pow3[ans / 3];
        else if (ans % 3 == 1) now = pow3[ans / 3 - 1] * 4;
        else now = pow3[ans / 3] * 2;
        if (now >= need) break;
    }
    printf("%d\n", ans);
}
 
int main() {
    prepare();
    scanf("%s", s);
    n = strlen(s);
    if (n <= 2) return solve(n == 1 ? s[0]-'0' : (s[0]-'0')*10 + s[1]-'0'), 0;
    need.resize((n + 2) / 3);
    rep (i, 0, n-1) {
        int tmp = n - i - 1;
        if (tmp % 3 == 0) need[tmp/3] += s[i] - '0';
        else if (tmp % 3 == 1) need[tmp/3] += (s[i] - '0') * 10;
        else need[tmp/3] += (s[i] - '0') * 100;
    }
    bbb = int(n * log(10) / log(3)) - 3;
    quickpower3(p3[0], bbb);
    rep (i, 1, 5) {
        p3[i] = p3[i-1];
        mulnum(p3[i], 3);
    }
    ans = bbb * 3 + 3;
    while (1) {
        ans++; //printf("%d\n", ans);
        if (ans % 3 == 0) {
            now = p3[ans / 3 - bbb];
        }
        else if (ans % 3 == 1) {
            now = p3[ans / 3 - 1 - bbb];
            mulnum(now, 4);
        }
        else {
            now = p3[ans / 3 - bbb];
            mulnum(now, 2);
        }
        if (check()) break;
    }
    printf("%d\n", ans);
    return 0;
}