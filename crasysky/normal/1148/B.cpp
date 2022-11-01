#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cmath>
#include <set>
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int maxn = 1000006;
int a[maxn], b[maxn];
int read(){
    int c = 0, f = 1; char ch = getchar();
    while (ch != '-' && (ch < '0' || '9' < ch)) ch = getchar();
    if (ch == '-') f = -1, ch = getchar();
    while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
    return c * f;
}
int main(){
    int n = read(), m = read(), ta = read(), tb = read(), k = read();
    for (int i = 1; i <= n; ++ i)
        a[i] = read();
    for (int i = 1; i <= m; ++ i)
        b[i] = read();
    int ans = 0;
    for (int i = 0; i <= k; ++ i){
        int x = a[i + 1] + ta;
        int y = lower_bound(b + 1, b + 1 + m, x) - b;
        if (i + 1 > n || y + (k - i) > m){
            cout << -1 << endl;
            return 0;
        }
        ans = max(ans, b[y + (k - i)] + tb);
    }
    cout << ans << endl;
}