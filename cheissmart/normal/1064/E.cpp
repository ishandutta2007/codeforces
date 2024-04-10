#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, l = 0, r = 1e9, x, y = 87;
	vector<pair<int, int>> v;
	cin >> n;
	while(n--) {
		if (r <= l+1) {
			v.emplace_back(l, y);
			l = 0, r = 1e9, ++y;
		}
		int x = (l + r) / 2;
		cout << x << ' ' << y << endl;
		string s;
		cin >> s;
		if (s[0] == 'b')
			l = x+1;
		else
			r = x-1; 
	}
	if(v.size() == 2) {
		cout << v[0].first << " " << v[0].second << " " << v[1].first << " " << v[1].second << endl;
	} else if(v.size() == 1) {
		cout << v[0].first << " " << v[0].second << " " << l << " " << y << endl;
	} else {
		cout << l << " " << y << " " << l << " " << y + 87 << endl;
	}
}