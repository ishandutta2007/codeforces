//==================DP=============
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, a[10000]; vector<pair<pair<long long, long long>, long long>>U; long long minv = 0;
void add(long long I) {
	long long G = (1LL << 60);
	for (int i = 0; i < U.size(); i++) {
		if (U[i].second >= 0)G = min(G, U[i].first.first);
	}
	I--;
	if (I < G)minv += (G - I);
	vector<pair<pair<long long, long long>, long long>>V;
	for (int i = 0; i < U.size(); i++) {
		if (U[i].first.first + 1 <= I && I <= U[i].first.second) {
			V.push_back(make_pair(make_pair(U[i].first.first + 1, I), min(-1LL, U[i].second - 1)));
			V.push_back(make_pair(make_pair(I + 1, U[i].first.second + 1), min(1LL, U[i].second + 1)));
		}
		else if (I <= U[i].first.first) {
			V.push_back(make_pair(make_pair(U[i].first.first + 1, U[i].first.second + 1), min(1LL, U[i].second + 1)));
		}
		else {
			V.push_back(make_pair(make_pair(U[i].first.first + 1, U[i].first.second + 1), min(-1LL, U[i].second - 1)));
		}
	}
	for (int i = 0; i < V.size(); i++)V[i].second = min(V[i].second, 1LL);
	U = V;
}
int main() {
	cin >> n; for (int i = 0; i < n; i++)cin >> a[i];
	U.push_back(make_pair(make_pair(-(1LL << 40), (1LL << 40)), 0LL));
	for (int i = 0; i < n; i++) add(a[i]);
	cout << minv << endl;
	return 0;
}