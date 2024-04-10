#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
using namespace std;
const int INF = 1e9;
const int maxn = 2e6 + 6;
int fa[maxn], sz[maxn];
int getfa(int x){
	return fa[x] == x ? x : fa[x] = getfa(fa[x]);
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
	for (int i = 1; i <= n; ++ i)
		fa[i] = i;
	for (int i = 1; i <= m; ++ i){
		int k = read(), l = 0;
		for (int j = 1; j <= k; ++ j){
			int x = read();
			if (l)
				fa[getfa(x)] = getfa(l);
			l = x;
		}
	}
	for (int i = 1; i <= n; ++ i)
		++ sz[getfa(i)];
	for (int i = 1; i <= n; ++ i)
		printf("%d ", sz[getfa(i)]);
}