#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int n;
int a[1 << 20];
int p[1 << 20];
int sl[1 << 20];

int main() {
    scanf("%d", &n);
    memset(p, -1, sizeof(p));
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        p[a[i]] = i;
    }
    int mx = 1;
    sl[n + 1] = 0;
    sl[n] = 1;
    for (int i = n - 1; i > 0; --i) {
        if (p[i] < p[i + 1]) {
            sl[i] = sl[i + 1] + 1;
        } else {
            sl[i] = 1;
        }
        if (sl[i] > mx) {
            mx = sl[i];
        }
    }
    printf("%d\n", n - mx);
    return 0;
}