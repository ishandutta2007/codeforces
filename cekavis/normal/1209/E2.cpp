#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 14, M = 2005, K = 1<<12;
int n, m, T, f[K], g[K];
struct item{
	int mx, a[N];
	bool operator<(const item &r)const{ return mx>r.mx;}
	int &operator[](const int x){ return a[x];}
} a[M];
int main() {
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n, &m);
		for(int j=1; j<=m; ++j) a[j].mx=0;
		for(int i=0; i<n; ++i) for(int j=1; j<=m; ++j)
			scanf("%d", &a[j][i]), a[j].mx=max(a[j].mx, a[j][i]);
		sort(a+1, a+m+1);
		memset(f, 0, sizeof f);
		for(int i=1; i<=n && i<=m; ++i){
			for(int j=0; j<1<<n; ++j){
				g[j]=0;
				for(int k=0; k<n; ++k){
					int s=0;
					for(int t=0; t<n; ++t) if(j>>t&1) s+=a[i][(t+k)%n];
					g[j]=max(g[j], s);
				}
			}
			for(int j=1<<n; --j;) for(int k=j; k; k=(k-1)&j)
				f[j]=max(f[j], f[k^j]+g[k]);
		}
		printf("%d\n", f[(1<<n)-1]);
	}
	return 0;
}