#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
inline int read(){
	int x=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	while (ch>='0'&&ch<='9') { x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}
 
const int MAXN=1003,MAXM=300005;
int n,m,l,a[MAXM],b[MAXM],c[MAXM],d[MAXM],e[MAXM];
LL f[26][MAXN][MAXN],s[MAXN][MAXN],g[MAXN][MAXN],h[MAXN][MAXN];
int main(){
	int i,j,k;
	n=read(); m=read(); l=read();
	for (i=1;i<=n;++i) {
		for (j=1;j<=m;++j) s[i][j]=getchar()-'a';
		getchar();
	}
	memset(f,0,sizeof(f));
	for (i=1;i<=l;++i) {
		a[i]=read(); b[i]=read(); c[i]=read(); d[i]=read(); e[i]=getchar()-'a';
		f[e[i]][a[i]][b[i]]++; f[e[i]][a[i]][d[i]+1]--;
		f[e[i]][c[i]+1][b[i]]--; f[e[i]][c[i]+1][d[i]+1]++;
	}
	for (k=0;k<26;++k)
		for (i=1;i<=n;++i)
			for (j=1;j<=m;++j) f[k][i][j]+=f[k][i-1][j]+f[k][i][j-1]-f[k][i-1][j-1];
	memset(g,0,sizeof(g));
	for (i=1;i<=n;++i)
		for (j=1;j<=m;++j) {
			for (k=0;k<26;++k) g[i][j]+=fabs(k-s[i][j])*f[k][i][j];
			g[i][j]+=g[i-1][j]+g[i][j-1]-g[i-1][j-1];
		}
	//for (i=1;i<=n;++i) { for (j=1;j<=m;++j) cout<<g[i][j]<<' '; cout<<endl; } cout<<'G'<<endl;
	memset(h,0,sizeof(h));
	for (i=1;i<=l;++i) {
		h[a[i]][b[i]]++; h[a[i]][d[i]+1]--; h[c[i]+1][b[i]]--; h[c[i]+1][d[i]+1]++;
	}
	for (i=1;i<=n;++i)
		for (j=1;j<=m;++j) {
			h[i][j]+=h[i-1][j]+h[i][j-1]-h[i-1][j-1]; 
			f[s[i][j]][i][j]+=l-h[i][j];
		}
	//for (i=1;i<=n;++i) { for (j=1;j<=m;++j) cout<<h[i][j]<<' '; cout<<endl; } cout<<'H'<<endl;
	for (k=0;k<26;++k)
		for (i=1;i<=n;++i)
			for (j=1;j<=m;++j) f[k][i][j]+=f[k][i-1][j]+f[k][i][j-1]-f[k][i-1][j-1];
	/*for (k=0;k<26;++k) {
		for (i=1;i<=n;++i) { for (j=1;j<=m;++j) cout<<f[k][i][j]<<' '; cout<<endl; }
		cout<<char(k+'a')<<endl;
	}*/
	LL tmp,ans=1000000000000000000LL;
	for (i=1;i<=l;++i) {
		tmp=g[n][m]-(g[c[i]][d[i]]-g[a[i]-1][d[i]]-g[c[i]][b[i]-1]+g[a[i]-1][b[i]-1]);
		for (k=0;k<26;++k) {
			tmp+=fabs(k-e[i])*
			(f[k][c[i]][d[i]]-f[k][a[i]-1][d[i]]-f[k][c[i]][b[i]-1]+f[k][a[i]-1][b[i]-1]);
		}
		ans=min(ans,tmp);
	}
	cout<<ans<<endl;
	
	return 0;
}