#include <stdio.h>
#define STANNIS 1
#define DAENERYS 0

unsigned char solve(int n, int k, int odd, int even)
{
    // Stannis: odd, Daenerys: even
    if ((n - k) & 1) {
        // S -> D -> S -> D -> ... -> D -> S
        if (((n - k) / 2 >= even && k % 2 == 0)
            || (n - k) / 2 >= odd) return DAENERYS;
        else return STANNIS;
    } else {
        if (n == k) return (odd & 1) ? STANNIS : DAENERYS;
        // S -> D -> S -> D -> ... -> S -> D
        else return ((n - k) / 2 >= even && k % 2 == 1) ? STANNIS : DAENERYS;
    }
}

int main()
{
    int n, k, i, a, odd = 0, even = 0;
    scanf("%d%d", &n, &k);
    for (i = 0; i < n; ++i) {
        scanf("%d", &a);
        (a & 1) ? ++odd : ++even;
    }
    printf(solve(n, k, odd, even) ? "Stannis" : "Daenerys");
    return 0;
}