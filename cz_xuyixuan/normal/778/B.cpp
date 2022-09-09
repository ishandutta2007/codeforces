#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5005;
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
int n, m, now[MAXN];
int x[MAXN], y[MAXN];
string name, rubbish, Min, Max;
string opt[MAXN], val[MAXN];
map <string, int> num;
int main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++) {
		cin >> name;
		num[name] = i;
		cin >> rubbish;
		cin >> val[i];
		if (val[i][0] == '0' || val[i][0] == '1') continue;
		else {
			x[i] = num[val[i]];
			cin >> opt[i];
			cin >> rubbish;
			y[i] = num[rubbish];
		}
	}
	for (int j = 0; j < m; j++) {
		int sumz = 0, sumo = 0;
		now[0] = 0;
		for (int i = 1; i <= n; i++) {
			if (opt[i] == "OR") now[i] = now[x[i]] | now[y[i]];
			else if (opt[i] == "AND") now[i] = now[x[i]] & now[y[i]];
			else if (opt[i] == "XOR") now[i] = now[x[i]] ^ now[y[i]];
			else now[i] = val[i][j] - '0';
			sumz += now[i];
		}
		now[0] = 1;
		for (int i = 1; i <= n; i++) {
			if (opt[i] == "OR") now[i] = now[x[i]] | now[y[i]];
			else if (opt[i] == "AND") now[i] = now[x[i]] & now[y[i]];
			else if (opt[i] == "XOR") now[i] = now[x[i]] ^ now[y[i]];
			else now[i] = val[i][j] - '0';
			sumo += now[i];
		}
		if (sumz <= sumo) Min += '0';
		else Min += '1';
		if (sumz >= sumo) Max += '0';
		else Max += '1';
	}
	cout << Min << endl;
	cout << Max << endl;
	return 0;
}