#include<cstdio>
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
const int o=1e6+10;
int t,n,a[o];long long s,f[o],g[o],m1,m2,ans;
inline long long max(long long a,long long b){return a>b?a:b;}
inline long long min(long long a,long long b){return a<b?a:b;}
int main(){
	read(t);while(t--){
		read(n);
		for(int i=s=ans=m1=m2=0;i<n;++i)
		{read(a[i]);if(i&1) g[(i+1)>>1]=g[i>>1]+a[i],g[(i+3)>>1]=0;else f[(i+2)>>1]=f[i>>1]+a[i],s+=a[i],f[(i+4)>>1]=0;}
		for(int i=1;i<=(n+1)>>1;++i) ans=max(ans,max(g[i]-f[i]-m1,g[i-1]-f[i]-m2)),m1=min(m1,g[i]-f[i]),m2=min(m2,g[i-1]-f[i]);
		write(s+ans);putchar('\n');
	}
	return 0;
}