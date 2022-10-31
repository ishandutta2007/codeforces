#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

int n,m,k,q,g[505][505];
vi bs;
const int INF = 1e9+6;

int p[505][505];

bool broken(int t) {
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			p[i][j] = g[i][j] <= t;
		}
	}
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			p[i][j] += p[i-1][j];
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			p[i][j] += p[i][j-1];
	for(int i = k; i <= n; ++i) {
		for(int j = k; j <= m; ++j) {
			int rc = p[i][j] - p[i-k][j] - p[i][j-k] + p[i-k][j-k];
			if(rc == k*k)
				return true;
		}
	}
	return false;
}

int main() {	
	scanf("%d%d%d%d",&n,&m,&k,&q);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			g[i][j] = INF;
	bs.pb(INF);
	while(q--) {
		int x,y,t;
		scanf("%d%d%d",&x,&y,&t);
		g[x][y] = t;
		bs.pb(t);
	}
	sort(bs.begin(),bs.end());
	bs.erase(unique(bs.begin(),bs.end()),bs.end());
	int lo = -1, hi = (int)bs.size()-1;
	while(hi-lo>1) {
		int md = (lo+hi)/2;
		if(broken(bs[md]))
			hi = md;
		else
			lo = md;
	}
	if(bs[hi] == INF) printf("-1\n");
	else printf("%d\n",bs[hi]);
}