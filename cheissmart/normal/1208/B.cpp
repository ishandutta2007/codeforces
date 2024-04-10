#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define endl '\n'
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int a[2005], b[2005], c[2005], d[2005];

map<int, int> m, mm, mmm;

int32_t main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		mmm[a[i]] = i;
	}
	for(int i=1;i<=n;i++) {
		d[i] = max(d[i-1], mmm[a[i]]);
	}
	for(int i=1;i<=n;i++) {
		b[i] = b[i-1];
		if(m[a[i]])
			b[i] = 1;
		m[a[i]] = 1;
	}
	for(int i=n;i>=1;i--) {
		c[i] = c[i+1];
		if(mm[a[i]])
			c[i] = 1;
		mm[a[i]] = 1;
	}
	int ans = INF;
	for(int i=1;i<=n;i++) {
		for(int j=i;j<=n+1;j++) {
			if(b[i-1] == 0 && c[j] == 0 && d[i-1] < j) {
				ans = min(ans, j - i);
			}
		}
	}
	cout << max(ans, 0) << endl;
}