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

const int INF = 1e9 + 7, N = 2e5+7;

vi v[N], pos[N];
int pre[N];

signed main()
{
	IO_OP;
	
	int n, m;
	cin >> n >> m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++) {
			int t;
			cin >> t;
			v[j].PB(t);
		}
	int ans = 0;
	for(int j=0;j<m;j++) {
		int cost = n;
		vi u;
		for(int i=0;i<n;i++) {
			int x = (j+1)+i*m;
			u.PB(x);
		}
		for(int i=0;i<n;i++) {
			pre[i] = i + n;
		}
		for(int x:u) pos[x].clear();
		for(int i = 0; i < v[j].size(); i++)
			pos[v[j][i]].PB(i);
		for(int i = 0; i < u.size(); i++) {
			int x = u[i];
			for(int k:pos[x]) {
				int shift = (k - i + n) % n;
				pre[shift]--;
			}
		} 
		for(int i=0;i<n;i++)
			cost = min(cost, pre[i]);
		ans += cost;
	}
	cout << ans << endl;

}