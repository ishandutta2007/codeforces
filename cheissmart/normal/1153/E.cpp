#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int qry(int a, int b, int c, int d) {
	cout << "? " << a << " " << b << " " << c << " " << d << endl;
	int res;
	cin >> res;
	return res;
}

void ans(int a, int b, int c, int d) {
	cout << "! " << a << " " << b << " " << c << " " << d << endl;
}

int main()
{
	IO_OP;
	
	int n, k;
	vi r, c;
	cin >> n;
	for(int i=1;i<=n;i++) {
		if(qry(i, 1, i, n)&1)
			r.PB(i);
		if(qry(1, i, n, i)&1)
			c.PB(i);
	}
	if(r.size() && c.size()) {
		if(qry(r[0], c[0], r[0], c[0])&1) {
			ans(r[0], c[0], r[1], c[1]);
		} else {
			ans(r[0], c[1], r[1], c[0]);
		}
	} else if(c.size()) {
		int l = 1, h = n;
		while(h - l > 0) {
			int m = (l + h) / 2;
			if(qry(l, c[0], m, c[0]) & 1) {
				h = m;
			} else {
				l = m + 1;
			}
		}
		ans(l, c[0], l, c[1]);
	} else {
		int l = 1, h = n;
		while(h - l > 0) {
			int m = (l + h) / 2;
			if(qry(r[0], l, r[0], m) & 1) {
				h = m;
			} else {
				l = m + 1;
			}
		}
		ans(r[0], l, r[1], l);
	}
}