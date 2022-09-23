#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;

int N, M;

struct Point {
	int x, y;
	int id;
}A[101010];

vector<pii> adj[101010];

priority_queue<pii, vector<pii>, greater<pii> > pq;
ll D[101010];

void f(int a, int b, int c) {
	adj[a].push_back(pii(b, c));
	adj[b].push_back(pii(a, c));
}

int main() {
	scanf("%d%d", &N, &M);
	scanf("%d%d", &A[1].x, &A[1].y);
	scanf("%d%d", &A[M + 2].x, &A[M + 2].y);
	M += 2;

	for(int i = 2; i < M; i++) scanf("%d%d", &A[i].x, &A[i].y);
	for(int i = 1; i <= M; i++) A[i].id = i;

	sort(A + 1, A + M, [&](const Point& a, const Point& b) {
		return a.x < b.x;
	});

	for(int i = 2; i < M; i++) {
		f(A[i - 1].id, A[i].id, A[i].x - A[i - 1].x);
	}

	sort(A + 1, A + M, [&](const Point& a, const Point& b) {
		return a.y < b.y;
	});

	for(int i = 2; i < M; i++) {
		f(A[i - 1].id, A[i].id, A[i].y - A[i - 1].y);
	}

	sort(A + 1, A + M, [&](const Point& a, const Point& b) {
		return a.id < b.id;
	});

	for(int i = 1; i < M; i++) {
		f(i, M, abs(A[M].x - A[i].x) + abs(A[M].y - A[i].y));
	}

	pq.emplace(0, 1);
	for(int i = 2; i <= M; i++) D[i] = (1LL) << 60;

	while(pq.size()) {
		ll d = pq.top().first;
		int x = pq.top().second;
		pq.pop();
		if(D[x] < d) continue;
		for(pii i : adj[x]) {
			if(D[i.first] > d + i.second) {
				D[i.first] = d + i.second;
				pq.push(pii(D[i.first], i.first));
			}
		}
	}

	printf("%lld\n", D[M]);

	return 0;
}