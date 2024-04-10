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
template<class T1,class T2>inline T1 max(T1 a,T2 b){return a>b?a:b;}
template<class T1,class T2>inline T1 min(T1 a,T2 b){return a<b?a:b;}
const int o=101;
int q,n,m,L,H,T;
struct cust{int t,l,h;}c[o];
inline bool comp(cust A,cust B){return A.t<B.t;}
inline void slv(){
	read(n);read(m);T=0;L=H=m;
	for(int i=1;i<=n;++i) read(c[i].t),read(c[i].l),read(c[i].h);
	sort(c+1,c+1+n,comp);
	for(int i=1;i<=n;++i){
		if(H+c[i].t-T<c[i].l||L-c[i].t+T>c[i].h){printf("NO\n");return;}
		L=max(c[i].l,L-c[i].t+T);H=min(c[i].h,H+c[i].t-T);T=c[i].t;
	}
	printf("YES\n");
}
int main(){read(q);while(q--) slv();return 0;}