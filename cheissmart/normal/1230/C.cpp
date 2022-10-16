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

int c[10];
int u[30], v[30];

signed main()
{
	IO_OP;
	
	int n, m;
	cin >> n >> m;
	if(n <= 6) {
		cout << m << endl;
		return 0;
	}
	for(int i=0;i<m;i++)
		cin >> u[i] >> v[i];
	int ans = 0;
	for(int i=1;i<=n;i++) {
		for(int j=i+1;j<=n;j++) {
			int co = 1;
			for(int k=1;k<=n;k++)
				if(k != i && k != j)
					c[k] = co++;
			c[i] = c[j] = co++;
			set<pi> s;
			for(int k=0;k<m;k++) {
				int c1 = c[u[k]], c2 = c[v[k]];
				if(c1 > c2) swap(c1, c2);
				s.insert(MP(c1 ,c2));
			}
			ans = max(ans, (int)s.size());
		}
	}
	cout << ans << endl;
}