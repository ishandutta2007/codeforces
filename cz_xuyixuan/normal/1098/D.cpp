#include<bits/stdc++.h>
using namespace std;
const int MAXLOG = 31;
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
struct Heap {
	int cnt; ll sum; priority_queue <int, vector <int>, greater <int> > Heap, Delt;
	void ins(int x) {
		cnt++, sum += x;
		Heap.push(x);
	}
	void del(int x) {
		cnt--, sum -= x;
		Delt.push(x);
	}
	int query() {
		while (!Heap.empty() && !Delt.empty() && Heap.top() == Delt.top()) {
			Heap.pop();
			Delt.pop();
		}
		if (Heap.empty()) return -1;
		else return Heap.top();
	}
} a[MAXLOG];
int main() {
	int n; read(n);
	for (int i = 1; i <= n; i++) {
		char c; int x;
		scanf("\n%c %d", &c, &x);
		for (int i = 0; i < MAXLOG; i++)
			if (x <= (1 << i)) {
				if (c == '+') a[i].ins(x);
				else a[i].del(x);
				break;
			}
		int ans = 0; ll sum = 0;
		for (int i = 0; i < MAXLOG; i++) {
			ans += a[i].cnt;
			int tmp = a[i].query();
			if (tmp > 2 * sum) ans--;
			sum += a[i].sum;
		}
		writeln(ans);
	}
	return 0;
}