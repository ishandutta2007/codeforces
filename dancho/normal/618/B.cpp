#include <cstdio>
#include <cstring>
using namespace std;

bool us[64];

int n;
int a[64][64];

int p[64];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    memset(us, 0, sizeof(us));

    for (int v = 1; v <= n; ++v) {
        int cnt = 0;
        for (int po = 0; po < n; ++po) {
            if (us[po]) {
                continue;
            }
            bool ok = true;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (a[i][j] == v && i != po && j != po) {
                        ok = false;
                    }
                }
            }
            if (!ok) {
                continue;
            }
            us[po] = 1;
            p[po] = v;
            break;
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%d%c", p[i], " \n"[i == n - 1]);
    }
    return 0;
}