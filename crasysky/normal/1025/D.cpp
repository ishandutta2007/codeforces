#include <iostream>
#include <cstring>
#include <cstdio>
#define maxn 702
using namespace std;
int read(){
	int cnt = 0;
	char ch = getchar();
	while (ch < '0' || '9' < ch)
		ch = getchar();
	while ('0' <= ch && ch <= '9'){
		cnt = cnt * 10 + ch- '0';
		ch = getchar();
	}
	return cnt;
}
int n, a[maxn], f[maxn][maxn][2];
bool G[maxn][maxn];
bool dfs(int l, int r, int flag){
	if (f[l][r][flag] != -1)
		return f[l][r][flag];
	int fa = flag == 0 ? l - 1 : r + 1;
	if (l == r)
		return f[l][r][flag] = G[l][fa];
	if (G[l][fa] && dfs(l + 1, r, 0))
		return f[l][r][flag] = 1;
	if (G[r][fa] && dfs(l, r - 1, 1))
		return f[l][r][flag] = 1;
	for (int i = l + 1; i < r; ++ i)
		if (G[i][fa] && dfs(l, i - 1, 1) && dfs(i + 1, r, 0))
			return f[l][r][flag] = 1;
	return f[l][r][flag] = 0;
}
int gcd(int x, int y){
	if (y == 0)
		return x;
	return gcd(y, x % y);
}
int main(){
	int n = read();
	for (int i = 1; i <= n; ++ i)
		a[i] = read();
	for (int i = 1; i <= n; ++ i)
		for (int j = i + 1; j <= n; ++ j)
			if (gcd(a[i], a[j]) != 1)
				G[i][j] = G[j][i] = true;
	memset(f, -1, sizeof(f));
	bool flag = dfs(1, n - 1, 1) || dfs(2, n, 0);
	if (! flag)
		for (int i = 2; i < n; ++ i)
			if (dfs(1, i - 1, 1) && dfs(i + 1, n, 0)){
				flag = true;
				break;
			}
	if (flag)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}