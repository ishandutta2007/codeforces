#include <cstdio>
static const int MAXN = 1024;

int n;
int f[MAXN];

inline bool check_berland()
{
    if (n == 1) return f[0];
    int sum = 0;
    for (int i = 0; i < n; ++i) sum += f[i];
    return sum == n - 1;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &f[i]);
    puts(check_berland() ? "YES" : "NO");
    return 0;
}