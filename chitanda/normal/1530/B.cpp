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

int T;
int h, w;
int a[21][21];

int main() {
    scanf("%d", &T);
    while (T--) {
        static int tot = 0;
        ++tot;
        scanf("%d%d", &h, &w);
        for (int i = 0; i < w; i += 2) a[0][i] = tot;
        for (int i = 2; i < h; i += 2) a[i][w - 1] = tot;
        for (int i = w - 3; i >= 0; i -= 2) a[h - 1][i] = tot;
        for (int i = h - 3; i > 1; i -= 2) a[i][0] = tot;
        for (int i = 0; i < h; puts(""), ++i)
            for (int j = 0; j < w; ++j) printf("%d", a[i][j] == tot ? 1 : 0);
        puts("");
    }
    return 0;
}