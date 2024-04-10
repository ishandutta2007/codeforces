#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
#include <set>
#define Pr pair <int, int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int P = 998244353;
const int maxn = 1003;
const int INF = 1000000000;
int c[maxn], p[maxn], f[maxn][maxn];
int solve(int l, int r){
    if (l >= r)
        return 1;
    if (f[l][r])
        return f[l][r];
    int c;
    for (c = 1; p[c] < l || r < p[c]; ++ c);
    int x = p[c], s1 = 0, s2 = 0;
    for (int i = l; i <= x; ++ i)
        s1 = (s1 + 1LL * solve(l, i - 1) * solve(i, x - 1)) % P;
    for (int j = x; j <= r; ++ j)
        s2 = (s2 + 1LL * solve(x + 1, j) * solve(j + 1, r)) % P;
    return f[l][r] = 1LL * s1 * s2 % P;
}
int read(){
	int c = 0, f = 1; char ch = getchar();
	while (ch != '-' && (ch < '0' || '9' < ch)) ch = getchar();
	if (ch == '-') f = -1, ch = getchar();
	while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
	return c * f;
}
int main(){
    int n = read(), m = read();
    for (int i = 1; i <= m; ++ i)
        p[c[i] = read()] = i;
    cout << solve(1, m) << endl;
}