#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1005;
const int inf = 0x3f3f3f3f;

int n;
int a[maxn], b[maxn];

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
        sort(b + 1, b + n + 1);

        int i = 1;
        bool flg = 1;
        for (int j = 1; j <= n; j++) {
            if (a[j] <= b[j] && a[j] >= b[j] - 1) ;
            else flg = 0;
        }
        if (flg) printf("YES\n"); else printf("NO\n");
    }
}