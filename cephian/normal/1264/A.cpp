#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n;
	cin >> n;
	vector<int> v;
	int l = 0;
	int cnt = 0;
	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		if(a == l) ++cnt;
		else {
			if(cnt != 0)
				v.push_back(cnt);
			cnt = 1;
			l = a;
		}
	}
	v.push_back(cnt);
	int g = v[0];
	int s = 0;
	int b = 0;
	int i = 1;
	while(s <= g && i < (int)v.size()) {
		s += v[i++];
	}
	while(i < (int)v.size() && 2*(g+s+b+v[i]) <= n) {
		b += v[i++];
	}
	if(2*(g+s+b) <= n && g < s && g < b)
		cout << g << ' ' << s << ' ' << b << '\n';
	else
		cout << "0 0 0\n";
}


int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
}