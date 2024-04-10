#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

#define Query pair<pair<int, int>, pair<int, int>>
#define left first.first
#define right first.second
#define qu second.first
#define num second.second

const int MAXN = 1e5 + 20;
const int SQRT = 320;
const int LOG = 18 + 2;

int n, q;
int par[MAXN][LOG];
int depth[MAXN], s_t[MAXN], f_t[MAXN], sz, ss[MAXN];
vector<int>	adj[MAXN];
Query sec[MAXN];
int cnt[MAXN], ans[MAXN];

void init(){
	for (int i = 1; i < LOG; i++)
		for (int j = 0; j < n; j++)
			if (par[j][i - 1] == -1)
				par[j][i] = -1;
			else
				par[j][i] = par[par[j][i - 1]][i - 1];
}

int move_up(int v, int x){
	for (int i = LOG - 1; i >= 0; i--){
		if ((1 << i) > x || par[v][i] == -1)	continue;
		v = par[v][i];
		x -= (1 << i);
	}	
	return	v;
}

void build(int v, int de = 0){
	depth[v] = de;
	ss[sz] = v;
	s_t[v] = sz++;
	for (int u:adj[v])
		build(u, de + 1);
	f_t[v] = sz;
}

bool cmp(Query a, Query b){
	if (a.left / SQRT != b.left / SQRT)
		return	a.left < b.left;
	return	a.right < b.right;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> par[i][0];
		par[i][0]--;
		if (par[i][0] != -1)
			adj[par[i][0]].push_back(i);
	}
	for (int i = 0; i < n; i++)
		if (par[i][0] == -1)
			build(i);
	init();
	cin >> q;
	for (int i = 0; i < q; i++){
		int v, k;	cin >> v >> k;	v--;
		if (depth[v] < k){
			sec[i].left = 1e9;
			continue;
		}
		int tv = v;
		v = move_up(v, k);
		sec[i].left = s_t[v];
		sec[i].right = f_t[v];
		sec[i].qu = depth[tv];
		sec[i].num = i;
	}
	sort(sec, sec + q, cmp);

	int l = 0, r = 0;
	for (int i = 0; i < q; i++){
		if (sec[i].left == 1e9)	continue;
		int tl = sec[i].left, tr = sec[i].right;
		while (r < tr)
			cnt[depth[ss[r++]]]++;
		while (l > tl)
			cnt[depth[ss[--l]]]++;
		while (r > tr)
			cnt[depth[ss[--r]]]--;
		while (l < tl)
			cnt[depth[ss[l++]]]--;
		ans[sec[i].num] = cnt[sec[i].qu] - 1;
	}
	for (int i = 0; i < q; i++)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}