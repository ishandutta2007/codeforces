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
long long delta, a[MAXN], t[MAXN];
priority_queue <long long, vector <long long>, greater<long long> > Heap;
int main() {
	int n; read(n);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	for (int i = 1; i <= n; i++)
		read(t[i]);
	for (int i = 1; i <= n; i++) {
		Heap.push(a[i] + delta);
		delta += t[i];
		long long ans = 0;
		while (!Heap.empty() && Heap.top() <= delta) {
			long long tmp = Heap.top();
			Heap.pop(); ans += tmp - (delta - t[i]);
		}
		ans += Heap.size() * t[i];
		printf("%I64d ", ans);
	}
	return 0;
}