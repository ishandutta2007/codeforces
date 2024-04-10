#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct event {
	int type, p, x;
	event(int a, int b, int c) {
		type = a, p = b, x = c;
	}
};


int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	vector<event> v;
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		v.emplace_back(1, i, a);
	}
	int q;
	cin >> q;
	for(int i = 0; i < q; ++i) {
		int type;
		cin >> type;
		int p=0, x;
		if(type == 1) cin >> p >> x;
		else cin >> x;
		v.emplace_back(type, p-1, x);
	}
	int highest = 0;
	vector<int> ans(n, -1);
	for(int i = v.size()-1; i >= 0; --i) {
		if(v[i].type == 2) {
			highest = max(highest, v[i].x);
		} else {
			if(ans[v[i].p] != -1) continue;
			ans[v[i].p] = max(highest, v[i].x);
		}
	}
	for(int i = 0; i < n; ++i)
		cout << ans[i] << ' ';
	cout << '\n';
}