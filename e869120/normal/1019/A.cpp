#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long n, m, p[3009], c[3009], minx = (1LL << 60); vector<int>vec[3009];

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> p[i] >> c[i];
		vec[p[i]].push_back(c[i]);
	}
	for (int i = 1; i <= m; i++) sort(vec[i].begin(), vec[i].end());
	for (int i = 1; i <= n; i++) {
		long long sum = 0, cx = i; vector<int>v;
		for (int j = 2; j <= m; j++) {
			int S = ((int)vec[j].size() - (i - 1)); S = max(S, 0);
			for (int k = 0; k < S; k++) { sum += vec[j][k]; cx--; }
			for (int k = S; k < vec[j].size(); k++) v.push_back(vec[j][k]);
		}
		sort(v.begin(), v.end());
		for (int j = 0; j < cx - (int)vec[1].size(); j++) sum += v[j];
		minx = min(minx, sum);
	}
	cout << minx << endl;
	return 0;
}