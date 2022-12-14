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

const int INF = 1e9 + 7;

signed main()
{
	IO_OP;
	
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	int zcnt = 0;
	if(!a) zcnt++;
	if(!b) zcnt++;
	if(!c) zcnt++;
	if(!d) zcnt++;
	if(zcnt == 3) {
		if(a+b+c+d != 1) {
			cout << "NO" << endl;
			return 0;
		}
		cout << "YES" << endl;
		if(a) cout << 0 << endl;
		if(b) cout << 1 << endl;
		if(c) cout << 2 << endl;
		if(d) cout << 3 << endl;
		return 0;
	}
	if(zcnt == 2) {
		if(a && b && abs(a-b) <= 1) {
			cout << "YES" << endl;
			if(a == b) 
				for(int i=0;i<a;i++) cout << "0 1 ";
			else if(a > b) {
				for(int i=0;i<b;i++) cout << "0 1 ";
				cout << "0 ";
			}
			else if(a < b) {
				cout << "1 ";
				for(int i=0;i<a;i++) cout << "0 1 ";
			}
		} else if(b && c && abs(b-c) <= 1) {
			cout << "YES" << endl;
			if(b == c) 
				for(int i=0;i<b;i++) cout << "1 2 ";
			else if(b > c) {
				for(int i=0;i<c;i++) cout << "1 2 ";
				cout << "1 ";
			}
			else if(b < c) {
				cout << "2 ";
				for(int i=0;i<b;i++) cout << "1 2 ";
			}
		} else if(c && d && abs(d-c) <= 1) {
			cout << "YES" << endl;
			if(c == d) 
				for(int i=0;i<c;i++) cout << "2 3 ";
			else if(c > d) {
				for(int i=0;i<d;i++) cout << "2 3 ";
				cout << "2 ";
			}
			else if(c < d) {
				cout << "3 ";
				for(int i=0;i<c;i++) cout << "2 3 ";
			}
		} else {
			cout << "NO" << endl;
		}
		return 0;
	}
	if(zcnt == 1) {
		if(!a) {
			if(c < b) {
				cout << "NO" << endl;
			} else {
				int rc = c - b;
				int nd = rc;
				if(d == nd || d == nd + 1 || d == nd - 1) {
					cout << "YES" << endl;
					if(d == nd - 1) {
						for(int i=0;i<b;i++) cout << "2 1 ";
						cout << "2 ";
						for(int i=0;i<d;i++) cout << "3 2 ";
					} else {
						for(int i=0;i<b;i++) cout << "1 2 ";
						for(int i=0;i<nd;i++) cout << "3 2 ";
						if(d == nd + 1) cout << 3;
					}
				} else {
					cout << "NO" << endl;
				}
			}
		} else if(!b) {
			cout << "NO" << endl;
		} else if(!c) {
			cout << "NO" << endl;
		} else {
			if(b < c) {
				cout << "NO" << endl;
			} else {
				int rb = b - c;
				int na = rb;
				if(a == na || a == na + 1 || a == na - 1) {
					cout << "YES" << endl;
					if(a == na - 1) {
						for(int i=0;i<c;i++) cout << "1 2 ";
						cout << "1 ";
						for(int i=0;i<a;i++) cout << "0 1 ";
					} else {
						for(int i=0;i<c;i++) cout << "2 1 ";
						for(int i=0;i<na;i++) cout << "0 1 ";
						if(a == na + 1) cout << 0;
					}
				} else {
					cout << "NO" << endl;
				}
			}
		}
		return 0;
	}

	vi v;
	for(int x=0;x<=min(b, c);x++) {
		int rb = b - x, rc = c - x;
		int na = rb - 1, nd = rc - 1;
		if(a == na || a == na + 1) {
			if(d == nd || d == nd + 1){
				if(a == na + 1) v.PB(0);
				for(int i=0;i<x;i++) v.PB(1), v.PB(2);
				v.PB(1);
				for(int i=0;i<na;i++) v.PB(0), v.PB(1);
				v.PB(2);
				for(int i=0;i<nd;i++) v.PB(3), v.PB(2);
				if(d == nd + 1) v.PB(3);
				break;
			}
		}
	}
	if(v.empty()) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	for(int e:v) cout << e << " ";
}