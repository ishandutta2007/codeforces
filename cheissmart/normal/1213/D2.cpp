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

vi v[200005];

int32_t main()
{
	IO_OP;
	
	int n, k;
	cin >> n >> k;
	for(int i=0;i<n;i++) {
		int t;
		cin >> t;
		int tt = t, c = 0;
		while(tt) {
			v[tt].PB(c);
			c++;
			tt /= 2;
		}
		v[0].PB(c);
	}
	int ans = INF;
	for(int i=0;i<200005;i++) {
		sort(ALL(v[i]));
		if(v[i].size() >= k) {
			int cans= 0;
			for(int j=0;j<k;j++)
				cans += v[i][j];
			ans = min(ans, cans);
		}
	}
	cout << ans << endl;
}