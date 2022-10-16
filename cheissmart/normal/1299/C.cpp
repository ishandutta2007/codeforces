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

const int INF = 1e9 + 7, N = 1000006;

int a[N], n;
double p[N], pp[N];

signed main()
{
	IO_OP;
	
	cin >> n;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		p[i] = a[i] + p[i-1];
	}
	V<pair<double, int>> v({{0, 0}});
	for(int i=1;i<=n;i++) {
		while(v.size() >= 2 && (p[i]-v.back().F)/(i-v.back().S) <
		 (v.back().F-v[v.size()-2].F)/(v.back().S-v[v.size()-2].S))
			v.pop_back();
		v.EB(p[i], i);
	}
	cout << fixed << setprecision(10);
	for(int i=0;i<(int)v.size()-1;i++) {
		int l = v[i].S, r = v[i+1].S;
		double ll = p[l], rr = p[r];
		for(int i=l;i<=r;i++) {
			pp[i] = ll + (rr - ll) / (r - l) * (i - l);
		}
	}
	for(int i=1;i<=n;i++)
		cout << pp[i] - pp[i-1] << '\n';

}