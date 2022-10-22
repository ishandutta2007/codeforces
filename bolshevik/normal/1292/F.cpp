#include<cstdio>
using namespace std;
const int o=1<<15,MOD=1e9+7;
int n,a[o],ans=1,st[o],tp,St[o],Tp,w[o],f[o],C[70][70],A[70][70],T[o],h[o],cnt,s;bool vis[o],flg[o];
struct Edge{int v,p;}e[o];
inline void ad(int U,int V){e[++cnt].v=V;e[cnt].p=h[U];h[U]=cnt;}
void dfs(int nw){
	if(vis[nw]) return;
	vis[nw]=1;
	if(flg[nw]) St[++Tp]=nw;
	else st[++tp]=nw;
	for(int i=h[nw];i;i=e[i].p) dfs(e[i].v);
}
inline void calc(){
	if(!tp) return;
	ans=ans*1ll*C[s+=tp-1][tp-1]%MOD;
	for(int i=0;i<(1<<Tp);++i) w[i]=f[i]=0;
	for(int i=1,j;i<=tp;++w[T[i++]]) for(T[i]=0,j=1;j<=Tp;++j) if(a[st[i]]%a[St[j]]==0) T[i]|=(1<<(j-1));
	for(int i=1;i<(1<<Tp);i<<=1) for(int j=0;j<(1<<Tp);j+=i<<1)
		for(int k=0;k<i;++k) w[i+j+k]=(w[i+j+k]+w[j+k])%MOD;
	f[(1<<Tp)-1]=1;
	for(int i=(1<<Tp)-1;i--;) for(int j=1;j<=tp;++j) if((i&T[j])-T[j]&&(!i||(i&T[j])))
		f[i]=(f[i]+f[i|T[j]]*1ll*A[w[(1<<Tp)-1]-w[i]-1][w[i|T[j]]-w[i]-1])%MOD;
	ans=ans*1ll*f[0]%MOD;
}
int main(){
	scanf("%d",&n);
	for(int i=C[0][0]=A[0][0]=1;i<=n;scanf("%d",&a[i++])) for(int j=C[i][0]=A[i][0]=1;j<=i;++j)
		C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD,A[i][j]=A[i-1][j-1]*1ll*i%MOD;
	for(int i=1;i<=n;++i) for(int j=flg[i]=1;j<=n;++j) if(i-j&&a[i]%a[j]==0) flg[i]=0,ad(i,j),ad(j,i);
	for(int i=1;i<=n;++i) if(!vis[i]) tp=Tp=0,dfs(i),calc();
	printf("%d",ans);
	return 0;
}