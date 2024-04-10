#include <bits/stdc++.h>
#define print(x) cerr << #x << " = " << x << endl;
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n, k;
	cin >> n >> k;
	map<int,int> f;
	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		++f[a];
	}
	int lo = 1, hi = n+1;
	while(hi-lo-1) {
		int md = (lo+hi)/2;
		int max_len = 0;
		for(auto x : f) {
			max_len += x.second / md;
		}
		if(max_len < k) hi = md;
		else lo = md;
	}

	vector<int> ans;
	for(auto x : f) {
		int p = x.second/lo;
		while(p--)
			ans.push_back(x.first);
	}
	ans.resize(k);
	for(int x : ans)
		cout << x << " ";
	cout << "\n";
}