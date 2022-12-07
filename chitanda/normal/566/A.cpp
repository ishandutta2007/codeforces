#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

const int maxn = 800100;
int n;
vector<int> p[maxn], q[maxn];
char s[maxn];
int ans;
vector<pair<int, int> > mc;
int son[maxn][26], tot = 1;

void work(vector<int> g[]){
	for(int i = 1; i <= n; ++i){
		scanf("%s", s);
		int m = strlen(s), now = 1;
		for(int i = 0; i < m; ++i){
			if(!son[now][s[i] - 'a']) son[now][s[i] - 'a'] = ++tot;
			now = son[now][s[i] - 'a'];
		}
		g[now].pb(i);
	}
}

void dfs(int t, int f, int d){
	for(int i = 0; i < 26; ++i)
		if(son[t][i]) dfs(son[t][i], t, d + 1);
	int i = p[t].size(), j = q[t].size();
	ans += d * min(i, j);
	for(; i && j; --i, --j)
		mc.pb(mkp(p[t][i - 1], q[t][j - 1]));
	for(; i; --i) p[f].pb(p[t][i - 1]);
	for(; j; --j) q[f].pb(q[t][j - 1]);
}

int main(){
	scanf("%d", &n);
	work(p);
	work(q);
	dfs(1, 0, 0);
	printf("%d\n", ans);
	for(auto v : mc) printf("%d %d\n", v.fi, v.se);
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}