#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

struct Node {
	long long l, r, a, b;
};

bool operator<(const Node &a1, const Node &a2) {
	if (a1.l < a2.l) return true;
	if (a1.l > a2.l) return false;
	if (a1.r < a2.r) return true;
	if (a1.r > a2.r) return false;
	return false;
}

class ConvexHullTrick {
public:
	vector<Node> E;

	void init() {
		E.push_back(Node{ -(1LL << 61),(1LL << 61), -(1LL << 25), (1LL << 60) });
	}
	long long cross_point(Node A, Node B) {
		if (A.a == B.a) {
			if (A.b < B.b) return (1LL << 60);
			return -(1LL << 60);
		}
		// B 
		long long PB = B.b, PA = A.b + (B.a - A.a) * (B.a - A.a);
		if (PB >= PA) {
			long long E = (PB - PA) / (2LL * (B.a - A.a));
			return B.a + E;
		}
		else {
			long long E = (PA - PB) / (2LL * (B.a - A.a)); E *= -1LL;
			return B.a + (E - 1LL);
		}
	}
	void add(long long pa, long long pb) {
		while (E.size() >= 1) {
			long long F = cross_point(E[E.size() - 1], Node{ 0LL, 0LL, pa, pb });
			if (E[E.size() - 1].l > F) {
				E.pop_back();
			}
			else {
				E[E.size() - 1].r = F;
				E.push_back(Node{ F + 1LL, (1LL << 61), pa, pb });
				break;
			}
		}
	}
	long long get_val(long long pos) {
		int pos1 = lower_bound(E.begin(), E.end(), Node{ pos, (1LL << 62), 0LL, 0LL }) - E.begin(); pos1--;
		return E[pos1].b + (E[pos1].a - pos) * (E[pos1].a - pos);
	}
};

long long N, A[1 << 19], B[1 << 19], dp[1 << 19], rem[1 << 19], ans = (1LL << 60);
vector<int>G[1 << 19], X[1 << 19];
bool used[1 << 19];

void dfs(int pos) {
	used[pos] = true; dp[pos] += 1;
	for (int i = 0; i < G[pos].size(); i++) {
		if (used[G[pos][i]] == true) continue;
		X[pos].push_back(G[pos][i]);
		dfs(G[pos][i]);
		dp[pos] += dp[G[pos][i]];
	}
}

void dfs2(int pos) {
	for (int i = 0; i < X[pos].size(); i++) dfs2(X[pos][i]);
	long long rems = dp[pos] * dp[pos];
	for (int i = 0; i < X[pos].size(); i++) {
		rems = min(rems, rem[X[pos][i]] + (dp[pos] - dp[X[pos][i]]) * (dp[pos] - dp[X[pos][i]]));
	}
	rem[pos] = rems;
}

void dfs3(int pos) {
	for (int i = 0; i < X[pos].size(); i++) dfs3(X[pos][i]);
	
	vector<pair<long long, long long>>vec;
	for (int i = 0; i < X[pos].size(); i++) vec.push_back(make_pair(dp[X[pos][i]], rem[X[pos][i]]));
	sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i++) {
		ans = min(ans, 1LL * (N - vec[i].first) * (N - vec[i].first) + 1LL * vec[i].second);
	}

	ConvexHullTrick Z; Z.init();
	for (int i = 0; i < vec.size(); i++) {
		long long P = Z.get_val(-vec[i].first); ans = min(ans, P + vec[i].second);
		Z.add(vec[i].first - N, vec[i].second);
	}
}

int main() {
	scanf("%lld", &N);
	for (int i = 1; i <= N - 1; i++) {
		scanf("%lld%lld", &A[i], &B[i]);
		G[A[i]].push_back(B[i]);
		G[B[i]].push_back(A[i]);
	}
	dfs(1);
	dfs2(1);
	dfs3(1);
	cout << N * (N - 1LL) / 2LL + (N * N - ans) / 2LL << endl;
	return 0;
}