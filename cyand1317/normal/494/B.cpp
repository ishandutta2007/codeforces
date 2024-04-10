#include <cstdio>
static const int MAXN = 1e5 + 4;
static const int MODULUS = 1e9 + 7;
#define _  %  MODULUS
#define __ %= MODULUS

int slen, tlen;
char s[MAXN], t[MAXN];
int fail[MAXN], match[MAXN];
int ans[MAXN] = { 0 };

int main()
{
    for (slen = 0; (s[slen] = getchar()) != '\n'; ++slen) ;
    for (tlen = 0; (t[tlen] = getchar()) != '\n'; ++tlen) ;
    // KMP
    int cnd = 0;
    fail[0] = 0;
    for (int i = 1; i < tlen; ++i) {
        while (cnd > 0 && t[i] != t[cnd]) cnd = fail[cnd - 1];
        if (t[i] == t[cnd]) fail[i] = ++cnd; else fail[i] = 0;
    }
    //for (int i = 0; i < tlen; ++i) printf("%d%c", fail[i], i == tlen - 1 ? '\n' : ' ');
    cnd = match[0] = (s[0] == t[0] ? 1 : 0);
    for (int i = 1; i < slen; ++i) {
        while (cnd > 0 && s[i] != t[cnd]) cnd = fail[cnd - 1];
        if (s[i] == t[cnd]) match[i] = ++cnd; else match[i] = 0;
    }
    //for (int i = 0; i < slen; ++i) printf("%d%c", match[i], i == slen - 1 ? '\n' : ' ');

    int sum = 0, w_sum = 0;
    for (int i = 0; i < slen; ++i) {
        if (match[i] == tlen) {
            ans[i] = w_sum + i - tlen + 2;
        } else {
            ans[i] = ans[i - 1];
        }
        if (i - tlen + 1 >= 0) {
            (sum += ans[i - tlen + 1])__;
            (w_sum += sum)__;
        }
    }
    int total = 0;
    for (int i = 0; i < slen; ++i) (total += ans[i])__;
    printf("%d\n", total);

    return 0;
}