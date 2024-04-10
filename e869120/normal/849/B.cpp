#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int n;long double a[100009];
bool solve(long double p, long double q) {
	vector<pair<long double, long double>>Z;
	for (int i = 0; i < n; i++) {
		long double I = a[i] - 1.0L*i*p;
		if (abs(I - q) >= 1e-13)Z.push_back(make_pair(i, a[i]));
	}
	if (Z.size() == 0)return false;
	if (Z.size() == 1)return true;
	long double X = (Z[1].second - Z[0].second) / (Z[1].first - Z[0].first);
	long double Y = Z[0].second - Z[0].first*X; if (abs(p - X) >= 1e-13)return false;
	for (int i = 0; i < Z.size(); i++) {
		long double I = Z[i].first*X + Y;
		if (abs(I - Z[i].second) >= 1e-13)return false;
	}
	return true;
}
int main() {
	cin >> n; for (int i = 0; i < n; i++)cin >> a[i];
	bool p1 = solve(a[1] - a[0], a[0]);
	bool p2 = solve((a[2] - a[0]) / 2.0L, a[0]);
	bool p3 = solve(a[2] - a[1], a[1] - (a[2] - a[1]));
	if (p1 == true || p2 == true || p3 == true)cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}