#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct laptop {
    int price;
    int quality;
};

bool lessthan(laptop a, laptop b) {
    return a.price < b.price;
}

int main() {
    int n;
    scanf("%d", &n);
    laptop vals[n];
    for (int i = 0; i < n; ++i) {
        laptop l;
        scanf("%d %d", &l.price, &l.quality);
        vals[i] = l;
    }
    std::sort(vals, vals + n, lessthan);
    int p_p = -1;
    int p_q = -1;
    for (int i = 0; i < n; ++i) {
        laptop tmp = vals[i];
        if (p_p != -1) {
            if (tmp.price > p_p && tmp.quality < p_q) {
                printf("Happy Alex");
                return 0;
            }
        }
        p_p = tmp.price;
        p_q = tmp.quality;
    }
    printf("Poor Alex");
    return 0;
}