#include <cstdio>
static const int MAXN = 100005;

int n;
bool p[MAXN] = { false };

inline bool is_prime(int x) {
    for (int i = 2; i * i <= x; ++i) if (x % i == 0) return false;
    return true;
}

int main()
{
    scanf("%d", &n);
    puts(n <= 2 ? "1" : "2");
    for (int i = 2; i <= n + 1; ++i)
        printf("%d%c", is_prime(i) ? 1 : 2, i == n + 1 ? '\n' : ' ');
    return 0;
}