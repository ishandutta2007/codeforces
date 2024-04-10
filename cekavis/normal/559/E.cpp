#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 105;
int n, m, b[N], l[N], r[N], x[N*3], g[N][N*3], f[N][N][N*3];
pair<int,int> a[N];
int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; ++i){
		scanf("%d%d", &a[i].first, &a[i].second);
		x[++m]=a[i].first;
		x[++m]=a[i].first-a[i].second;
		x[++m]=a[i].first+a[i].second;
	}
	sort(a+1, a+n+1), sort(x+1, x+m+1), m=unique(x+1, x+m+1)-x-1;
	for(int i=1; i<=n; ++i)
		b[i]=lower_bound(x+1, x+m+1, a[i].first)-x,
		l[i]=lower_bound(x+1, x+m+1, a[i].first-a[i].second)-x,
		r[i]=lower_bound(x+1, x+m+1, a[i].first+a[i].second)-x;
	memset(f, 0x3f, sizeof f);
	for(int i=1; i<=n; ++i){
		f[i][i][b[i]]=l[i];
		for(int j=b[i]+1; j<=r[i]; ++j) f[i][i][j]=b[i];
	}
	for(int i=1; i<=n; ++i) for(int j=i+1; j<=n; ++j){
		for(int k=b[j]; k<=m; ++k) f[i][j][k]=f[i][j-1][k];
		for(int k=b[j]; k<=r[j]; ++k)
			f[i][j][k]=min(f[i][j][k], f[i][j-1][b[j]]);
		if(l[j]<=b[j-1]) f[i][j][b[j]]=min(f[i][j][b[j]], f[i][j-1][b[j-1]]);
		for(int k=i; k<j; ++k) if(r[k]>=b[j]){
			int t=j-1, L=min(b[k], l[j]);
			while(t>=i && L<=b[t]){
				if(t!=k) L=min(L, l[t]);
				--t;
			}
			if(t<i) for(int p=b[j]; p<=r[k]; ++p) f[i][j][p]=min(f[i][j][p], L);
			else
				for(int p=b[j]; p<=r[k]; ++p)
					f[i][j][p]=min(f[i][j][p], f[i][t][L]);
		}
		int t=j-1, L=l[j];
		while(t>=i && L<=b[t]) L=min(L, l[t--]);
		if(t<i) f[i][j][b[j]]=min(f[i][j][b[j]], L);
		else f[i][j][b[j]]=min(f[i][j][b[j]], f[i][t][L]);
	}
	for(int i=1; i<=n; ++i) for(int j=0; j<=m; ++j) for(int k=i; k<=n; ++k)
		for(int p=b[k]; p<=m; ++p) if(j<f[i][k][p] && f[i][k][p]<m)
			g[k][p]=max(g[k][p], g[i-1][j]+x[p]-x[f[i][k][p]]);
	printf("%d\n", *max_element(g[n], g[n]+m+1));
	return 0;
}