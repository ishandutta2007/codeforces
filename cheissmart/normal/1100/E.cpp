#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(c) c.begin(),c.end()
#define INF int(1e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
int a[100005][3], vis[100005], idx[100005], n, m;
vi G[100005], t;
bool loop(int u) {
	if (vis[u] == 1)
        return 1;
    if (vis[u] == 2)
        return 0;
    vis[u] = 1;
    for (int v : G[u])
        if (loop(v))
            return 1;
    vis[u] = 2;
    return 0;
}

void top(int u) {
	vis[u]=1;
	for(auto& v : G[u]) {
		if(vis[v]==0) {
			top(v);
		}
	}
	t.PB(u);
}

bool ok(int k) {
	for(int i=1;i<=n;i++) {
		G[i].clear();
		vis[i] = 0;
	}
	for(int i=0;i<m;i++) {
		if(a[i][2] > k) {
			G[a[i][0]].PB(a[i][1]);
		}
	}
	for(int i=1;i<=n;i++) {
		if(vis[i] == 0 && loop(i))
			return false;
	}
	return true;
}

int main()
{
	IO_OP;

	cin >> n >> m;
	for(int i=0;i<m;i++)
		for(int j=0;j<3;j++)
			cin >> a[i][j];
	int l = 0, r = 1e9+7;
	while(l<=r) {
		int mid = (l+r)/2;
		if(ok(mid)) r = mid-1;
		else l = mid+1;
	}
	cout << l << " ";
	for(int i=1;i<=n;i++) {
		G[i].clear();
		vis[i] = 0;
	}
	for(int i=0;i<m;i++) {
		if(a[i][2] > l) {
			G[a[i][0]].PB(a[i][1]);
		}
	}
	for(int i=1;i<=n;i++)
		if(vis[i] == 0)
			top(i);
	reverse(t.begin(), t.end());
	for(int i=0;i<t.size();i++)
		idx[t[i]] = i;
	vi ans;
	for(int i=0;i<m;i++) {
		if(a[i][2] <= l) {
			if(idx[a[i][0]] > idx[a[i][1]])
				ans.EB(i);
		}
	}
	cout << ans.size() << endl;
	for(int p:ans)
		cout << p+1 << " ";
}