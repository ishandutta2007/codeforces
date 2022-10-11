#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

long long n, a[150009]; vector<long long>vec;
map<long long, vector<long long>>M;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i]; M[a[i]].push_back(i);
		for (int j = 0; j < 20; j++) vec.push_back((1LL << j)*a[i]);
	}
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	for (int i = 0; i < vec.size(); i++) {
		vector<long long>J = M[vec[i]]; sort(J.begin(), J.end());
		if (J.size() == 0) continue;
		for (int j = 0; j < (int)J.size() - 1; j += 2) {
			a[J[j]] = -1; a[J[j + 1]] = vec[i] * 2LL;
			M[vec[i] * 2LL].push_back(J[j + 1]);
		}
	}
	vector<long long>ans;
	for (int i = 1; i <= n; i++) {
		if (a[i] >= 1) ans.push_back(a[i]);
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) { if (i)cout << " "; cout << ans[i]; } cout << endl;
	return 0;
}