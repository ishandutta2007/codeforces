#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a % b);
}

int n;
int a[200020];

vector<int> gv[200020];
int mx[200020];
bool ok[200020];
int ri[200020];

int vr[200020];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    for (int i = 1; i < n; ++i) {
        gv[gcd(i, n)].push_back(i);
    }
    
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (!gv[i].size()) {
            continue;
        }
        memset(mx, 0, sizeof(mx));
        int k = 0;
        for (int j = 0; j < n; ++j) {
            mx[k] = max(mx[k], a[j]);
            ++k;
            if (k >= i) {
                k = 0;
            }
        }
        memset(ok, 0, sizeof(ok));
        k = 0;
        int s = -1;
        for (int j = 0; j < n; ++j) {
            if (a[j] == mx[k]) {
                ok[j] = 1;
            } else {
                s = j;
            }
            ++k;
            if (k >= i) {
                k = 0;
            }
        }
        if (s == -1) {
            ans += (long long) n * gv[i].size();
        } else {
            memset(vr, 0, sizeof(vr));
            ri[s] = 0;
            int t = s;
            --s;
            if (s < 0) {
                s = n - 1;
            }
            for (int j = 1; j < n; ++j) {
                if (!ok[s]) {
                    ri[s] = 0;
                } else {
                    ri[s] = ri[t] + 1;
                    vr[ri[s]]++;
                }
                t = s;
                --s;
                if (s < 0) {
                    s = n - 1;
                }
            }
            for (int j = n - 1; j >= 0; --j) {
                vr[j] = vr[j + 1] + vr[j];
            }
            for (int j = 0; j < (int) gv[i].size(); ++j) {
                ans += vr[gv[i][j]];
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}