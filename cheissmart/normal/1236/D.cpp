#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int N = 1e5 + 87;

int a[N], n, m, l, r, u, d;

struct DS{
	int bit[N], n; // [1, n]
	DS() {
		memset(bit, 0, sizeof bit);
	}
	int lowbit(int x) {
		return x & -x;
	}
	void _add(int i, int d) {
		while(i <= n) {
			bit[i] += d;
			i += lowbit(i);
		}
	}
	int qry(int i) {
		int res = 0;
		while(i) {
			res += bit[i];
			i -= lowbit(i);
		}
		return res;
	}
	void add(int i, int j, int d) {
		_add(i, d);
		_add(j+1, -d);
	}
	int operator[]( int i)  {
		return qry(i);
	}
} rd, cd;

void cutu() {
	if(l > r) return;
	while(rd[u] == r-l+1) {
		u++;
		cd.add(l, r, -1);
	}
}

void cutd() {
	if(l > r) return;
	while(rd[d] == r-l+1) {
		d--;
		cd.add(l, r, -1);
	}
}

void cutl() {
	if(u > d) return;
	while(cd[l] == d-u+1) {
		l++;
		rd.add(u, d, -1);
	}
}
void cutr() {
	if(u > d) return;
	while(cd[r] == d-u+1) {
		r--;
		rd.add(u, d, -1);
	}
}

bool solve() {
	int n, m, k;
	cin >> n >> m >> k;
	rd.n = n, cd.n = m;
	for(int i=0;i<k;i++) {
		int x, y;
		cin >> x >> y;
		rd.add(x, x, 1);
		cd.add(y, y, 1);
	}
	l = 1, r = m, u = 1, d = n;		
	cutl();cutr();cutd();cutu();
	int di = 1;
	while(true) {
		if(l > r || u > d) break;
		// cout << di << endl;
		// debug(l), debug(r), debug(u), debug(d);
		if(di == 1) {
			if(rd[u]) return false;
			u++;
			di = 2;
			cutl();
		} else if(di == 2) {
			if(cd[r]) return false;
			r--;
			di = 3;
			cutu();
		} else if(di == 3) {
			if(rd[d]) return false;
			d--;
			di = 4;
			cutr();
		} else {
			if(cd[l]) return false;
			l++;
			di = 1;
			cutd();
		}
	}
	return true;
}

int32_t main()
{
	IO_OP;

	if(solve()) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	
}