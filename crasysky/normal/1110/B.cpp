#include <algorithm>
#include <iostream>
#include <cstdio>
#define mp make_pair
#define fi first
#define se second
using namespace std;
int a[1000006], b[1000006];
int read(){
	int cnt = 0;
	char ch = getchar();
	while (ch < '0' || '9' < ch)
		ch = getchar();
	while ('0' <= ch && ch <= '9'){
		cnt = cnt * 10 + ch - '0';
		ch = getchar();
	}
	return cnt;
}
int main(){
	int n = read(), m = read(), k = read() - 1;
	for (int i = 1; i <= n; ++ i)
		a[i] = read();
	for (int i = 1; i < n; ++ i)
		b[i] = a[i + 1] - a[i] - 1;
	int ans = a[n] - a[1] + 1;
	sort(b + 1, b + n);
	for (int i = n - 1; i >= n - k; -- i)
		ans -= b[i];
	cout << ans << endl;
}