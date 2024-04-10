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
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

int x[100005], y[100005];

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	if(n & 1) {
		cout << "NO" << endl;
		return 0;
	}
	for(int i=0;i<n;i++)
		cin >> x[i] >> y[i];
	map<pi, int> cnt;
	V<pi> v;
	for(int i=0;i<n;i++) {
		int a = x[i] - x[(i+1)%n], b = y[i] - y[(i+1)%n];
		cnt[{a, b}]++;
		v.EB(a, b);
	}
	for(int i=0;i<n/2;i++) {
		if(v[i].F != -v[i+n/2].F || v[i].S != -v[i+n/2].S) {
			cout << "NO" << endl;
			return 0;
		}
	}
	
	cout << "YES" << endl;
}