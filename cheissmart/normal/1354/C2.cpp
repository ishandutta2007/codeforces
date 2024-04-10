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
#define double long double

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 503;
const double TT = acos(-1);

double ra[N], theta[N];

double go1(int n, double ang) {
	double na = TT - (n - 2) * TT / n;
	int l = 0, r = n - 1;
	while(l <= r) {
		int m = (l + r) / 2;
		double sa = ang + m * na;
		if(sa > TT) r = m - 1;
		else l = m + 1;
	} 
	int tt = r;
	double rr = ra[tt], phi = theta[tt] + ang;
	return rr * sin(phi);
}


double go2(int n, double ang) {
	double x1, x2;
	{
		double na = TT - (n - 2) * TT / n;
		int l = 0, r = n - 1;
		while(l <= r) {
			int m = (l + r) / 2;
			double sa = ang + m * na;
			if(sa > TT / 2) r = m - 1;
			else l = m + 1;
		} 
		int tt = r;
		double rr = ra[tt], phi = theta[tt] + ang;
		x1 = rr * cos(phi);
	}
	{
		double na = TT - (n - 2) * TT / n;
		int l = 0, r = n - 1;
		while(l <= r) {
			int m = (l + r) / 2;
			double sa = ang + m * na;
			if(sa > TT / 2 + TT) r = m - 1;
			else l = m + 1;
		} 
		int tt = r;
		double rr = ra[tt], phi = theta[tt] + ang;
		x2 = rr * cos(phi);
	}
	return abs(x1 - x2);
}

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	cout << fixed << setprecision(10);
	while(t--) {
		int n;
		cin >> n;
		n *= 2;
		double ang = (n - 2) * TT / n;
		double x = 0, y = 0, dir = 0;
		for(int i = 0; i < n; i++) {
			x = x + cos(dir), y = y + sin(dir);
			ra[i] = sqrt(x * x + y * y);
			theta[i] = atan2(y, x);
			dir += TT - ang;
		}
		double l = 0, r = TT - ang;
		for(int i = 0; i < 1000; i++) {
			double m = (l + r) / 2;
			if(go1(n, m) < go2(n, m)) l = m;
			else r = m;
		}
		cout << go1(n, l) << endl;
	}

}