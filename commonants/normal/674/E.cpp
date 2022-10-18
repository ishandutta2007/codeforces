#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;
const double eps=3e-9;
const int MX=500011,MXD=60;
int fa[MX];double dp[MX][MXD];
int q,cnt;
int main(){
	scanf("%d",&q);
	fa[++cnt]=0;for(int j=0;j<MXD;j++)dp[cnt][j]=1.0;
	for(int i=1;i<=q;i++){
		int typ,v;scanf("%d%d",&typ,&v);
		if(typ==1){
			fa[++cnt]=v;
			for(int j=0;j<MXD;j++)dp[cnt][j]=1.0;
			int t=cnt;double tp=1.0,tp0;
			for(int j=0;j<MXD;j++){
				if(!fa[t])break;
				tp0=dp[fa[t]][j];
				dp[fa[t]][j]*=(0.5+0.5*(j?dp[t][j-1]:0.0))/(0.5+0.5*tp);
				tp=tp0;
				t=fa[t];
			}
		}else{
			double ans=0.0;
			for(int i=1;i<MXD;i++)ans+=(dp[v][i]-dp[v][i-1])*i;
			printf("%.10f\n",ans);
		}
	}
	return 0;
}