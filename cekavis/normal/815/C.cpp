#include<bits/stdc++.h>
using namespace std;
const int N = 5005;
int n, m, a[N], s[N], f[N][N], g[N][N];
vector<int> e[N];
int main() {
	scanf("%d%d%d%d", &n, &m, f[1]+1, g[1]+1);
	for(int i=2, fa; i<=n; ++i) scanf("%d%d%d", f[i]+1, g[i]+1, &fa), e[fa].push_back(i);
	for(int i=n; i; --i){
		fill(f[i]+2, f[i]+n+1, 1.01e9), fill(g[i]+2, g[i]+n+1, 1.01e9), s[i]=1, g[i][1]=f[i][1]-g[i][1];
		for(int v:e[i]){
			for(int x=s[i]; ~x; --x) for(int y=s[v]; ~y; --y){
				f[i][x+y]=min(f[i][x+y], f[i][x]+f[v][y]);
				if(x) g[i][x+y]=min(g[i][x+y], g[i][x]+g[v][y]);
			}
			s[i]+=s[v];
		}
		for(int x=1; x<=s[i]; ++x) g[i][x]=min(g[i][x], f[i][x]);
	}
	return printf("%d", (int)(upper_bound(g[1]+1, g[1]+n+1, m)-g[1]-1)), 0;
}