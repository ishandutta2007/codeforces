#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int vals[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &vals[i]);
    }

    int ind = 0;
    for (;;) {
        vals[ind] -= m;
        int ni = ind;
        do {
            ++ni;
            if (ni == n)
                ni = 0;
        } while (ni != ind && vals[ni] <= 0);
        if (ni == ind) {
            printf("%d", ind + 1);
            return 0;
        }
        ind = ni;
    }
    return 0;
}