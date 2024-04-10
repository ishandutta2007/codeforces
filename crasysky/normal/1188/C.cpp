#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#define Pr pair <int, int>
#define Mp make_pair 
#define fi first
#define se second
using namespace std;
const int P = 998244353;
const int maxn = 1003;
const int INF = 1e9;
int a[maxn], s[maxn][maxn];
int add(int x, int y){
	x += y;
	return x >= P ? x - P : x;
}
int read(){
	int c = 0; char ch = getchar();
	while (ch < '0' || '9' < ch) ch = getchar();
	while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
	return c;
}
int main(){
	int n = read(), k = read();
	for (int i = 1; i <= n; ++ i)
		a[i] = read();
	sort(a + 1, a + 1 + n);
	a[0] = -INF;
	int ans = 0;
	for (int d = 1; d <= a[n] / (k - 1); ++ d){
		for (int i = 0; i <= n; ++ i)
			s[0][i] = 1;
		for (int j = 1; j <= k; ++ j){
			for (int i = 1, l = 0; i <= n; ++ i){
				while (a[i] - a[l] >= d)
					++ l;
				s[j][i] = add(s[j][i - 1], s[j - 1][l - 1]);
			}
		}
		ans = add(ans, s[k][n]);
	}
	cout << ans % P << endl;
}