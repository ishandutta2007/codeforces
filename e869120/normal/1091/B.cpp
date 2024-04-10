#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int N, X[1 << 18], Y[1 << 18], A[1 << 18], B[1 << 18]; map<pair<int, int>, int>Map, Map2;
vector<pair<int, int>>vec;

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> X[i] >> Y[i];
	for (int i = 1; i <= N; i++) { cin >> A[i] >> B[i]; Map[make_pair(A[i], B[i])] = i; }

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			vec.push_back(make_pair(X[i] + A[j], Y[i] + B[j]));
			Map2[make_pair(X[i] + A[j], Y[i] + B[j])]++;
		}
	}
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	for (int i = 0; i < vec.size(); i++) {
		if (Map2[vec[i]] < N) continue;

		vector<int>L;
		for (int j = 1; j <= N; j++) {
			int px = vec[i].first - X[j], py = vec[i].second - Y[j];
			int Z = Map[make_pair(px, py)];
			if (Z >= 1) L.push_back(Z);
		}
		sort(L.begin(), L.end());
		L.erase(unique(L.begin(), L.end()), L.end());

		if (L.size() == N) {
			cout << vec[i].first << " " << vec[i].second << endl;
			break;
		}
	}
	return 0;
}