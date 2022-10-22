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
const int o=1e6+10,MOD=998244353;
#define int long long
int n,x,y,A,f[o],g[o],q,l,rev[o],bit,ans[o];
int qp(int b,int f){
	if(!f) return 1;
	int rcd=qp(b,f>>1);
	return (f&1)?rcd*rcd%MOD*b%MOD:rcd*rcd%MOD;
}
inline void ntt(int*a,int n,int inv){
	for(int i=1;i<n;++i){
		rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
		if(i<rev[i]) a[i]^=a[rev[i]]^=a[i]^=a[rev[i]]; 
	}
	for(int md=1;md<n;md<<=1){
		int tmp=qp(3,(MOD-1)/(md<<1));
		if(inv==-1) tmp=qp(tmp,MOD-2);
		for(int i=0;i<n;i+=md<<1)
			for(int omega=1,j=0;j<md;++j,omega=omega*tmp%MOD){
				int x=a[i+j],y=omega*a[i+j+md]%MOD;
				a[i+j]=(x+y)%MOD;a[i+j+md]=(x-y+MOD)%MOD;
			}
	}
}
signed main(){
	read(n);read(x);read(y);for(int i=0;i<=n;++i) read(A),++f[A],++g[x-A];
	for(;(1<<bit)<=(x<<1);++bit);
	ntt(f,1<<bit,1);ntt(g,1<<bit,1);
	for(int i=0;i<(1<<bit);++i) f[i]=f[i]*g[i]%MOD;
	ntt(f,1<<bit,-1);
	for(int i=1;i<=x;++i) if(f[i+x]*qp(1<<bit,MOD-2)%MOD) for(int j=1;(i+y)*2*j<o;++j) ans[(i+y)*2*j]=(i+y)*2;
	read(q);while(q--) read(l),write(ans[l]?ans[l]:-1),putchar(' ');
	return 0;
}