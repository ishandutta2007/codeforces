#include <cstdio>

int n, k;
char s[104];
int ct[26] = { 0 };

int main()
{
    scanf("%d%d%s", &n, &k, s);

    for (int i = 0; i < n; ++i) {
        if (++ct[s[i] - 'a'] > k) { puts("NO"); return 0; }
    }

    puts("YES"); return 0;
}