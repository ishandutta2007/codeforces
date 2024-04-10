#include <cstdio>

int n;
int odd_ct = 0;

int main()
{
    scanf("%d", &n);
    for (int i = 0, a_i; i < n; ++i) {
        scanf("%d", &a_i);
        if (a_i & 1) ++odd_ct;
    }

    puts((odd_ct >= 1) ? "First" : "Second");
    return 0;
}