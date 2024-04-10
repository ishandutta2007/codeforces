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
const int o=1e6+10;
int n,a[o],pos[o],x[o],y[o],tp;struct elm{int idx,v,rk;}m[o];
inline bool cmp1(elm A,elm B){return A.v<B.v||(A.v==B.v&&A.idx<B.idx);}
inline bool cmp2(elm A,elm B){return A.idx<B.idx;}
#define swp(lt,rt) a[lt]^=a[rt],a[rt]^=a[lt],a[lt]^=a[rt]
int main(){
	read(n);for(int i=1;i<=n;++i) read(m[i].v),m[i].idx=i;
	sort(m+1,m+1+n,cmp1);for(int i=1;i<=n;++i) m[i].rk=i;
	sort(m+1,m+1+n,cmp2);for(int i=1;i<=n;++i) a[i]=m[i].rk;
	for(;n;--n){
		for(int i=1;i<=n;++i) pos[a[i]]=i;
		for(int i=a[n]+1;i<=n;++i) x[++tp]=pos[i],y[tp]=n,swp(pos[i],n);
	}
	write(tp);putchar('\n');for(int i=1;i<=tp;++i) write(x[i]),putchar(' '),write(y[i]),putchar('\n');
	return 0;
}