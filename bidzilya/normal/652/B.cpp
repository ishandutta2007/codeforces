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

int main() {
    int n;
    scanf("%d", &n);

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    sort(a.begin(), a.end());

    vector<int> b(n);
    for (int i = 0, l = 0, r = n - 1; i < n; ++i) {
        if (i & 1) {
            b[i] = a[r];
            --r;
        } else {
            b[i] = a[l];
            ++l;
        }
    }

    for (int x : b) {
        printf("%d ", x);
    }
    printf("\n");

    return 0;
}