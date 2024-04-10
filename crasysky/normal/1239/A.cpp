#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <set>
#define Pr pair <int, int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int P = 1e9 + 7;
const int maxn = 1e6 + 6;
int f[maxn], g[maxn];
int read(){
	int c = 0, f = 1; char ch = getchar();
	while (ch != '-' || (ch < '0' || '9' < ch)) ch = getchar();
	if (ch == '-') f = -1, ch = getchar();
	while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
	return c * f;
}
int main(){
	int n, m;
	cin >> n >> m;
	f[1] = 2, f[2] = 4;
	for (int i = 3; i <= max(n, m); ++ i)
		f[i] = (f[i - 1] + f[i - 2]) % P;
	cout << (1LL * f[n] + f[m] - 2 + P) % P << endl;
}