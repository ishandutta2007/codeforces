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
#define int long long
inline int min(int a,int b){return a<b?a:b;}
const int o=2e5+10;
int n,a[o],s,ans,mn;
signed main(){
	read(n);for(int i=1;i<=n;++i) read(a[i]),ans+=a[i];
	for(int i=1;i<n;i+=2) s+=a[i];mn=s;
	for(int i=1,j=1;i<=n;++i,j=(j+1)%n+1) s=s-a[j]+a[(j+n-2)%n+1],mn=min(mn,s);
	write(ans-mn);
	return 0;
}