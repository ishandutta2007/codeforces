#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

vector<pair<int, int> > f[3][200100];
pair<int, int> ans[100100], res[100100];
int g[100100], p[100100], t[100100];
int n, h, w;

void work(vector<pair<int, int> > &f, vector<pair<int, int> > &g){
	int n = f.size(), m = g.size();
	for(int i = 0; i < n; ++i){
		if(m >= n)
			ans[f[i].se] = res[g[n - i - 1].se];
		else{
			if(i + m < n)
				ans[f[i].se] = res[f[i + m].se];
			else
				ans[f[i].se] = res[g[n - i - 1].se];
		}
	}
}

int main(){
	scanf("%d%d%d", &n, &w, &h);
	for(int i = 1; i <= n; ++i){
		scanf("%d%d%d", g + i, p + i, t + i);
		f[g[i]][t[i] - p[i] + 100000].pb(mkp(p[i], i));
		res[i] = ans[i] = g[i] == 1 ? mkp(p[i], h) : mkp(w, p[i]);
	}
	
	for(int i = 1; i <= 200000; ++i){
		if(f[1][i].size() && f[2][i].size()){
			sort(all(f[1][i]));
			sort(all(f[2][i]));
			work(f[1][i], f[2][i]);
			work(f[2][i], f[1][i]);
		}
	}
	
	for(int i = 1; i <= n; ++i)
		printf("%d %d\n", ans[i].fi, ans[i].se);
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}