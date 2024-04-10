#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

long long N, A, B, X[200009], Y[200009], s, rem; vector<pair<long long, int>>J; bool used[200009];

int main() {
	cin >> N >> A >> B;
	for (int i = 1; i <= N; i++) {
		scanf("%lld%lld", &X[i], &Y[i]); rem += Y[i];
		J.push_back(make_pair(X[i] - Y[i], i));
	}
	if (B == 0) { cout << rem << endl; return 0; }
	sort(J.begin(), J.end()); reverse(J.begin(), J.end());

	int D = -1;
	for (int i = 0; i < J.size(); i++) {
		if (i < B && J[i].first > 0) { D = i; s += J[i].first; used[J[i].second] = true; }
	}
	long long E = 0; if (D >= 0) E = J[D].first;

	long long maxn = rem + s;

	for (int i = 1; i <= N; i++) {
		if (used[i] == true) {
			long long T = (X[i] << A) - X[i];
			maxn = max(maxn, rem + s + T);
		}
		else {
			long long T = (X[i] << A) - Y[i], F = E; if (B > D + 1) F = 0;
			maxn = max(maxn, rem + s - F + T);
		}
	}
	cout << maxn << endl;
	return 0;
}