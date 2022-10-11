#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
#pragma warning (disable: 4996)

struct Node {
	long long l, r, a, b;
};

bool operator<(const Node &a1, const Node &a2) {
	if (a1.l < a2.l) return true;
	else if (a1.l == a2.l && a1.r < a2.r) return true;
	return false;
}

class ConvexHullTrick {
public:
	vector<Node>vec;

	long long cross_point(Node V1, Node V2) {
		//  V2  (y = a + bx)
		
		if (V1.a == V2.a) return 0;
		if (V1.a > V2.a) {
			long long S = (V1.a - V2.a) / (V2.b - V1.b);
			return S + 1LL;
		}
		if (V1.a < V2.a) {
			long long S = (V2.a - V1.a) / (V2.b - V1.b);
			return -S;
		}
	}

	void init() {
		vec.push_back(Node{ -(1LL << 61), (1LL << 61), -(1LL << 60), 0 });
	}

	void add(long long a, long long b) {
		while (true) {
			Node G = vec[vec.size() - 1];
			long long P = cross_point(G, Node{ 0LL, 0LL, a, b });

			if (P <= G.l) {
				vec.pop_back();
			}
			else {
				vec[vec.size() - 1].r = P - 1;
				vec.push_back(Node{ P, (1LL << 61), a, b });
				break;
			}
		}
	}

	long long getans(long long x) {
		int pos1 = lower_bound(vec.begin(), vec.end(), Node{ x, (1LL << 62), -1LL, -1LL }) - vec.begin();
		pos1--;
		return vec[pos1].a + vec[pos1].b * x;
	}
};

long long solve_1(long long N, vector<long long>X, vector<long long>Y, vector<long long>A) {
	vector<tuple<long long, long long, long long>>vec;
	for (int i = 0; i < N; i++) vec.push_back(make_tuple(X[i], Y[i], A[i]));
	sort(vec.begin(), vec.end());
	for (int i = 0; i < N; i++) { X[i] = get<0>(vec[i]); Y[i] = get<1>(vec[i]); A[i] = get<2>(vec[i]); }

	ConvexHullTrick Z; vector<long long>dp(N + 1, 0);
	Z.init();
	for (int i = 0; i < N; i++) {
		long long E1 = X[i] * Y[i] - A[i];
		long long E2 = -(1LL << 60); if (i >= 1) E2 = Z.getans(-Y[i]) + X[i] * Y[i] - A[i];
		dp[i] = max(E1, E2);
		Z.add(dp[i], X[i]);
	}

	long long maxn = 0;
	for (int i = 0; i < N; i++) maxn = max(maxn, dp[i]);
	return maxn;
}

long long solve_Jury(long long N, vector<long long>X, vector<long long>Y, vector<long long>A) {
	long long maxn = 0;
	for (int i = 1; i < (1 << N); i++) {
		vector<long long>C(30, 0); long long ret = 0;
		for (int j = 0; j < N; j++) {
			if ((i / (1 << j)) % 2 == 1) { C[X[j] - 1] = max(C[X[j] - 1], Y[j]); ret -= A[j]; }
		}
		for (int j = 28; j >= 0; j--) C[j] = max(C[j], C[j + 1]);
		for (int j = 0; j <= 29; j++) ret += C[j];
		maxn = max(maxn, ret);
	}
	return maxn;
}

int main() {
	int Debug = 1;
	if (Debug == 1) {
		long long n, a, b, c; vector<long long>x, y, z;
		scanf("%lld", &n);
		for (int i = 0; i < n; i++) { scanf("%lld%lld%lld", &a, &b, &c); x.push_back(a); y.push_back(b); z.push_back(c); }
		cout << solve_1(n, x, y, z) << endl;
	}
	if (Debug == 2) {
		for (int t = 1; t <= 10000; t++) {
			long long n = 5; vector<long long>x, y, z;
			while (true) {
				x.clear(); y.clear(); z.clear();
				for (int j = 0; j < n; j++) x.push_back(rand() % 15 + 1);
				for (int j = 0; j < n; j++) y.push_back(rand() % 15 + 1);
				sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());
				sort(y.begin(), y.end()); y.erase(unique(y.begin(), y.end()), y.end()); reverse(y.begin(), y.end());

				if (x.size() == n && y.size() == n) {
					for (int j = 0; j < n; j++) z.push_back(rand() % (x[j] * y[j] + 1));
					break;
				}
			}

			long long V1 = solve_Jury(n, x, y, z);
			long long V2 = solve_1(n, x, y, z);

			if (V1 != V2) {
				cout << "Wrong Answer on Test #" << t << endl;
				cout << "Jury = " << V1 << ", Output = " << V2 << endl;
				cout << endl;
				cout << n << endl;
				for (int j = 0; j < n; j++) cout << x[j] << " " << y[j] << " " << z[j] << endl;
				cout << endl;
			}
		}
	}
	return 0;
}