#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
using namespace std;
#pragma warning(disable:4996)
long long n, k, a[1000005], s, ct, G[30000000];
void pb(pair<int, int>F) {
	G[F.first] += F.second;
}
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]); vector<long long>P, Q; P.push_back(a[i]); Q.push_back(a[i]);
		if (a[i] == 1) { pb(make_pair(1, 1)); continue; }

		while (P[P.size() - 1] > 1) { P.push_back(P[P.size() - 1] / 2); }
		while (Q[Q.size() - 1] > 1) { Q.push_back((Q[Q.size() - 1] + 1) / 2); }

		long long H = 1, S = 0;
		for (int j = 0; j < P.size() - 1; j++) {
			if (H - S >= 1) { pb(make_pair(P[j], H - S)); S = H; }

			if (j >= 1 && Q[j] % 2 == 0) {
				long long W = P[j] * H;
				long long I = S + (a[i] - W);
				if (I - S >= 1) { pb(make_pair(P[j + 1] + 1, I - S)); S = I; }
			}

			H *= 2;
		}
		pb(make_pair(1, a[i] - S));
	}
	for (int i = 20000000; i >= 0; i--) {
		s += G[i]; if (s >= k) { cout << i << endl; break; }
	}
	if (s < k) cout << "-1" << endl;
	return 0;
}