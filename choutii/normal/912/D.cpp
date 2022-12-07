#include <bits/stdc++.h>

#define fir first
#define sec second
#define MP make_pair
#define PB push_back

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

int n, m, r, K;
LL E(int x, int y) {
	return (LL) (min(x, n - r + 1) - max(1, x - r + 1) + 1) * (min(y, m - r + 1) - max(1, y - r + 1) + 1);
}

priority_queue<pair<int, pair<int, int> > > q;
map<pair<int, int>, int> vis;
 
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int main() {
	int i;
	cin >> n >> m >> r >> K;
	q.push(MP(E(n + 1 >> 1, m + 1 >> 1), MP(n + 1 >> 1, m + 1 >> 1)));
	vis[q.top().sec] = 1;
	LL ans = 0; 
	while(K--) {
		pair<int, pair<int, int> > c = q.top(); q.pop(); ans += c.fir;
		int x = c.sec.fir, y = c.sec.sec;
		for(int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if(!vis[MP(nx, ny)]) {
				vis[MP(nx, ny)] = 1;
				q.push(MP(E(nx, ny), MP(nx, ny)));
			}
		}
	}
	printf("%.10lf", ans / (double) (n - r + 1) / (m - r + 1));
	return 0;
}