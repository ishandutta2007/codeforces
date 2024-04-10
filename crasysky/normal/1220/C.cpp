#include <iostream>
#include <cstdio>
#include <map>
#define fi first
#define se second
using namespace std;
const int maxn = 1000006;
int a[maxn], mn[maxn];
string s;
int read(){
	int c = 0; char ch = getchar();
	while (ch < '0' || '9' < ch) ch = getchar();
	while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
	return c;
}
int main(){
	cin >> s;
	int n = s.length();
	for (int i = 1; i <= n; ++ i)
		a[i] = s[i - 1];
	mn[1] = a[1];
	for (int i = 2; i <= n; ++ i)
		mn[i] = min(mn[i - 1], a[i]);
	for (int i = 1; i <= n; ++ i)
		if (mn[i] < a[i])
			puts("Ann");
		else
			puts("Mike");
}