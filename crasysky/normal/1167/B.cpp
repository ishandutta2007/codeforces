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
int a[10][10], ans[100], can[100];
int p[6] = {4, 8, 15, 16, 23, 42};
int read(){
	int c = 0, f = 1; char ch = getchar();
	while (ch != '-' && (ch < '0' || '9' < ch)) ch = getchar();
	if (ch == '-') f = -1, ch = getchar();
	while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
	return c * f;
}
int q(int x, int y){
	cout << "? " << x << " " << y << endl;
	fflush(stdout); a[x][y] =  read();
}
int main(){
	q(1, 2), q(2, 3), q(4, 5), q(5, 6);
	for (int i = 0; i < 6; ++ i)
		can[p[i]] = true;
	for (int i = 0; i < 6; ++ i)
		if (a[1][2] % p[i] == 0 && a[2][3] % p[i] == 0){
			int x = a[1][2] / p[i], y = a[2][3] / p[i];
			if (can[x] && can[y] && x != p[i] && y != p[i] && x != y)
				ans[2] = p[i];	
		}
	ans[1] = a[1][2] / ans[2];
	ans[3] = a[2][3] / ans[2];
	for (int i = 0; i  < 6; ++ i)
		if (a[4][5] % p[i] == 0 && a[5][6] % p[i] == 0){
			int x = a[4][5] / p[i], y = a[5][6] / p[i];
			if (can[x] && can[y] && x != p[i] && y != p[i] && x != y)
				ans[5] = p[i];	
		}
	ans[4] = a[4][5] / ans[5];
	ans[6] = a[5][6] / ans[5];
	cout << "! ";
	for (int i = 1; i <= 6; ++ i)
		cout << ans[i] << " ";
	cout << endl;
	fflush(stdout);
}