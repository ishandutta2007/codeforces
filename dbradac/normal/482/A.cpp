#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int i, n, k, st, zadnji;

    scanf("%d%d", &n, &k);

    for (i=n; i>k; i--)
        printf("%d ", i);

    zadnji = k + 1;
    for (i=k, st=-1; i>=1; i--, st*=-1) {
        zadnji += i * st;
        printf("%d ", zadnji);
    }
    printf("\n");

    return 0;
}