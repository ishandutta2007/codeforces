#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353,MAX_N=5+3e5;
inline void mo(int& x){x>=MOD?x-=MOD:0;}
inline int mo1(int x){ return x>=MOD?x-MOD:x; }
inline int fpow(int x,int n,int ret=1){
	for(;n;n>>=1,x=1ll*x*x%MOD)
		n&1?ret=1ll*ret*x%MOD:0;
	return ret;
}
int g[MAX_N],p[MAX_N],a[MAX_N],inv[MAX_N],n,m=0;
struct K{
	int a,b;
	K(){ a=b=0; }
	K(int _a,int _b){ a=_a,b=_b; }
	inline K operator+(int x){ return K(a,mo1(b+x)); }
	inline K operator-(int x){ return K(a,mo1(b+MOD-x)); }
	inline K operator+(K x){ return K(mo1(a+x.a),mo1(b+x.b)); }
	inline K operator-(K x){ return K(mo1(a+MOD-x.a),mo1(b+MOD-x.b)); }
	inline K operator*(int x){ return K(1ll*a*x%MOD,1ll*b*x%MOD); }
	inline K subs(K x){ return K(1ll*a*x.a%MOD,(1ll*a*x.b+b)%MOD); }
	inline int solve(){ return fpow(a,MOD-2,MOD-b); }
};
void get_g(){
	inv[1]=1;
	for(int i=2;i<=max(n,m);++i)
		inv[i]=1ll*(MOD-MOD/i)*inv[MOD%i]%MOD;
	static K g1[MAX_N];
	g1[0]=K(1,0);
	g1[1]=K(1,mo1(1+MOD-n));
	for(int i=1;i<m;++i)
		g1[i+1]=(g1[i]*(n-1)*m-g1[i]*(n-2)*(m-i)
			-g1[i-1]*(n-1)*i-1ll*m*(n-1)%MOD)*inv[m-i];
	g[0]=g1[m].solve();
	for(int i=1;i<=m;++i){
//		printf("[%d %d]",g1[i].a,g1[i].b);
		g[i]=g1[i].subs(K(0,g[0])).b;
	}
//	for(int i=0;i<=m;++i) printf("[%d]",g[i]);
}
void get_p(){
	static K p1[MAX_N];
	p1[1]=K(1,0);
	int invg0=fpow(g[0],MOD-2);
	for(int i=2;i<=n;++i)
		p1[i]=K(1,1ll*(g[a[1]]+MOD-g[a[i]])*invg0%MOD);
	K s(0,0);
	for(int i=1;i<=n;++i) s=s+p1[i];
	s=s-1;
	p[1]=s.solve();
	for(int i=2;i<=n;++i)
		p[i]=p1[i].subs(K(0,p[1])).b;
//	for(int i=1;i<=n;++i) printf("{%d}",p[i]); puts("");
	int ans=(g[a[1]]+MOD-1ll*g[0]*(1+MOD-p[1])%MOD)%MOD;
	printf("%d\n",ans);
}
int main(){
//	printf("|%d|",fpow(5,MOD-2,2));
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]),m+=a[i];
	get_g();
	get_p();
	return 0;
}