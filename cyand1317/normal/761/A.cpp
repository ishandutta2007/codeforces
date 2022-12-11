#include <cstdio>
#include <cstdlib>

int main()
{
    int a, b; scanf("%d%d", &a, &b);
    puts(((a || b) && std::abs(a - b) <= 1) ? "YES" : "NO");
    return 0;
}