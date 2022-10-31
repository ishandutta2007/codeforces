#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1000006;
int fa[maxn];
int getfa(int x){
	if (fa[x] == x) return x;
	return fa[x] = getfa(fa[x]);
}
int read(){
	int c = 0; char ch = getchar();
	while (ch < '0' || '9' < ch) ch = getchar();
	while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
	return c;
}
int main(){
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++ i)
		fa[i] = i;
	int ans = 0;
	for (int i = 1; i <= k; ++ i){
		int u = read(), v = read();
		if (getfa(u) == getfa(v))
			++ ans;
		else
			fa[getfa(u)] = getfa(v);
	}
	cout << ans << endl;
}