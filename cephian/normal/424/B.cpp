#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cctype>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>

using namespace std;
typedef long long ll;
const int TGT = 1000000;
const double INF = 1000000000000000;
const double EPS = 1e-14;
int n;
ll s;
vector<pair<double,ll> > v;

double mag(double x, double y) {
	return sqrt(x*x + y*y);
}

int main() {
	ios::sync_with_stdio(0);
	cin >> n >> s;
	if(s >= TGT) {
		cout << "0\n";
		return 0;
	}
	for(int i = 0; i < n; ++i) {
		double x,y;
		ll k;
		cin >> x >> y >> k;
		v.push_back(pair<double,ll>(mag(x,y), k));
	}
	sort(v.begin(),v.end());
	cout << setprecision(12) << fixed;
	for(int i = 0; i < n; ++i) {
		s += v[i].second;
		if(s >= TGT) {
			cout << v[i].first << "\n";
			return 0;
		}
	}
	cout << "-1\n";
}