#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1000006;
const int P = 998244353;
int d[maxn], fac[maxn];
int read(){
	int c = 0, f = 1; char ch = getchar();
	while (ch != '-' && (ch < '0' || '9' < ch)) ch = getchar();
	if (ch == '-') f = -1, ch = getchar();
	while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
	return c * f;
}
int main(){
	int n = read();
	for (int i = 1; i < n; ++ i){
		int u = read(), v = read();
		++ d[u], ++ d[v];
	}	
	fac[0] = 1;
	for (int i =1 ; i <= n; ++ i)
		fac[i] = 1LL * fac[i - 1] * i % P;
	int ans = n;
	for (int i = 1; i <= n; ++ i)
		ans = 1LL * ans * fac[d[i]] % P;
	cout << ans << endl;
}