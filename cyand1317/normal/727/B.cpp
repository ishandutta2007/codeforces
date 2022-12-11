#include <cstdio>
#include <cstdlib>
typedef long long int64;
static const int MAXN = 1005;

int n;
char s[MAXN];

inline void skip_token_item(int &p) {
    while (s[p] >= 'a' && s[p] <= 'z') ++p;
}
inline int skip_token_price(int &p) {
    int last_dot = 114514, q = p;
    while (s[q] == '.' || (s[q] >= '0' && s[q] <= '9')) ++q;
    int cents = 0;
    for (; p < q; ++p) {
        if (s[p] == '.') last_dot = p;
        else cents = cents * 10 + s[p] - '0';
    }
    if (last_dot != p - 3) cents *= 100;
    return cents;
}

int main()
{
    for (n = 0; (s[n] = getchar()) != '\n'; ++n) ;

    int p = 0;
    int64 sum = 0;
    while (p < n) {
        skip_token_item(p);
        sum += skip_token_price(p);
    }

    char s[32];
    p = 0;
    //itoa(sum, s, 10);
    //sprintf(s, "%d", sum);
    if (sum % 100 != 0) {
        s[p++] = sum % 10 + '0'; sum /= 10;
        s[p++] = sum % 10 + '0'; sum /= 10;
        s[p++] = '.';
    } else sum /= 100;
    int digits = 0;
    do {
        if (digits > 0 && digits % 3 == 0) s[p++] = '.';
        s[p++] = sum % 10 + '0'; sum /= 10;
        ++digits;
    } while (sum);
    for (--p; p >= 0; --p) putchar(s[p]); putchar('\n');
    return 0;
}