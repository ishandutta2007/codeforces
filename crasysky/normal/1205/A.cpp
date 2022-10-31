#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#define Pr pair <int, int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int INF = 1e9;
const int maxn = 1e6 + 6;
int a[maxn];
int read(){
	int c = 0, f = 1; char ch = getchar();
	while (ch != '-' && (ch < '0' || '9' < ch)) ch = getchar();
	if (ch == '-') f = -1, ch = getchar();
	while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
	return c * f;
}
int main(){
	int n = 2 * read();
	if ((n * n + n) / 2 % 2 == 0){
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	int m = 0;
	for (int i = 1; i <= n; ++ i)
		if (i % 4 == 0 || i % 4 == 1)
			a[++ m] = i;
	for (int i = 1; i <= n; ++ i)
		if (i % 4 == 2 || i % 4 == 3)
			a[++ m] = i;
	for (int i = 1; i <= n; ++ i)
		cout << a[i] << " ";
	cout << endl;
}