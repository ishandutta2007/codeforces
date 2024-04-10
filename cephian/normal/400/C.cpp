#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int r, c;
pair<int,int> rot(pair<int,int> p) {
	int se = r-(p.first-1);
	int fs = p.second;
	swap(r, c);
	return make_pair(fs, se);
}

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int n, m, x, y, z, p;
	cin >> n >> m >> x >> y >> z >> p;
	x %= 4, y %= 2, z = (4-(z%4))%4;
	for(int i = 0; i < p; ++i) {
		pair<int,int> q;
		cin >> q.first >> q.second;
		r = n, c = m;
		for(int j = 0; j < x; ++j) q = rot(q);
		if(y) q.second = c+1-q.second;
		for(int j = 0; j < z; ++j) q = rot(q);
		cout << q.first << ' ' << q.second << '\n';
	}
}