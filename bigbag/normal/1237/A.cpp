#include <bits/stdc++.h>

using namespace std;

const int max_n = 22222, inf = 1000111222;

int n, a[max_n], b[max_n];
int sum;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        b[i] = a[i] / 2;
        sum += b[i];
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] % 2) {
            if (sum < 0) {
                if (a[i] > 0) {
                    ++b[i];
                    ++sum;
                }
            } else if (sum > 0) {
                if (a[i] < 0) {
                    --b[i];
                    --sum;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%d\n", b[i]);
    }
    return 0;
}