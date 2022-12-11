#include <cstdio>
typedef long long int64;
static const int MAXN = 100007;
static const int TBD = -1888888;
static const int64 MODULUS = 1234567891363;

int n, k, tbd;
int a[MAXN] = { 0 };

int main()
{
    scanf("%d%d", &n, &k); getchar();
    char ch, flag;
    for (int i = 0; i <= n; ++i) {
        if ((ch = getchar()) == '?') (a[i] = TBD), ++tbd, getchar();
        else {
            flag = (ch == '-' ? ((ch = getchar()), -1) : 1);
            do a[i] = a[i] * 10 + ch - '0'; while ((ch = getchar()) != '\n');
            a[i] *= flag;
        }
    }

    if (k == 0) {
        if (a[0] == TBD) puts((n + 1 - tbd) % 2 == 1 ? "Yes" : "No");
        else puts(a[0] == 0 ? "Yes" : "No");
    } else {
        if (tbd == 0) {
            // Check whether k is a root of the polynomial
            int64 r = 0;
            for (int i = n; i >= 0; --i)
                r = (r * k + a[i]) % MODULUS;
            puts(r == 0 ? "Yes" : "No");
        } else {
            puts((n + 1) % 2 == 0 ? "Yes" : "No");
        }
    }
    return 0;
}