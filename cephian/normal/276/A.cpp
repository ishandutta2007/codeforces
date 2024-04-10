#include <iostream>
#include <cstdio>

using namespace std;

int enj(int k, int t, int f) {
    if (t > k)
        return f - (t - k);
    return f;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int max = -1;
    for (int i = 0; i < n; ++i) {
        int f, t;
        scanf("%d %d", &f, &t);
        if (i == 0) {
            max = enj(k, t, f);
        } else {
            int tmp = enj(k, t, f);
            if (tmp > max)
                max = tmp;
        }
    }
    printf("%d", max);
}