#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define endl '\n'
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int x[300005], y[300005], ans[300005], pos[300005];
pi p[300005];
vi G[300005];

int32_t main()
{
	IO_OP;

	int n, m;
	cin >> n >> m;
	for(int i=0;i<n;i++) {
		cin >> x[i] >> y[i];
		p[i] = {x[i]-y[i], i};
	}
	for(int i=0;i<m;i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		G[u].PB(v);
		G[v].PB(u);
	}
	sort(p, p+n);
	for(int i=0;i<n;i++)
		pos[p[i].S] = i;
	int px = 0;
	for(int i=0;i<n;i++) {
		int j = p[i].S, d = 0;
		ans[j] += px;
		for(int v:G[j]) {
			if(pos[v] < i)  {
				ans[j] -= x[v];
				d++;
			}
		}
		ans[j] += (i-d) * y[j];
		px += x[j];
	}
	int py = 0;
	for(int i=n-1;i>=0;i--) {
		int j = p[i].S, d = 0;
		ans[j] += py;
		for(int v:G[j]) {
			if(pos[v] > i)  {
				ans[j] -= y[v];
				d++;
			}
		}
		ans[j] += (n-i-1-d) * x[j];
		py += y[j];
	}
	for(int i=0;i<n;i++)
		cout << ans[i] << " ";
}