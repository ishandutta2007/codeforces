#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define P pair
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl
#define endl '\n'

using namespace std;

typedef long long ll;
typedef P<int, int> pi;
typedef V<int> vi;

const int INF = 2e9 + 7;

int d[105], h[105];

int32_t main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		int n, x;
		cin >> n >> x;
		for(int i=0;i<n;i++)
			cin >> d[i] >> h[i];
		int mx = *max_element(d, d+n), g = -INF;
		for(int i=0;i<n;i++)
			g = max(g, d[i]-h[i]);
		if(mx >= x) cout << 1 << endl;
		else if(g <= 0) cout << -1 << endl;
		else cout << (x - mx + g - 1) / g + 1 << endl;
	}	
	
}