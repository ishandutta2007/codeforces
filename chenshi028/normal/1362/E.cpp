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
const int o=1e6+10,MOD=1e9+7;
int T,n,p,k[o];bool inf;long long v,s;
long long qp(int b,int f){
	if(!f) return 1ll;
	long long rcd=qp(b,f>>1);
	return rcd*rcd%MOD*(f&1?b:1ll)%MOD;
}
inline int min(int a,int b){return a<b?a:b;} 
int main(){
	read(T);while(T--){
		read(n);read(p);
		for(int i=1;i<=n;++i) read(k[i]);
		sort(k+1,k+1+n);v=s=inf=0;k[n+1]=o;
		for(int i=n;i>=1;--i){
			s*=qp(p,k[i+1]-k[i]);
			for(int j=1;j<=min(k[i+1]-k[i],20);++j){v*=p;if(v>n) inf=1;}
			for(;i&&i-1&&k[i]==k[i-1];--i) if(inf||v>0){--v;--s;continue;}else ++v,++s;
			if(inf||v>0) --v,--s;else ++v,++s;
			s=(s+MOD)%MOD;
		}
		write(s*qp(p,k[1])%MOD);putchar('\n');
	}
	return 0;
}