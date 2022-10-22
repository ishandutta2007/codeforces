#include<cstdio>
#include<cstring>
using namespace std;
template<class T>inline void read(T&a){
	char c=getchar();int f=1;a=0;
	while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}
	while(c<='9'&&c>='0') a=(a<<1)+(a<<3)+c-48,c=getchar();
	a*=f;
}
template<class T>void write(T a){
	if(a<0) putchar('-'),a=-a;
	if(a>9) write(a/10);
	putchar(a%10+48);
}
inline int min(int a,int b){return a<b?a:b;}
inline int max(int a,int b){return a>b?a:b;}
const int o=1e6+10;
int t,n,k,ans;char a[o];bool vis[o];
int main(){
	read(t);while(t--){
		memset(vis,ans=0,sizeof vis);read(n);read(k);scanf("%s",a+1);
		for(int i=1;i<=n;++i) if(a[i]^48) for(int j=max(1,i-k);j<=min(i+k,n);++j) vis[j]=1;
		for(int i=1;i<=n;++i) if(!vis[i]){++ans;for(int j=max(1,i-k);j<=min(i+k,n);++j) vis[j]=1;}
		write(ans);putchar('\n');
	}
	return 0;
}