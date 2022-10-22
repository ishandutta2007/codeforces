#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e5 + 10;
const int MAXK = 100 + 3;

int n, m, k, s, a[MAXN];
vector<int> adj[MAXN];
int lv[MAXK][MAXN], sec[MAXN];
int q[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k >> s;
	for (int i = 0; i < n; i++) cin >> a[i], a[i]--;
	while (m--){
		int a, b; cin >> a >> b, a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	memset(lv, 63, sizeof(lv));
	for (int w = 0; w < k; w++){
		int h = 0, t = 0;
		for (int i = 0; i < n; i++)
			if (a[i] == w)
				q[t++] = i, lv[w][i] = 0;
		while (t^h){
			int v = q[h++];
			for (int u:adj[v])
				if (lv[w][v]+1 < lv[w][u]){
					lv[w][u] = lv[w][v]+1;
					q[t++] = u;
				}
		}
	}

	for (int i = 0; i < n; i++){
		for (int w = 0; w < k; w++)
			sec[w] = lv[w][i];
		sort(sec, sec + k);
		int ans = 0;
		for (int w = 0; w < s; w++)
			ans += sec[w];
		cout << ans << " ";
	}
	cout << "\n";
	return 0;
}