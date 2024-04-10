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

int g[15][105][105]={};
int n,q,w;

int main() {	
	scanf("%d%d%d",&n,&q,&w);
	for(int i = 0; i < n; ++i) {
		int x,y,s;
		scanf("%d%d%d",&x,&y,&s);
		++g[s][x][y];
	}
	for(int k = 0; k <= w; ++k) {
		for(int i = 1; i < 105; ++i)
			for(int j = 1; j < 105; ++j)
				g[k][i][j] += g[k][i-1][j];
		for(int i = 1; i < 105; ++i)
			for(int j = 1; j < 105; ++j)
				g[k][i][j] += g[k][i][j-1];
	}
	while(q--) {
		int t,a,b,c,d;
		scanf("%d%d%d%d%d",&t,&a,&b,&c,&d);
		int ans = 0;
		for(int s = 0; s <= w; ++s) {
			int tot = g[s][c][d] - g[s][a-1][d] - g[s][c][b-1] + g[s][a-1][b-1];
			ans += tot * ((s + t) % (w+1));
		}
		printf("%d\n",ans);
	}
}