#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int K = 1005, N = 55, M = 55, INF = 1E9 + 7;

int k, n, m;
int kmp_s[N], nxt_s[N][26], kmp_t[M], nxt_t[M][26];
int dp[K][N][M];
char code[K], s[N], t[M];

void init(char s[], int n, int kmp[], int nxt[][26])
{
    kmp[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        int cur = kmp[i - 1];
        while (cur > 0 && s[cur + 1] != s[i])
            cur = kmp[cur];
        if (s[cur + 1] == s[i])
            ++cur;
        kmp[i] = cur;
    }

    for (int i = 0; i <= n; i++)
        for (char c = 'a'; c <= 'z'; c++)
        {
            int cur = i;
            while (cur > 0 && s[cur + 1] != c)
                cur = kmp[cur];
            if (s[cur + 1] == c)
                ++cur;
            nxt[i][c - 'a'] = cur;
        }
}

int main()
{
    scanf("%s%s%s", code + 1, s + 1, t + 1);
    k = strlen(code + 1); n = strlen(s + 1); m = strlen(t + 1);
    init(s, n, kmp_s, nxt_s); init(t, m, kmp_t, nxt_t);
    for (int i = 0; i <= k; i++)
        for (int ks = 0; ks <= n; ks++)
            for (int kt = 0; kt <= m; kt++)
                dp[i][ks][kt] = -INF;
    dp[0][0][0] = 0;
    for (int i = 0; i < k; i++)
        for (int ks = 0; ks <= n; ks++)
            for (int kt = 0; kt <= m; kt++)
                for (char c = 'a'; c <= 'z'; c++)
                    if (code[i + 1] == '*' || code[i + 1] == c) // we now add/replace the (i + 1)-th character
                    {
                        int ns = nxt_s[ks][c - 'a'], nt = nxt_t[kt][c - 'a'];
                        int tmp = dp[i][ks][kt] + (ns == n) - (nt == m); // add the new occurrences if any
                        dp[i + 1][ns][nt] = max(dp[i + 1][ns][nt], tmp);
                    }
    int ma = -INF;
    for (int ks = 0; ks <= n; ks++)
        for (int kt = 0; kt <= m; kt++)
            ma = max(ma, dp[k][ks][kt]);
    printf("%d\n", ma);
}