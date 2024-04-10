#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
using namespace std;
int n, m, a[200000], b[200000], c[200000], d[200000], L = 1, S = 0; vector<pair<int, int>>C; vector<tuple<int, int, int>>vec;
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) { cin >> a[i] >> b[i]; vec.push_back(make_tuple(a[i], 1 - b[i], i)); }
	for (int i = 0; i < 1000; i++) { for (int j = 0; j < i - 1; j++) { C.push_back(make_pair(j + 1, i + 1)); } }
	sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i++) {
		if (get<1>(vec[i]) == 0) { L++; c[get<2>(vec[i])] = L - 1; d[get<2>(vec[i])] = L; }
		if (get<1>(vec[i]) == 1) { c[get<2>(vec[i])] = C[S].first; d[get<2>(vec[i])] = C[S].second; if (C[S].first > L || C[S].second > L) { cout << "-1" << endl; return 0; }S++; }
	}
	for (int i = 0; i < m; i++)printf("%d %d\n", c[i], d[i]);
	return 0;
}