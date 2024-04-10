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
string s;
int n, a[maxn], ans[maxn], tmp[maxn];
bool check(int x){
	int s1 = 0, s2 = 0;
	for (int i = 1; i <= n; ++ i){
		if (a[i] == 1){
			if (s1 < x)
				++ s1, tmp[i] = 1;
			else
				++ s2, tmp[i] = 0;
		}
		else{
			if (s1)
				-- s1, tmp[i] = 1;
			else
				-- s2, tmp[i] = 0;
		}
		if (s2 < 0 || s2 > x)
			return false;
	}
	for (int i = 1; i <= n; ++ i)
		ans[i] = tmp[i];
	return true;
}
int read(){
	int c = 0, f = 1; char ch = getchar();
	while (ch != '-' && (ch < '0' || '9' < ch)) ch = getchar();
	if (ch == '-') f = -1, ch = getchar();
	while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
	return c * f;
}
int main(){
	n = read();
	cin >> s;
	for (int i = 1; i <= n; ++ i)
		a[i] = s[i - 1] == '(' ? 1 : -1;
	int l = 1, r = n / 2;
	while (l <= r){
		int m = l + r >> 1;
		if (check(m))
			r = m - 1;
		else
			l = m + 1;
	}
	for (int i = 1; i <= n; ++ i)
		printf("%d", ans[i]);
}