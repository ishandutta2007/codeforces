#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 10;

int n, k, money, cnt[MAXN], p[MAXN], mx;
ll pp[MAXN];
vector<int>	adj[MAXN];

void dfs(int v, int p = -1, int de = 0){
	cnt[de]++;
	for (int u:adj[v])
		if (u^p)
			dfs(u, v, de + 1);
	mx = max(mx, de);
}

bool check(int r, int ans){
	int b = 1, e = r, l = 1;
	while (b <= e){
		int mid = (b + e)/ 2;
		if (p[r + 1] - p[mid] >= ans)
			l = mid, b = mid + 1;
		else
			e = mid - 1;
	}

	ll sm = pp[r - 1] - pp[l - 1] - ll(r - l) * ll(p[l]);
	ll rem = ans - (p[r + 1] - p[l + 1]);
	sm -= ll(cnt[l] - rem) * ll(r - l);
	return sm <= money;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k >> money;
	k = min(k, n - 1);
	for (int i = 0; i < n - 1; i++){
		int a, b; cin >> a >> b, a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(0);
	for (int i = 0; i + 1 < MAXN; i++)
		p[i + 1] = p[i] + cnt[i];
	pp[0] = cnt[0];
	for (int i = 1; i <= mx; i++)
		pp[i] = pp[i - 1] + ll(p[i + 1]);
	
	int b = 1, e = k, ret = 0;
	while (b <= e){
		int mid = (b + e)/ 2;
		bool found = 0;
		for (int i = mx; !found && i && p[i + 1] - 1 >= mid; i--)
			found |= check(i, mid);

		if (found)
			ret = mid, b = mid + 1;
		else
			e = mid - 1;
	}	
	cout << ret << "\n";
	return 0;
}