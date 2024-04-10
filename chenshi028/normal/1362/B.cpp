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
int t,n,a[1050],mx,k;bool f[1050],flg;
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
int main(){
	read(t);while(t--){
		read(n);memset(f,flg=k=mx=0,sizeof f);for(int i=1;i<=n;++i) read(a[i]),f[a[i]]=1,mx=max(a[i],mx),k^=a[i];
		if(n&1){printf("-1\n");continue;}
		if(k&&((n>>2)<<2)==n){printf("-1\n");continue;}
		if(k){for(int i=flg=1;i<=n;++i) if(!f[a[i]^k]){flg=0;break;}if(flg) write(k),putchar('\n');else printf("-1\n");continue;}
		mx=min(mx<<1,2048);
		for(k=1;k<mx&&!flg;++k) for(int i=flg=1;i<=n;++i) if(!f[a[i]^k]){flg=0;break;}
		if(flg) write(k-1),putchar('\n');
		else printf("-1\n");
	}
	return 0;
}