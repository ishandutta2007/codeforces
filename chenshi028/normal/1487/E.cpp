#include<cstdio>
#include<algorithm>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}while(c<='9'&&c>='0') a=a*10+c-48,c=getchar();a*=f;}
#define write(a) printf("%d",a)
inline int Min(int a,int b){return a<b?a:b;}
const int o=1e6+10,inf=1e9+10;
int st[o][20],n[5],a[o][5],h[o],cnt,m,f[o],lg[o],U,V,tmp[o];
struct Edge{int v,p;}e[o];
inline void ad(int U,int V){e[++cnt].v=V;e[cnt].p=h[U];h[U]=cnt;}
inline void upd(int id){for(int i=1;i<=n[id];++i) st[i][0]=f[i];for(int i=1;i<19;++i) for(int j=1;j<=n[id];++j) st[j][i]=Min(st[j][i-1],st[j+(1<<(i-1))][i-1]);}
inline int query(int l,int r){return l>r?inf:Min(st[l][lg[r-l+1]],st[r-(1<<lg[r-l+1])+1][lg[r-l+1]]);}
int main(){
	lg[0]=-1;for(int i=1;i<o;++i) lg[i]=lg[i>>1]+1;
	for(int i=1;i<5;++i) read(n[i]);
	for(int i=1;i<5;++i) for(int j=1;j<=n[i];++j) read(a[j][i]);
	for(int i=1;i<=n[1];++i) f[i]=a[i][1];upd(1);
	for(int i=2;i<5;++i){
		for(int j=1;j<=n[i];++j) h[j]=0;cnt=0;
		for(read(m);m--;) read(V),read(U),ad(U,V);
		for(int j=1;j<=n[i];++j){
			f[j]=inf;cnt=0;
			for(int k=h[j];k;k=e[k].p) tmp[++cnt]=e[k].v;tmp[++cnt]=n[i-1]+1;sort(tmp,tmp+cnt+1);
			for(int k=1;k<=cnt;++k) f[j]=Min(f[j],a[j][i]+query(tmp[k-1]+1,tmp[k]-1));
		}
		upd(i);
	}
	write(query(1,n[4])>=inf?-1:query(1,n[4]));
	return 0;
}