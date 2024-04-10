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
const int o=2e5+10,MOD=998244353;
int n,m,a[o],b[o],x,y,z;long long ans=1ll;
int main(){
	read(n);read(m);
	for(int i=1;i<=n;++i) read(a[n-i+1]);
	for(int i=1;i<=m;++i) read(b[m-i+1]);
	b[0]=1e9+10;
	for(int i=1;i<=m;++i){
		for(x=y++;y<=n&&a[y]-b[i];++y);
		if(y>n){putchar('0');return 0;}
		for(z=x+1;z<y;++z) if(a[z]<b[i]){putchar('0');return 0;}
		for(z=x+1;z<y&&a[z]>=b[i-1];++z);
		ans=ans*(z-x)%MOD;
	}
	for(z=y+1;z<=n;++z) if(a[z]<b[m]){putchar('0');return 0;}
	write(ans);
	return 0;
}