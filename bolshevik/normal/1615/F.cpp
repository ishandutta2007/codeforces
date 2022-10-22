#include<cstdio>
#include<cmath>
using namespace std;
const int o=2010,MOD=1e9+7;
int T,n,f[o][o*2],g[o][o*2];char s[o],t[o];
int main(){
	for(scanf("%d",&T);T--;printf("%d\n",f[n][o])){
		scanf("%d%s%s",&n,s+1,t+1);
		for(int i=2;i<=n;i+=2) s[i]=(s[i]=='?'?'?':('a'-s[i])),t[i]=(t[i]=='?'?'?':('a'-t[i]));
		for(int i=0;i<=n;++i) for(int j=o-n;j<=o+n;++j) f[i][j]=g[i][j]=0;
		g[0][o]=1;
		for(int i=1;i<=n;++i) for(int j=o-n;j<=o+n;++j) if(f[i-1][j]||g[i-1][j])
			for(int $=0;$<2;++$) if(s[i]!=49-$) for(int _=0;_<2;++_) if(t[i]!=49-_)
				g[i][j+$-_]=(g[i][j+$-_]+g[i-1][j])%MOD,f[i][j+$-_]=(f[i][j+$-_]+f[i-1][j]+g[i-1][j]*1ll*abs(j+$-_-o))%MOD;
	}
	return 0;
}