#include <bits/stdc++.h>
#define print(x) cerr << #x << " = " << x << endl;
using namespace std;
typedef long long ll;

vector<int> v;

const int N = 3e5+5;

int next_geq(int i, int x) {
	if(i == (int)v.size()-1) return -1;
	if(v.back() < x) return -1;
	int lo = i, hi = v.size()-1;
	while(hi-lo-1) {
		int md = (lo+hi)/2;
		if(v[md] >= x) hi = md;
		else lo = md;
	}
	return hi;
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	map<int,int> m;
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		++m[a];
	}
	for(auto x : m) {
		v.push_back(x.second);
	}
	sort(v.begin(), v.end());

	int best = 0;
	for(int st = 1; st <= n; ++st) {
		int val = st, ind = -1;
		int ans = 0;
		while(true) {
			ind = next_geq(ind, val);
			if(ind == -1) break;
			ans += val;
			val *= 2;
		}
		best = max(best, ans);
	}
	cout << best << "\n";
}