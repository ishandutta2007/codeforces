#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; ++i) cin >> a[i];
	for(int i = 0; i < n; ++i) cin >> b[i];

	double lo = 0;
	double hi = 1e9;
	for(int T = 0; T < 64; ++T) {
		double md = (lo+hi)/2;
		//md = 1;
		map<int, vector<double>> data;
		vector<pair<int,vector<double>>> v;

		for(int i = 0; i < n; ++i)
			data[a[i]].push_back(a[i] - md*b[i]);
		for(auto x : data) {
			v.push_back(x);
			sort(v.back().second.begin(), v.back().second.end());
		}

		vector<vector<double>> best(v.size()+1, vector<double>(n+1));
		for(int i = 0; i < n+1; ++i) 
			best[v.size()][i] = 1e60;
		best[v.size()][0] = 0;
		for(int i = (int)v.size()-1; i >= 0; --i) {
			for(int free = 0; free < n+1; ++free) {
				best[i][free] = 1e60;
				double keep_sum = 0;
				for(int keep = 0; keep <= (int)v[i].second.size(); ++keep) {
					const int take = ((int)v[i].second.size() - keep);
					const int old_free = free - keep + take;
					if(old_free - take < 0) continue;
					if(keep) keep_sum += v[i].second[keep-1];
					if(old_free < 0 || old_free > n) continue;
					best[i][free] = min(best[i][free], best[i+1][old_free] + keep_sum);
				}
			}
		}
		double ans = 1e60;
		for(int i = 0; i < n+1; ++i)
			ans = min(ans, best[0][i]);
		if(ans <= 0) hi = md;
		else lo = md;
	}
	cout << fixed << setprecision(12) ;
	cout << (ll)ceil(lo*1000) << "\n";
}