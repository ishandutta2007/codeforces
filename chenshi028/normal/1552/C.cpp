#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
inline int Max(int a,int b){return a>b?a:b;}
inline int Min(int a,int b){return a<b?a:b;}
const int o=210;
int T,n,k,l[o],r[o],stk[o],cnt,ans;bool vis[o];
int main(){
	for(read(T);T--;printf("%d\n",ans),ans=cnt=0){
		read(n);read(k);
		for(int i=1;i<=2*n;++i) vis[i]=0;
		for(int i=1;i<=k;++i) read(l[i]),read(r[i]),vis[l[i]]=vis[r[i]]=1;
		for(int i=1,j;i<=k;++i) if(l[i]>r[i]) j=l[i],l[i]=r[i],r[i]=j;
		for(int i=1;i<=2*n;++i) if(!vis[i]) stk[++cnt]=i;
		for(int i=1;i<=n-k;++i) l[i+k]=stk[i],r[i+k]=stk[i+n-k];
		for(int i=1;i<n;++i) for(int j=n;j>i;--j)
			ans+=(Max(l[i],l[j])<Min(r[i],r[j])&&!(l[i]<=l[j]&&r[j]<=r[i])&&!(l[j]<=l[i]&&r[i]<=r[j]));
	}
	return 0;
}