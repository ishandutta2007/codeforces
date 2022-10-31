#include<bits/stdc++.h>
#define LL long long
#define LD long double
#define ull unsigned long long
#define fi first
#define se second
#define mk make_pair
#define PLL pair<LL, LL>
#define PLI pair<LL, int>
#define PII pair<int, int>
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(), (x).end()
#define fio ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

const int N = 1e6 + 7;
const int inf = 0x3f3f3f3f;
const LL INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-8;
const double PI = acos(-1);

template<class T, class S> inline void add(T& a, S b) {a += b; if(a >= mod) a -= mod;}
template<class T, class S> inline void sub(T& a, S b) {a -= b; if(a < 0) a += mod;}
template<class T, class S> inline bool chkmax(T& a, S b) {return a < b ? a = b, true : false;}
template<class T, class S> inline bool chkmin(T& a, S b) {return a > b ? a = b, true : false;}

int n;
int a[N], tota;
int b[N], totb;
int F[N], Finv[N], inv[N];

int ans;
int cnt[21];

inline int C(int n, int m) {
    if(n < m || m < 0) return 0;
    return 1LL * F[n] * Finv[m] % mod * Finv[n - m] % mod;
}

void calc(int n, int m) {
    int ret = F[cnt[0]], tmp = 0, sum = cnt[0];
    for(int i = 1; i < m; i++) {
        tmp = ret;
        ret = 1LL * ret * cnt[i] % mod;
        ret = 1LL * ret * C(sum + cnt[i] - 1, cnt[i] - 1) % mod * F[cnt[i] - 1] % mod;
        sum += cnt[i];
    }
    add(ans, ret);
}

void init() {
    F[0] = Finv[0] = inv[1] = 1;
    for(int i = 2; i < N; i++) inv[i] = 1LL * (mod - mod / i) * inv[mod % i] % mod;
    for(int i = 1; i < N; i++) F[i] = 1LL * F[i - 1] * i % mod;
    for(int i = 1; i < N; i++) Finv[i] = 1LL * Finv[i - 1] * inv[i] % mod;
}

int main() {
    init();
    a[++tota] = 2;
    for(int i = 2; ;i++) {
        a[i] = a[i - 1] * 2;
        tota++;
        if(a[i] > 1000000) break;
    }
    b[++totb] = 3;
    for(int i = 2; ;i++) {
        b[i] = b[i - 1] * 2;
        totb++;
        if(b[i] > 1000000) break;
    }

    scanf("%d", &n);
    int pa = upper_bound(a + 1, a + 1 + tota, n) - a - 1;
    int pb = upper_bound(b + 1, b + 1 + totb, n) - b - 1;

    int num = 0;
    for(int i = pa - 1; i >= 0; i--) {
        if(i) cnt[i] = n / (1 << i) - n / (1 << (i + 1));
        else cnt[i] = n - n / 2;
    }

    calc(n, pa);

    if(pb == pa) {
        for(int o = pb - 1; o >= 0; o--) {
            int bit = pb - 1;
            for(int i = pb - 1; i >= 0; i--) {
                if(i > o) {
                    cnt[i] = n / 3 / (1 << (bit - 1)) - n / 3 / (1 << bit);
                    bit--;
                } else if(i < o) {
                    if(i) {
                        cnt[i] = n / (1 << (bit - 1)) - n / (1 << bit);
                        bit--;
                    } else cnt[i] = n - n / 2;
                } else {
                    if(i) {
                        cnt[i] = n / (1 << bit) - n / (1 << bit) / 3;
                    }
                    else cnt[i] = n - n / 3;
                }
            }
            calc(n, pb);
        }
    }

    printf("%d\n", ans);
    return 0;
}

/*
*/