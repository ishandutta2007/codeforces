#include <bits/stdc++.h>

#define fir first
#define sec second
using namespace std;
typedef long long LL;
typedef unsigned long long u64;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}
int read() {
	int x = 0, f = 1;char ch;
	for(ch = getchar(); !isdigit(ch); ch = getchar())
		if(ch == '-') f = -1;
	for(; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return x * f;
}

const int MaxN = 301234;

int n, p[MaxN];

int main() {
	int i;
	n = read();
	for(i = 1; i <= n; i++) p[i] = read();
	LL ans = 0;
	priority_queue<int, vector<int>, greater<int> > q;
	for(i = 1; i <= n; i++) {
		q.push(p[i]);
		if(!q.empty() && q.top() < p[i]) {
			int c = q.top(); q.pop();
			ans += p[i] - c;
			q.push(p[i]);
		}
	}
	cout << ans << endl;
	return 0;
}