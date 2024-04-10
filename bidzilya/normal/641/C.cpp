#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#ifdef LOCAL
    #define LLD_SPEC "%lld"
#else
    #define LLD_SPEC "%I64d"
#endif

void Normalize(int& x, int n) {
    x %= n;
    if (x < 0) {
        x += n;
    }
}

int main() {
    int n, q;
    scanf("%d%d", &n, &q);

    int shift[2];
    shift[0] = shift[1] = 0;

    int invCount = 0;
    for (; q; --q) {
        int tp;
        scanf("%d", &tp);
        if (tp == 1) {
            int x;
            scanf("%d", &x);

            shift[0] += x;
            shift[1] += x;

            if (abs(x) & 1) {
                ++invCount;
            }
        } else {
            if (invCount & 1) {
                shift[0] -= 1;
                shift[1] += 1;
            } else {
                shift[0] += 1;
                shift[1] -= 1;
            }
            ++invCount;
        }

        Normalize(shift[0], n);
        Normalize(shift[1], n);
    }

    vector<int> result(n);
    for (int i = 0; i < n; ++i) {
        int s = shift[i & 1];
        s += i;
        Normalize(s, n);

        result[s] = i;
    }

    for (int i = 0; i < n; ++i) {
        printf("%d ", result[i] + 1);
    }
    printf("\n");

    return 0;
}