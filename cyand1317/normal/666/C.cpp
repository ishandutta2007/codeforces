#include <cstdio>
typedef long long int64;
static const int MAXN = 100007;
static const int MODULUS = 1e9 + 7;
#define _ % MODULUS

int n, m, l;

inline void get_string_length() {
    l = 0;
    static char ch;
    while ((ch = getchar()) >= 'a' && ch <= 'z') ++l;
}

inline int fpow(int b, int e) {
    int64 ans = 1;
    while (e) {
        if (e & 1) ans = ans * b _;
        b = (int64)b * b _;
        e >>= 1;
    }
    return (int)ans;
}
int pow26[MAXN], pow25[MAXN];
int fact[MAXN], fact_inv[MAXN];
inline void preprocess() {
    pow26[0] = pow25[0] = 1;
    fact[0] = fact_inv[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        pow26[i] = (int64)pow26[i - 1] * 26 _;
        pow25[i] = (int64)pow25[i - 1] * 25 _;
        fact[i] = (int64)fact[i - 1] * i _;
        fact_inv[i] = fpow(fact[i], MODULUS - 2);
    }
}
inline int nCr(int n, int m) { return (int64)fact[n] * fact_inv[m]_ * fact_inv[n - m]_; }
int *ans[MAXN] = { NULL };
inline void update_answers() {
    if (ans[l]) return;
    ans[l] = new int[MAXN]();
    for (int i = 0; i < l; ++i) ans[l][i] = 0;
    ans[l][l] = 1;
    for (int i = l + 1; i < MAXN; ++i)
        ans[l][i] = ((int64)ans[l][i - 1] * 26 + (int64)nCr(i - 1, l - 1) * pow25[i - l])_;
}

int main()
{
    preprocess();
    scanf("%d", &m); getchar();
    get_string_length();
    update_answers();
    int op, arg;
    do {
        scanf("%d", &op); getchar();
        if (op == 1) {
            get_string_length();
            update_answers();
        } else {
            scanf("%d", &n);
            printf("%d\n", ans[l][n]);
        }
    } while (--m);
    return 0;
}