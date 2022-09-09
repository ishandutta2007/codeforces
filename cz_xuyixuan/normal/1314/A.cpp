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
int n; ll ans, sum;
pair <int, int> a[MAXN];
priority_queue <int> Heap;
int main() {
	read(n);
	for (int i = 1; i <= n; i++)
		read(a[i].first);
	for (int i = 1; i <= n; i++)
		read(a[i].second);
	sort(a + 1, a + n + 1);
	int cur = 0;
	for (int i = 1; i <= n; i++) {
		while (cur < a[i].first && Heap.size()) {
			ans += sum - Heap.top();
			sum -= Heap.top();
			Heap.pop();
			cur++;
		}
		cur = a[i].first;
		sum += a[i].second;
		Heap.push(a[i].second);
	}
	while (Heap.size()) {
		ans += sum - Heap.top();
		sum -= Heap.top();
		Heap.pop();
	}
	cout << ans << endl;
	return 0;
}