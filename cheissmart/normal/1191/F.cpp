#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int x[200005], y[200005], bit[200005], no[200005];

int lowbit(int x) {
	return x & -x;
}
int qry(int x) {
	int ret = 0;
	while(x) {
		ret += bit[x];
		x -= lowbit(x);
	}
	return ret;
}
void add(int i, int v) {
	while(i < 200005) {
		bit[i] += v;
		i += lowbit(i);
	}
}

vi G[200005];

int32_t main()
{
	IO_OP;
	
	int n;
	cin >> n;
	vi xs, ys;
	for(int i=0;i<n;i++) {
		cin >> x[i] >> y[i];
		xs.PB(x[i]);
		ys.PB(y[i]);
	}
	sort(xs.begin(), xs.end());
	sort(ys.begin(), ys.end());
	xs.resize(unique(xs.begin(), xs.end())-xs.begin());
	ys.resize(unique(ys.begin(), ys.end())-ys.begin());
	for(int i=0;i<n;i++) {
		x[i] = lower_bound(xs.begin(), xs.end(), x[i]) - xs.begin()+1;
		y[i] = lower_bound(ys.begin(), ys.end(), y[i]) - ys.begin()+1;
		G[y[i]].PB(x[i]);
	}
	int ans = 0;
	for(int i=ys.size();i>=1;i--) {
		sort(G[i].begin(), G[i].end());
		for(int j:G[i]) {
			if(!no[j]) {
				add(j, 1);
				no[j] = 1;
			}
		}
		int l = 0;
		for(int j=0;j<G[i].size();j++) {
			ans += (qry(G[i][j]) - qry(l)) * (qry(200004) - qry(G[i][j]) + 1);
			l = G[i][j];
		}
	}
	cout << ans << endl;
}