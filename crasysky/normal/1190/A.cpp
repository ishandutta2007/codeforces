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
const int maxn = 2000006;
const int INF = 1e9;
long long a[maxn];
long long read(){
	long long c = 0; char ch = getchar();
	while (ch < '0' || '9' < ch) ch = getchar();
	while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
	return c;
}
int main(){
	long long n = read();
	int m = read();
	long long k = read();
	for (int i = 1; i <= m; ++ i)
		a[i] = read();
	int ans = 0;
	for (int i = 1; i <= m; ){
		++ ans;
		int t = i - 1;
		long long x = a[i] - t;
		long long r = (x + k - 1) / k * k;
		while (i <= m && a[i] - t <= r)
			++ i;
	}
	cout << ans << endl;
}