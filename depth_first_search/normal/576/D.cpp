#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 150
using namespace std;
int n,m;struct line {int x,y,t;I bool operator < (Con line& o) Con {return t<o.t;}}s[N+5];
struct M
{
	bitset<N+5> a[N+5],b[N+5];I M() {for(RI i=1;i<=n;++i) a[i].reset(),b[i].reset();}
	I void Set(CI x,CI y) {a[x].set(y),b[y].set(x);}
	I M operator * (Con M& o) Con
	{
		M t;for(RI i=1;i<=n;++i) for(RI j=1;j<=n;++j) (a[i]&o.b[j]).any()&&(t.Set(i,j),0);return t;
	}
}O,S,U;
I void QP(RI y) {M x=U;W(y) y&1&&(S=S*x,0),x=x*x,y>>=1;}
int main()
{
	RI i;for(scanf("%d%d",&n,&m),i=1;i<=m;++i) scanf("%d%d%d",&s[i].x,&s[i].y,&s[i].t);
	RI t=0;for(S.Set(1,1),O=S,sort(s+1,s+m+1),i=1;i<=m;O=S,t=s[i++].t)
		if(QP(s[i].t-s[i-1].t),U.Set(s[i].x,s[i].y),S.a[1].test(n)) break;
	for(i=1;i<=n&&!O.a[1].test(n);++i) O=O*U,++t;
	return O.a[1].test(n)?printf("%d\n",t):puts("Impossible"),0;
}