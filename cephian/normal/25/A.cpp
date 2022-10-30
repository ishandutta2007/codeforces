#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int odd = 0, even = 0;
    int oddi, eveni;
    for (int i = 0; i < n; ++i) {
        int tmp;
        scanf("%d", &tmp);
        if (tmp % 2 == 0) {
            eveni = i + 1;
            ++even;
        } else {
            oddi = i + 1;
            ++odd;
        }
    }
    if (odd == 1)
        printf("%d", oddi);
    else
        printf("%d", eveni);
    fflush(stdout);
    return 0;
}