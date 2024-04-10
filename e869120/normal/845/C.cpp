#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<functional>
#include<algorithm>
#include<queue>
using namespace std;
int n, l[200000], r[200000], s1 = -1, s2 = -1; vector<pair<int, int>>D;
int main() {
	cin >> n; for (int i = 0; i < n; i++) { cin >> l[i] >> r[i]; l[i] *= 2; r[i] *= 2; r[i] += 1; }
	for (int i = 0; i < n; i++)D.push_back(make_pair(l[i], r[i]));
	sort(D.begin(), D.end());
	for (int i = 0; i < D.size(); i++) {
		if (s1 < D[i].first) { s1 = D[i].second; }
		else if (s2 < D[i].first) { s2 = D[i].second; }
		else { cout << "NO" << endl; return 0; }
	}
	cout << "YES" << endl;
	return 0;
}