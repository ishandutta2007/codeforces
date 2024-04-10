#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> h[101010];
vector<int> v[101010];

int x1, x2, y1, y2;
int N, M, K;
ll cnt = 1;

void f(int d) {
	int x = 1, y = 1;
	int bx = 1, by = 1;
	x1 = 1; y1 = 0; x2 = N + 1; y2 = M + 1;
	while(1) {
		d = d + 1 & 3;
		if(d == 0) {
			auto it = lower_bound(h[x].begin(), h[x].end(), y);
			int ny;
			if(it == h[x].end()) ny = y2 - 1;
			else ny = min((*it), y2) - 1;
			cnt += ny - y;
			y = ny;
			y2 = ny;
		}
		else if(d == 1) {
			auto it = lower_bound(v[y].begin(), v[y].end(), x);
			int nx;
			if(it == v[y].end()) nx = x2 - 1;
			else nx = min((*it), x2) - 1;
			cnt += nx - x;
			x = nx;
			x2 = nx;
		}
		else if(d == 2) {
			auto it = lower_bound(h[x].begin(), h[x].end(), y);
			int ny;
			if(it == h[x].begin()) ny = y1 + 1;
			else { it--; ny = max((*it), y1) + 1; }
			cnt += y - ny;
			y = ny;
			y1 = ny;
		}
		else {
			auto it = lower_bound(v[y].begin(), v[y].end(), x);
			int nx;
			if(it == v[y].begin()) nx = x1 + 1;
			else { it--; nx = max((*it), x1) + 1; }
			cnt += x - nx;
			x = nx;
			x1 = nx;
		}
		if(x == bx && y == by) break;
		bx = x; by = y;
	}
}

int main() {
	scanf("%d%d%d", &N, &M, &K);
	for(int i = 1; i <= K; i++) {
		int x, y; scanf("%d%d", &x, &y);
		h[x].push_back(y);
		v[y].push_back(x);
	}

	for(int i = 1; i <= N; i++) sort(h[i].begin(), h[i].end());
	for(int i = 1; i <= M; i++) sort(v[i].begin(), v[i].end());

	f(3);

	if(cnt + K == (ll)N * M) { puts("Yes"); return 0; }

	cnt = 1;
	f(0);

	if(cnt + K == (ll)N * M) { puts("Yes"); return 0; }
	puts("No");

	return 0;
}