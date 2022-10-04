/*
   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="
*/

#include <bits/stdc++.h>
#define ll long long
#define null NULL

using namespace std;

const ll MOD = 1e9 + 7;

struct vect {
	ll x, y;
	vect(ll _x, ll _y): x(_x), y(_y) {}
	vect(): x(0), y(0) {}
};

vect operator - (vect a, vect b) {
	return vect(a.x - b.x, a.y - b.y);
}

ll operator / (vect a, vect b) {
	return a.x * b.y - a.y * b.x;
}

vect operator - (vect a) {
	return vect(-a.x, -a.y);
}

int p(vect a) {
	if (a.y > 0 || (a.y == 0 && a.x >= 0))
		return 1;
	else
		return 2;
}

bool operator < (vect a, vect b) {
	int pa = p(a);
	int pb = p(b);
	if (pa < pb)
		return 1;
	if (pa > pb)
		return 0;
	return (a / b > 0);
}

int n;
vector<vect> a;

bool check_line(int p1, int p2) {
	vector<vect> other;
	for (int i = 0; i < n; ++i) {
		if (i != p1 && i != p2 && (a[i] - a[p1]) / (a[p2] - a[p1]) != 0) {
			other.push_back(a[i]);
		}
	}
	if (other.size() <= 2)
		return 1;
	for (int i = 2; i < other.size(); ++i) {
		if ((other[i] - other[0]) / (other[1] - other[0]) != 0) {
			return 0;
		}
	}
	return 1;
}

bool check_point(int p) {
	vector<pair<vect, int> > vp;
	for (int i = 0; i < n; ++i) {
		if (i != p) {
			vp.push_back({a[i] - a[p], i});
		}
	}
	for (int i = 0; i < n - 1; ++i) {
		vp.push_back({-vp[i].first, vp[i].second});
	}
	sort(vp.begin(), vp.end());
	for (int i = 0; i < vp.size() - 1; ++i) {
		if ((vp[i].first / vp[i + 1].first) == 0) {
			return check_line(vp[i].second, vp[i + 1].second);
		}
	}
	return 0;
}

const int small_n = 10;

int main() {
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].x >> a[i].y;
	}
	if (n <= 4) {
		cout << "YES" << endl;
		return 0;
	}
	/*if (n <= small_n) {
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				if (check_line(i, j) == 1) {
					cout << "YES" << endl;
					return 0;
				}
			}
		}
		cout << "NO" << endl;
		return 0;
	}*/
	for (int i = 0; i < 3; ++i) {
		if (check_point(i)) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}