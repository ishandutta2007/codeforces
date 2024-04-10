#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cout << setprecision(12) << fixed;
	int n;
	cin >> n;
	vector<double> p(n);
	for(int i = 0; i < n; ++i)
		cin >> p[i];
	sort(p.rbegin(),p.rend());
	double A = 0, B = 1;
	double best = 0;
	for(double q : p) {
		if(q > .999999999) {
			best = 1;
			break;
		}
		B *= 1-q;
		A += q/(1-q);
		best = max(best, A * B);
	}
	cout << best << "\n";
	
}