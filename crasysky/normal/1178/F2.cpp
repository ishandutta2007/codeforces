#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <map>
#define Pr pair <int, int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int P = 998244353;
const int maxn = 1000006;
const int INF = 1000000000;
int n, c[maxn], _c[maxn], mn[maxn], mx[maxn];
vector <int> p[maxn];
int f[1003][1003];
int solve(int l, int r){
    if (l > r)
        return 1;
    if (f[l][r] != -1)
        return f[l][r];
    int c;
    for (c = 1; ! (l <= mn[c] && mx[c] <= r) && c <= n; ++ c);
    if (c > n)
        return f[l][r] = 0;
    if (l == r)
        return 1;
    int x = mn[c], y = mx[c], s1 = 0, s2 = 0;
    for (int i = l; i <= x; ++ i)
        s1 = (s1 + 1LL * solve(l, i - 1) * solve(i, x - 1)) % P;
    for (int j = y; j <= r; ++ j)
        s2 = (s2 + 1LL * solve(y + 1, j) * solve(j + 1, r)) % P;
    int s = 1LL * s1 * s2 % P;
    for (int i = 1; i < p[c].size(); ++ i)
        s = 1LL * s * solve(p[c][i - 1] + 1, p[c][i] - 1) % P;
    return f[l][r] = s;
}
int read(){
	int c = 0, f = 1; char ch = getchar();
	while (ch != '-' && (ch < '0' || '9' < ch)) ch = getchar();
	if (ch == '-') f = -1, ch = getchar();
	while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
	return c * f;
}
int main(){
    n = read();
    int m = read();
    for (int i = 1; i <= n; ++ i)
        mn[i] = INF, mx[i] = -INF;
    for (int i = 1; i <= m; ++ i)
        c[i] = read();
    int _n = 0;
    _c[++ _n] = c[1];
    for (int i = 2; i <= m; ++ i)
        if (c[i] != _c[_n])
            _c[++ _n] = c[i];
    swap(c, _c), swap(m, _n);
    if (m > 2 * n){
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1; i <= m; ++ i){
        p[c[i]].push_back(i);
        mn[c[i]] = min(mn[c[i]], i), mx[c[i]] = max(mx[c[i]], i);
    }
    memset(f, -1, sizeof(f));
    cout << solve(1, m) << endl;
}