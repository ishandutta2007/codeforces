#include <cstdio>
#include <cstring>
typedef long long int64;
static const int MAXN = 2005;

int n;
char s[MAXN];
bool is_palindrome[MAXN][MAXN] = {{ false }};
int palindrome_start_ct[MAXN] = { 0 };

int main()
{
    gets(s); n = strlen(s);

    for (int i = 0; i < n; ++i) {
        is_palindrome[i][i] = true;
        if (i > 0) is_palindrome[i - 1][i] = (s[i - 1] == s[i]);
    }
    for (int len = 3; len <= n; ++len)
        for (int i = 0; i + len <= n; ++i)
            is_palindrome[i][i + len - 1] = (is_palindrome[i + 1][i + len - 2] && s[i] == s[i + len - 1]);
    for (int i = 0; i < n; ++i)
        for (int j = i; j < n; ++j)
            palindrome_start_ct[i] += (int)is_palindrome[i][j];

    int64 ans = 0, prev_palindromes = 0;
    for (int i = 0; i < n; ++i) {
        ans += (int64)prev_palindromes * palindrome_start_ct[i];
        for (int j = 0; j <= i; ++j) prev_palindromes += (int)is_palindrome[j][i];
    }

    printf("%I64d\n", ans);
    return 0;
}