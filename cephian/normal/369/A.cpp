#include <iostream>
#include <cstdio>

using namespace std;

int max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int tot = 0;
    for (int i = 0; i < n; ++i) {
        int tmp;
        scanf("%d", &tmp);
        if (tmp == 1) {
            if (m == 0)
                ++tot;
            else
                --m;
        } else {
            if (k == 0) {
                if (m == 0)
                    ++tot;
                else
                    --m;
            } else
                --k;
        }
    }
    printf("%d", tot);
    fflush(stdout);
    return 0;
}