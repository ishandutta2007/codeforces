#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define INF int(1e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int N = 4e5 + 87;

struct p{
	int c, x, y, xi, yi;
	p(){
		c = 0;
	}
} b[N][20];

int a[N];

p merge(p u, p v) {
	p res;
	if(u.c == 0) return v;
	if(v.c == 0) return u;
	if(u.c == 2) {
		res = u;
		return res;
	}
	if(v.c == 2) {
		res = v;
		return res;
	}
	if(u.x == v.x) {
		res = u;
		return res;
	}
	res.c = 2;
	res.x = u.x, res.xi = u.xi;
	res.y = v.x, res.yi = v.xi;
	return res;
}

int main()
{
	IO_OP;
	int n, m;
	cin >> n >> m;
	for(int i=0;i<n;i++) {
		cin >> a[i];
		b[i][0].c = 1, b[i][0].x = a[i], b[i][0].xi=i;
	}
	for(int i=1;i<19;i++) {
		for(int j=0;j<n;j++) {
			auto u = b[j][i-1], v = b[j+(1<<(i-1))][i-1];
			b[j][i] = merge(u, v);
		}
	}
	while(m--) {
		int l, r, x;
		cin >> l >> r >> x;
		l--, r--;
		int i;
		for(i=0;(1<<i)<r-l+1;i++);
		i--;
		if(i < 0) i = 0;
		p cur = merge(b[l][i], b[r-(1<<i)+1][i]);
		if(cur.c == 1) {
			if(cur.x == x) {
				cout << -1 << endl;
			}
			else {
				cout << cur.xi+1 << endl;
			}
		} else {
			if(cur.x != x) {
				cout << cur.xi+1 << endl;
			} else {
				cout << cur.yi+1 << endl;
			}
		}
	}
}