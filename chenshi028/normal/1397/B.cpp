#include<cstdio>
#include<algorithm>
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
const int o=1e5+10;
#define int long long
inline int Abs(int x){return x<0?-x:x;}
inline int Min(int a,int b){return a<b?a:b;} 
int n,a[o],f1,ans;
int qp(int b,int f){
	if(!f) return 1;
	int rcd=qp(b,f>>1);if(rcd==-1||rcd*rcd>f1+a[n]) return -1;
	int res=(f&1)?(rcd*rcd*b):(rcd*rcd);
	return (res>f1+a[n])?-1:res;
}
inline int f(int x){int tmp=0;for(int i=1,g=1;i<=n;++i) tmp+=Abs(a[i]-g),g*=x;return tmp;}
signed main(){
	read(n);for(int i=1;i<=n;++i) read(a[i]);sort(a+1,a+1+n);
	ans=f1=f(1);for(int i=2;qp(i,n-1)+1;++i) ans=Min(ans,f(i));
	write(ans);
	return 0;
}