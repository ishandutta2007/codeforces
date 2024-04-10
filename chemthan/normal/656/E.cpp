#include <bits/stdc++.h>
using namespace std;

template<class T> inline int chkmin(T& a, const T& val) {return a > val ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}

const int maxn = 20;
int n;
int a[maxn][maxn];
int ans;

void input(int i, int j) {
	cin>>a[i][j];
	j < n - 1 ? input(i, j + 1) : void();
	(i < n - 1 && j == n - 1) ? input(i + 1, 0) : void();
}

void floyd(int i, int j, int k) {
	chkmin(a[j][k], a[j][i] + a[i][k]);
	(k < n - 1) ? floyd(i, j, k + 1) : void();
	(k == n - 1 && j < n - 1) ? floyd(i, j + 1, 0) : void();
	(k == n - 1 && i < n - 1 && j == n - 1) ? floyd(i + 1, 0, 0) : void();
}

void get(int i, int j) {
	chkmax(ans, a[i][j]);
	j < n - 1 ? get(i, j + 1) : void();
	(i < n - 1 && j == n - 1) ? get(i + 1, 0) : void();
}

void solve() {
	cin>>n;
	input(0, 0);
	floyd(0, 0, 0);
	get(0, 0);
	cout<<ans<<"\n";
}

int main() {
	solve();
	return 0;
}