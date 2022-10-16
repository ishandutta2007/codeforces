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
int n, m, a[102];

bool ok(int d) {
	int t = 0;
	for(int i=1;i<=100;i++)
		t += a[i] / d;
	return t >= n;
}

signed main()
{
	IO_OP;
	
	cin >> n >> m;
	for(int i=0;i<m;i++) {
		int t;
		cin >> t;
		a[t]++;
	}	
	int ans = 0;
	for(int i=1;i<=100;i++)
		if(ok(i)) ans = i;
	cout << ans << endl;
}