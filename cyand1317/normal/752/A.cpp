// Network is on holiday today =^= sad
#include <cstdio>

int n, m, k;

int main()
{
    scanf("%d%d%d", &n, &m, &k); --k;
    printf("%d %d %c\n", k / (m * 2) + 1, k % (m * 2) / 2 + 1, k % 2 == 0 ? 'L' : 'R');
    return 0;
}