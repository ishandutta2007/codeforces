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

int a[1003], b[1003];
int n, m;

bool ok(double f) {
	for(int i=1;i<=n;i++) {
		int nxt = i + 1;
		if(nxt > n) nxt -= n;
		double req = (m + f) / a[i];
		if(f < req) return false;
		f -= req;
		req = (m + f) / b[nxt];
		if(f < req) return false;
		f -= req;
	}
	return true;
}

signed main()
{
	IO_OP;
	
	cin >> n>> m;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		if(a[i] == 1) {
			cout << -1 << endl;
			return 0;
		}
	}	
	for(int i=1;i<=n;i++) {
		cin >> b[i];
		if(b[i] == 1) {
			cout << -1 << endl;
			return 0;
		}
	}	
	double l = 0, r = 1e9 + 7;
	for(int i=0;i<1000;i++) {
		double m = (l + r) / 2;
		if(ok(m)) r = m;
		else l = m;
	}
	cout << fixed << setprecision(10) << l << endl;
	
}