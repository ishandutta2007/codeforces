#include <cstdio>
using namespace std;

const int max_n = 1e5 + 10;

int n;
int a[max_n];

int main() {
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i)
            scanf("%d", a + i);
        int np = 0;
        for (int i = 0; i < n; ++i)
            if (a[i] == i)
                ++np;
        if (np == n) {
            printf("%d\n", n);
            continue;
        }
        int ans = np + 1;
        for (int i = 0; i < n; ++i) 
            if (a[i] != i) {
                if (a[a[i]] == i) {
                    ans = np + 2;
                }
            }
        printf("%d\n", ans);
    }

    return 0;
}