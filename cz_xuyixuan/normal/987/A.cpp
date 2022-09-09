#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
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
set <char> st;
int main() {
	int n; read(n);
	for (int i = 1; i <= n; i++) {
		char s[15];
		scanf("\n%s", s);
		st.insert(s[0]);
	}
	printf("%d\n", 6 - n);
	if (st.count('p') == 0) printf("Power\n");
	if (st.count('g') == 0) printf("Time\n");
	if (st.count('b') == 0) printf("Space\n");
	if (st.count('o') == 0) printf("Soul\n");
	if (st.count('r') == 0) printf("Reality\n");
	if (st.count('y') == 0) printf("Mind\n");
	return 0;
}