#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(a=0;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
const int o=1e6+10,MOD=1e9+7;
int n,p[o],d[o],cnt[o],c[o],C[o],vis[o],hus[o],wif[o],ans=1,fac[o];
inline int f(int x){if(x==1) return 1;return n/x;}
inline bool chk(int x,int y){
	if(cnt[x]^cnt[y]) return false;
	for(int i=1,j=x,k=y;i<=cnt[x];j/=vis[j],k/=vis[k],++i)
		if(f(vis[j])^f(vis[k])) return false;
	int i=vis[x],j=vis[y];
	if(f(i)^f(j)) return false;
	if(hus[i]&&hus[i]-j) return false;
	if(wif[j]&&wif[j]-i) return false;
	if(!hus[i]) --C[f(wif[hus[i]=j]=i)];
	--c[y];
	return true;
}
int main(){
	read(n);
	for(int i=fac[0]=1;i<=n;++i) read(p[i]),fac[i]=fac[i-1]*1ll*i%MOD;
	for(int i=2,j;i<=n;++i) if(!vis[i]) for(++C[n/(j=i)];j<=n;j+=i) ++cnt[j],vis[j]=i;
	d[1]=c[1]=cnt[1]=vis[1]=1;++C[1];
	for(int i=2,j;i<=n;++c[d[i++]]) if((j=d[i/vis[i]])%vis[i]) d[i]=j*vis[i];else d[i]=j;
	for(int i=1;i<=n;++i) if(p[i]>0) if(!chk(d[i],d[p[i]])){printf("0");return 0;}
	for(int i=1;i<=n;++i) ans=ans*1ll*fac[c[i]]%MOD*fac[C[i]]%MOD;
	printf("%d",ans);
	return 0;
}