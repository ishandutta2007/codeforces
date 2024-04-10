#include<bits/stdc++.h>
using namespace std;
const int SIZ=100000,MOD=998244353;
char buf1[SIZ],*p1=buf1,*p2=buf1;
char gchar(){if(p1==p2)p1=buf1,p2=buf1+fread(buf1,1,SIZ,stdin);return p1==p2?EOF:*p1++;}
int read(){int ret;register int c;while((c=gchar())>'9'||c<'0');ret=c-'0';while((c=gchar())>='0'&&c<='9')ret=ret*10+c-'0';return ret;}
void write(int x){if(x>9)write(x/10);putchar(x%10+'0');}
int n,f[3003],x,sz[3003],gr[3003],fl[3003];
int F(int x){return f[x]==x?x:f[x]=F(f[x]);}
int cnt,a[1125100],b[1125100];
vector<int>g[3003];
void add(int x){gr[x]++;if(gr[x]==sz[x]*(sz[x]-1)/2)fl[x]=1;}
int l[3003],r[3003],cnt1;
vector<int>R[1503];
void dfs(int x){
	if(x<=n){l[x]=r[x]=++cnt1,R[x].push_back(x);return;}
	l[x]=n+1;
	for(int i=0;i<g[x].size();i++)dfs(g[x][i]),l[x]=min(l[x],l[g[x][i]]);
	r[x]=cnt1;
	if(fl[x])R[r[x]].push_back(l[x]);
}
void Add(int &a,int b){a+=b;if(a>=MOD)a-=MOD;}
int dp[3003][3003];
int main(){
	cnt=n=read();
	for(int i=1;i<=n;f[i]=i,sz[i]=1,i++)for(int j=1;j<=n;j++)x=read(),a[x]=i,b[x]=j;
	for(int i=1;i<=n*(n-1)/2;i++){
		int u=a[i],v=b[i];
		u=F(u),v=F(v);
		if(u==v)add(u);
		else{
			++cnt,g[cnt].push_back(u),g[cnt].push_back(v);
			f[u]=f[v]=f[cnt]=cnt;
			sz[cnt]=sz[u]+sz[v],gr[cnt]=gr[u]+gr[v],add(cnt);
		}
	}
	dfs(cnt),dp[0][0]=1;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
		for(int k=0;k<R[i].size();k++)if(dp[R[i][k]-1][j-1])
			Add(dp[i][j],dp[R[i][k]-1][j-1]);
	for(int i=1;i<=n;i++)write(dp[n][i]),putchar(' ');
}