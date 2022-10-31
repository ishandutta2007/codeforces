#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#define Pr pair <int, int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int maxn = 1000006;
int mx, x[maxn], y[maxn], X[maxn], Y[maxn], C[maxn];
vector <int> V[maxn];
set <int> st;
long long calc(int n){
	return 1LL * n * (n + 1) / 2;
}
void add(int x){
	for (; x <= mx; x += x & -x)
		++ C[x];
}
int sum(int x){
	int s = 0;
	for (; x; x -= x & -x)
		s += C[x];
	return s;
}
int read(){
	int c = 0; char ch = getchar();
	while (ch < '0' || '9' < ch) ch = getchar();
	while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
	return c;
}
int main(){
	int n = read(), my = 0;
	for (int i = 1; i <= n; ++ i){
		x[i] = read(), y[i] = read();
		X[++ mx] = x[i];
		Y[++ my] = y[i];
	}
	sort(X + 1, X + 1 + mx);
	mx = unique(X + 1, X + 1 + mx) - X - 1;
	for (int i = 1; i <= n; ++ i)
		x[i] = lower_bound(X + 1, X + 1 + mx, x[i]) - X;
	sort(Y + 1, Y + 1 + my);
	my = unique(Y + 1, Y + 1 + my) - Y - 1;
	for (int i = 1; i <= n; ++ i)
		y[i] = lower_bound(Y + 1, Y + 1 + my, y[i]) - Y;
	for (int i = 1; i <= n; ++ i)
		V[y[i]].push_back(x[i]);
	for (int i = 1; i <= my; ++ i)
		sort(V[i].begin(), V[i].end());
	long long ans = 0;
	for (int i = my; i; -- i){
		for (int j = 1; j < V[i].size(); ++ j){
			int r = V[i][j], l = V[i][j - 1];
			int s = sum(r - 1) - sum(l);
			ans -= calc(s);
		}
		int s = sum(mx) - sum(V[i][V[i].size() - 1]);
		ans -= calc(s);
		s = sum(V[i][0] - 1);
		ans -= calc(s);
		for (int j = 0; j < V[i].size(); ++ j){
			int x = V[i][j];
			if (st.find(x) == st.end())
				st.insert(x), add(x);
		}
		ans += calc(st.size());
	}
	cout << ans << endl;
}
/*
5
3 6
5 10
4 3
2 1
1 3
*/