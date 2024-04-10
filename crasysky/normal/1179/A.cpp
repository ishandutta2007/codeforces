#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <deque>
#include <set>
#define Pr pair <int, int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int INF = 1e9 + 9;
const int maxn = 1e6 + 6;
deque <int> q;
int a[maxn][2], b[maxn][2];
long long read(){
	long long c = 0, f = 1; char ch = getchar();
	while (ch != '-' && (ch < '0' || '9' < ch)) ch = getchar();
	if (ch == '-') f = -1, ch = getchar();
	while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
	return c * f;
}
int main(){
	int n = read(), m = read();
	for (int i = 1; i <= n; ++ i){
		int x = read();
		q.push_back(x);
	}
	for (int i = 1; i <= n; ++ i){
		int x = q.front(); q.pop_front();
		int y = q.front(); q.pop_front();
		a[i][0] = x, a[i][1] = y;
		q.push_front(max(x, y));
		q.push_back(min(x, y));
	}
	for (int i = 1; i <= n - 1; ++ i){
		int x = q.front(); q.pop_front();
		int y = q.front(); q.pop_front();
		b[i % (n - 1)][0] = x, b[i % (n - 1)][1] = y;
		q.push_front(max(x, y));
		q.push_back(min(x, y));
	}
	while (m --){
		long long x = read();
		if (x <= n)
			printf("%d %d\n", a[x][0], a[x][1]);
		else
			printf("%d %d\n", b[(x - n) % (n - 1)][0], b[(x - n) % (n - 1)][1]);
	}
}