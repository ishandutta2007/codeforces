#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#include <set>
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int maxn = 1000006;
const int P = 1000000007;
const int INF = 2000000000;
pair <int, int> a[maxn];
int f[maxn][2], s[maxn][2];
int read(){
    int c = 0, f = 1; char ch = getchar();
    while ((ch < '0' || '9' < ch) && ch != '-') ch = getchar();
    if (ch == '-') f = -1, ch = getchar();
    while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
    return c * f;
}
int main(){
    int n = read();
    for (int i = 1; i <= n; ++ i)
        a[i].fi = read(), a[i].se = read();
    sort(a + 1, a + 1 + n);
    int mx = 0;
    s[0][1] = 1;
    for (int i = 1; i <= n; ++ i){
        int t = upper_bound(a + 1, a + i, mp(a[i].se, INF)) - a - 1;
        mx = max(mx, t);
        f[i][0] = s[t][0] + a[i].se;
        f[i][1] = s[t][1];
        if (s[i - 1][0] > f[i][0] - a[i].fi)
            s[i][0] = f[i][0] - a[i].fi, s[i][1] = f[i][1];
        else if (s[i - 1][0] == f[i][0] - a[i].fi)
            s[i][0] = s[i - 1][0], s[i][1] = (s[i - 1][1] + f[i][1]) % P;
        else
            s[i][0] = s[i - 1][0], s[i][1] = s[i - 1][1];
    }
    int x = INF, y = 0;
    for (int i = mx + 1; i <= n; ++ i)
        if (f[i][0] < x)
            x = f[i][0], y = f[i][1];
        else if (f[i][0] == x)
            y = (y + f[i][1]) % P;
    cout << y << endl;
}