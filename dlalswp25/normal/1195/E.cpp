#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int H[3030][3030];
int tmp[3030][3030];

int N, M, A, B;
ll X, Y, Z, G;

deque<pii> dq;

int main() {
	scanf("%d%d%d%d", &N, &M, &A, &B);
	scanf("%lld%lld%lld%lld", &G, &X, &Y, &Z);
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			H[i][j] = G;
			G = G * X + Y;
			G %= Z;
		}
	}

	for(int j = 1; j <= M; j++) {
		while(dq.size()) dq.pop_back();

		for(int i = 1; i <= A; i++) {
			while(dq.size() && dq.back().first >= H[i][j]) dq.pop_back();
			dq.push_back({H[i][j], i});
		}

		for(int i = 1; i <= N - A + 1; i++) {
			tmp[i][j] = dq.front().first;
			while(dq.size() && dq.front().second <= i) dq.pop_front();

			if(i == N - A + 1) break;

			while(dq.size() && dq.back().first >= H[i + A][j]) dq.pop_back();
			dq.push_back({H[i + A][j], i + A});	
		}
	}

	for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++) {
		H[i][j] = tmp[i][j];
	}

	for(int i = 1; i <= N - A + 1; i++) {
		while(dq.size()) dq.pop_back();

		for(int j = 1; j <= B; j++) {
			while(dq.size() && dq.back().first >= H[i][j]) dq.pop_back();
			dq.push_back({H[i][j], j});
		}

		for(int j = 1; j <= M - B + 1; j++) {
			tmp[i][j] = dq.front().first;
			while(dq.size() && dq.front().second <= j) dq.pop_front();

			if(j == M - B + 1) break;

			while(dq.size() && dq.back().first >= H[i][j + B]) dq.pop_back();
			dq.push_back({H[i][j + B], j + B});
		}
	}

	ll ans = 0;
	for(int i = 1; i <= N - A + 1; i++) {
		for(int j = 1; j <= M - B + 1; j++) {
			ans += tmp[i][j];
		}
	}
	printf("%lld\n", ans);

	return 0;
}