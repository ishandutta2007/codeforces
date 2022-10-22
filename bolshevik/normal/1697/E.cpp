#include<cstdio>
#include<cmath>
using namespace std;
const int o=110,MOD=998244353;
int n,x[o],y[o],f[o][o],s[o],cnt,coef[o],ans;bool e[o][o],vis[o];
inline int dis(int i,int j){return abs(x[i]-x[j])+abs(y[i]-y[j]);}
void dfs(int nw){
	++s[cnt];vis[nw]=1;
	for(int i=1;i<=n;++i) if(e[nw][i]&&!vis[i]) dfs(i);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d%d",&x[i],&y[i]);
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) if(i^j)
		for(int k=e[i][j]=1;k<=n;++k) if(i-k&&j-k) e[i][j]&=(dis(i,k)>=dis(i,j));
	for(int i=1;i<=n;++i,cnt=0){
		for(int j=1;j<=n;++j) if(e[i][j]) s[++cnt]=j;
		for(int j=1;j<cnt;++j) for(int k=cnt;k>j&&cnt;--k)
			if(dis(s[k],s[j])!=dis(i,s[1])) for(;cnt;--cnt) e[i][s[cnt]]=0;
	}
	for(int T=n;T--;) for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j) if(e[i][j]&&!e[j][i]) for(int k=1;k<=n;++k) e[i][k]=0;
	for(int i=1;i<=n;++i) if(!vis[i]) s[++cnt]=0,dfs(i);
	for(int i=f[0][0]=coef[n+1]=1;i<=cnt;++i){
		for(int j=1;j<=n;++j) f[i][j]=f[i-1][j-1];
		if(s[i]>1) for(int j=s[i];j<=n;++j) f[i][j]=(f[i][j]+f[i-1][j-s[i]])%MOD;
	}
	for(int i=n;i;--i) coef[i]=coef[i+1]*1ll*i%MOD;
	for(int i=1;i<=n;++i) ans=(ans+f[cnt][i]*1ll*coef[n-i+1])%MOD;
	printf("%d",ans);
	return 0;
}