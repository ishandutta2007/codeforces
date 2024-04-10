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

const int maxn = 100005;
int T;
int n;
int a[maxn], b[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", a + i);
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d", b + i);
        }
        sort(a, a + n);
        sort(b, b + n);
        int t = n - n / 4, suma = 0, sumb = 0;
        for (int i = n - t; i < n; ++i) {
            suma += a[i];
            sumb += b[i];
        }
        int curi = n - t, curj = n - t, ans = 0;
        // printf("%d %d\n", curi, curj);
        while (suma < sumb) {
            ++ans;
            int nt = (n + ans) - (n + ans) / 4;
            suma += 100;
            if (nt == t)
                suma -= a[curi], ++curi;
            else
                sumb += curj > 0 ? b[curj - 1] : 0, --curj;
            // printf("%d %d\n", suma, sumb);
            t = nt;
        }
        printf("%d\n", ans);
    }
    return 0;
}