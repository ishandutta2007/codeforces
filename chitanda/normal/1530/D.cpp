#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define y1 y114514
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define all(a) a.begin(), a.end()
const int M = 1000000007;

const int maxn = 200005;
int T;
int n;
int a[maxn], b[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) b[i] = 0;
        int ans = 0;
        vector<int> va, vb;
        va.reserve(n);
        vb.reserve(n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
            if (b[a[i]] == 0) {
                b[a[i]] = i;
                ++ans;
            } else {
                va.pb(i);
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (!b[i]) vb.pb(i);
        }
        if (ans == n - 1 && va[0] == vb[0]) {
            int t = b[a[va[0]]];
            b[a[va[0]]] = va[0];
            va[0] = t;
        }
        sort(all(va));
        sort(all(vb));
        reverse(all(vb));

        for (int i = 0; i < va.size(); ++i)
            if (va[i] == vb[i]) {
                if (i > 0) {
                    swap(va[i - 1], va[i]);
                } else {
                    swap(va[i], va[i + 1]);
                }
            }

        for (int i = 0; i < va.size(); ++i) b[vb[i]] = va[i], a[va[i]] = vb[i];

        printf("%d\n", ans);
        for (int i = 1; i <= n; ++i) printf("%d ", a[i]);
        puts("");
    }
    return 0;
}