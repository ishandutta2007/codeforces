#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}while(c<='9'&&c>='0') a=a*10+c-48,c=getchar();a*=f;}
#define write(a) printf("%d",a)
inline int Min(int a,int b){return a<b?a:b;}
//Obviously, f(x,y)>0 => the shortest path between x and y is unique
const int o=700,MOD=998244353;
int n,m,dis[o][o],u[o],v[o],ans,d[o];
int main(){
	read(n);read(m);for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) if(i^j) dis[i][j]=o;
	for(int i=1;i<=m;++i) read(u[i]),read(v[i]),dis[u[i]][v[i]]=dis[v[i]][u[i]]=1;
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) for(int k=1;k<=n;++k) dis[j][k]=Min(dis[j][k],dis[j][i]+dis[i][k]);
	for(int i=1,cnt;i<=n;++i,putchar('\n'))
		for(int j=1;j<=n;++j,putchar(' ')){
			cnt=0;for(int k=ans=1;k<=n;++k) if(dis[i][k]+dis[k][j]==dis[i][j]) ++cnt,d[k]=1;else d[k]=0;
			if(cnt!=dis[i][j]+1){putchar('0');continue;}
			for(int k=1;k<=m;++k) if(dis[i][u[k]]+dis[u[k]][j]!=dis[i][j]||dis[i][v[k]]+dis[v[k]][j]!=dis[i][j])
				if(dis[i][u[k]]+1==dis[i][v[k]]&&dis[j][u[k]]+1==dis[j][v[k]]) ++d[v[k]];
				else if(dis[i][v[k]]+1==dis[i][u[k]]&&dis[j][v[k]]+1==dis[j][u[k]]) ++d[u[k]];
			for(int k=1;k<=n;++k) ans=ans*1ll*d[k]%MOD;
			write(ans); 
		}
	return 0;
}