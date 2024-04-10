#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T> void write(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> void writeln(T x) {
	write(x);
	puts("");
}
int n, a[MAXN], b[MAXN];
vector <int> inc, dec;
bool cmp(int x, int y) {
	return a[x] > a[y];
}
bool cnp(int x, int y) {
	return b[x] < b[y];
}
int main() {
	read(n);
	vector <int> inc, dec;
	for (int i = 1; i <= n; i++) {
		read(a[i]), read(b[i]);
		if (a[i] < b[i]) inc.push_back(i);
		else dec.push_back(i);
	}
	if (inc.size() > dec.size()) {
		writeln(inc.size());
		sort(inc.begin(), inc.end(), cmp);
		for (auto x : inc)
			printf("%d ", x);
		printf("\n");
	} else {
		writeln(dec.size());
		sort(dec.begin(), dec.end(), cnp);
		for (auto x : dec)
			printf("%d ", x);
		printf("\n");
	}
	return 0;
}