#include <iostream>
#include <cstdio>

using namespace std;

#define LL long long

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    LL vals[m];
    for (int i = 0; i < m; ++i) {
        scanf("%I64d", &vals[i]);
    }
    LL fedor;
    scanf("%I64d", &fedor);
    int friends = 0;
    for (int i = 0; i < m; ++i) {
        LL comp = fedor ^ vals[i];

        int count = 0;
        while (comp != 0) {
            if (comp % 2 == 1)
                ++count;
            comp >>= 1;
        }
        if (count <= k)
            ++friends;
    }
    printf("%d", friends);
    return 0;
}