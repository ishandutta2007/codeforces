#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(a=0;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
const int o=610;
#define int long long
inline int Min(int a,int b){return a<b?a:b;}
int T,n,m,ans,f[o][o],g[o],h[o],a=5,b=4;char s[o][o];
inline int query(int xl,int yl,int xr,int yr){return f[xr][yr]-f[xl-1][yr]-f[xr][yl-1]+f[xl-1][yl-1];}
signed main(){
	for(read(T);T--;printf("%lld\n",ans)){
		read(n);read(m);ans=n*m;
		for(int i=1;i<=n;++i) scanf("%s",s[i]+1);
		for(int i=1;i<=n;++i) for(int j=1;j<=m;++j)
			f[i][j]=f[i][j-1]+s[i][j]-48;
		for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) f[i][j]+=f[i-1][j];
		for(int i=1;i<n;++i) for(int j=i+a-1;j<=n;++j){
			for(int k=1;k<=m;++k) g[k]=query(i+1,k,j-1,k)+(s[i][k]=='0')+(s[j][k]=='0');
			for(int k=1;k<=m;++k) g[k]+=g[k-1];
			h[m+1]=n*m+1;
			for(int k=m;k>1;--k) h[k]=Min(h[k+1],g[k-1]+j-i-1-query(i+1,k,j-1,k));
			for(int k=m-b+1;k;--k) ans=Min(ans,h[k+b-1]-g[k]+j-i-1-query(i+1,k,j-1,k));
		}
	}
	return 0;
}