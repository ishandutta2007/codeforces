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

const int MaxN = 1234;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n, m, K, x1, y1, x2, y2; char mp[MaxN][MaxN];
int dis[MaxN][MaxN];

int bfs() {
	if(x1 == x2 && y1 == y2) return puts("0"), 0;	
	queue<pair<int, int> > q;
	q.push(make_pair(x1, y1));
	memset(dis, -1, sizeof(dis));
	dis[x1][y1] = 0;
	while(!q.empty()) {
		int x = q.front().fir, y = q.front().sec; q.pop();
		for(int i = 0; i < 4; i++)
			for(int j = 1; j <= K; j++) {
				int nx = x + j * dx[i];
				int ny = y + j * dy[i];
				if(nx > n || nx < 1 || ny > m || ny < 1 || mp[nx][ny] == '#') break;
				if(! ~dis[nx][ny]) {
					dis[nx][ny] = dis[x][y] + 1;
					q.push(make_pair(nx, ny));
					if(nx == x2 && ny == y2) 
						return printf("%d", dis[nx][ny]), 0; 
				}
			}
	}
	return puts("-1"), 0;
}
int main() {
	int i;
	n = read(); m = read(); K = read();
	for(i = 1; i <= n; i++)
		scanf("%s", mp[i] + 1);
	x1 = read(); y1 = read(); x2 = read(); y2 = read();
	bfs();
	return 0;
}