#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 2005;
int n, m, ans, a[N], b[N], c[N*2];
vector<int> f[N*2];
int main() {
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; ++i) scanf("%d", a+i);
	for(int i=1; i<=n; ++i) scanf("%d", b+i);
	for(int i=1; i<=n+m; ++i) scanf("%d", c+i);
	f[0].push_back(0);
	for(int i=n; i; --i){
		vector<int> g=f[a[i]];
		for(int j=a[i]; ~j; j--) for(int k=0; k<(int)f[j].size(); ++k){
			int x=k, sum=0;
			for(int p=j; p<a[i] && x; ++p) sum+=(x/=2)*c[p+1];
			++x;
			while((int)g.size()<=x) g.push_back(-1e9);
			g[x]=max(g[x], sum+=f[j][k]-b[i]+c[a[i]]);
			for(int p=a[i]; x>1; ++p) sum+=(x/=2)*c[p+1];
			ans=max(ans, sum);
		}
		f[a[i]]=g;
	}
	printf("%d\n", ans);
	return 0;
}