#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 18, M = 1<<N;
int n, p[M];
ll h[M], ans[M], f[M][N], g[N][M];
char s[N][N];
map<vector<int>,vector<int>> S;
ll calc(const vector<int> &x){
	fill(h, h+(1<<n), 1);
	for(int i:x) for(int j=0; j<1<<n; ++j) h[j]*=g[i][j];
	ll ans=0;
	for(int i=0; i<1<<n; ++i) ans+=((n-p[i])&1)?-h[i]:h[i];
	return ans;
}
int main() {
	scanf("%d", &n);
	for(int i=0; i<n; ++i) scanf("%s", s[i]);
	for(int i=0; i<n; ++i) f[1<<i][i]=1;
	for(int i=1; i<1<<n; ++i) p[i]=p[i>>1]+(i&1);
	for(int i=1; i<1<<n; ++i) for(int j=0; j<n; ++j) if(i>>j&1){
		for(int k=0; k<n; ++k) if(!(i>>k&1) && s[j][k]=='1')
			f[i|(1<<k)][k]+=f[i][j];
		g[p[i]][i]+=f[i][j];
	}
	for(int i=0; i<=n; ++i) for(int j=0; j<n; ++j) for(int k=0; k<1<<n; ++k)
		if(k>>j&1) g[i][k]+=g[i][k-(1<<j)];
	for(int i=0; i<1<<(n-1); ++i){
		vector<int> s;
		for(int j=0, x=1; j<n; ++j) if(i>>j&1) ++x; else s.push_back(x), x=1;
		sort(s.begin(), s.end());
		S[s].push_back(i);
	}
	for(auto x:S){
		ll s=calc(x.first);
		for(int i:x.second) ans[i]=s;
	}
	for(int i=0; i<n-1; ++i) for(int j=0; j<1<<(n-1); ++j) if(j>>i&1)
		ans[j-(1<<i)]-=ans[j];
	for(int i=0; i<1<<(n-1); ++i) printf("%lld ", ans[i]);
	return 0;
}