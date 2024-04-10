#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n, m;
    scanf("%d", &n);
    int piles[n];
    int cum[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &piles[i]);
        cum[i] = piles[i];
        if (i != 0)
            cum[i] += cum[i - 1];
    }
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        int q;
        scanf("%d", &q);
        int max = n - 1;
        int min = 0;
        while (min != max) {
            int mid = (max + min) / 2;
            if (cum[mid] >= q)
                max = mid;
            else {
                min = mid + 1;
            }
        }
        printf("%d\n", max+1);
    }
}