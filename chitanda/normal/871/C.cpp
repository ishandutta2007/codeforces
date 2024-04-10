#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define pii pair<int, int>
#define M 1000000007
#define all(a) a.begin(), a.end()

int n;
int tot;
bool vis[200005];
vector<int> g[200005];
map<int, int> mpx, mpy;
bool flag;
int sz;
int x[100005], y[100005];
int two[200005];

int getx(int x){
	return mpx.count(x) ? mpx[x] : mpx[x] = ++tot;
}

int gety(int y){
	return mpy.count(y) ? mpy[y] : mpy[y] = ++tot;
}

void dfs(int t, int fa){
	++sz;
	vis[t] = 1;
	for(int v : g[t]){
		if(v == fa) continue;
		if(vis[v]) flag = 1;
		else dfs(v, t);
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%d%d", x + i, y + i);
		int p = getx(x[i]), q = gety(y[i]);
		g[p].pb(q);
		g[q].pb(p);
	}
	
	two[0] = 1;
	for(int i = 1; i <= tot; ++i)
		two[i] = two[i - 1] * 2 % M;
	
	int ans = 1;
	for(int i = 1; i <= tot; ++i)
		if(!vis[i]){
			flag = 0;
			sz = 0;
			dfs(i, 0);
			if(!flag) ans = (ll)ans * (two[sz] - 1) % M;
			else ans = (ll)ans * two[sz] % M;
		}
	
	printf("%d\n", ans);

#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}