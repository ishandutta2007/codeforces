#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

const int B = 330;
const int maxn = 100100;
int n, m, q;
vector<int> g[maxn];
int t1[maxn], t2[maxn], len[maxn];
int fa[maxn], size[maxn];
vector<int> cnt[maxn];
vector<ll> sum[maxn];
double ans[maxn / B + 100][maxn / B + 100];

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

void merge(int u, int v){
	u = find(u), v = find(v);
	fa[u] = v;
	size[v] += size[u];
}

void dfs(int t, int fa, int c){
	for(auto v : g[t]){
		if(v == fa) continue;
		dfs(v, t, c);
		if(t1[v] + 1 > t1[t]) t2[t] = t1[t], t1[t] = t1[v] + 1;
		else t2[t] = max(t2[t], t1[v] + 1);
	}
	len[c] = max(len[c], t1[t] + t2[t]);
}

void dfs2(int t, int fa, int c){
	for(auto v : g[t]){
		if(v == fa) continue;
		int x = 0;
		if(t1[v] + 1 == t1[t]) x = t2[t] + 1;
		else x = t1[t] + 1;
		if(x > t1[v]) t2[v] = t1[v], t1[v] = x;
		else t2[v] = max(t2[v], x);
		dfs2(v, t, c);
	}
	cnt[c][t1[t]]++;
	//printf("%d %d %d\n", c, t, cnt[c][t1[t]]);
}

double work(int x, int y){
	if(x == y) return -1;
	if(size[x] > size[y]) swap(x, y);
	int prelen = max(len[x], len[y]);
	ll tmp = 0; int last = 0;
	for(int k = 0; k < size[x]; ++k){
		int now = cnt[x][k] - last; last = cnt[x][k];
		if(k <= prelen - 1){
			if(prelen - 1 - k >= size[y] - 1){
				tmp += (ll)prelen * now * cnt[y][size[y] - 1];
			}else{
				tmp += (ll)prelen * now * cnt[y][prelen - 1 - k];
				tmp += (ll)now * (sum[y][size[y] - 1] - sum[y][prelen - 1 - k]);
				tmp += (ll)(k + 1) * now * (cnt[y][size[y] - 1] - cnt[y][prelen - 1 - k]);
			}
		}else{
			tmp += (ll)now * sum[y][size[y] - 1] + (ll)(k + 1) * now * cnt[y][size[y] - 1];
		}
	}
	return 1. * tmp / ((ll)size[x] * size[y]);
}

int main(){
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 1; i <= n; ++i) fa[i] = i, size[i] = 1;
	for(int i = 1; i <= m; ++i){
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].pb(v);
		g[v].pb(u);
		merge(u, v);
	}
	vector<int> kuai;
	for(int i = 1; i <= n; ++i){
		if(find(i) != i) continue;
		if(size[i] >= B)
			kuai.pb(i);
		cnt[i].resize(size[i]);
		sum[i].resize(size[i]);
		dfs(i, 0, i);
		dfs2(i, 0, i);
		for(int j = 1; j < size[i]; ++j){
			sum[i][j] = sum[i][j - 1] + (ll)j * cnt[i][j];
			cnt[i][j] += cnt[i][j - 1];
			//printf("%d %d: %d %lld\n", i, j, cnt[i][j], sum[i][j]);
		}
	}
	
	for(int i = 0; i < kuai.size(); ++i)
		for(int j = i; j < kuai.size(); ++j){
			if(i == j) ans[i][j] = -1;
			else{
				int x = kuai[i], y = kuai[j];
				ans[i][j] = work(x, y);
				ans[j][i] = ans[i][j];
			}
		}
	
	while(q--){
		int u, v;
		scanf("%d%d", &u, &v);
		u = find(u), v = find(v);
		if(size[u] >= B && size[v] >= B){
			u = lower_bound(kuai.begin(), kuai.end(), u) - kuai.begin();
			v = lower_bound(kuai.begin(), kuai.end(), v) - kuai.begin();
			printf("%.10f\n", ans[u][v]);
		}else{
			printf("%.10f\n", work(u, v));
		}
	}
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}