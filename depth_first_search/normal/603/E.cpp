#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 100000
#define M 300000
using namespace std;
int n,m;struct line {int p,x,y,v;I bool operator < (Con line& o) Con {return v<o.v;}}s[M+5];
namespace U
{
	int tot,f[N+5],g[N+5],v[N+5];I int fa(CI x) {return f[x]?fa(f[x]):x;}
	int T,Sx[M+5],Sy[M+5],Sg[M+5],Sv[M+5];I void Union(RI x,RI y)
	{
		if(++T,(x=fa(x))==(y=fa(y))) return (void)(Sx[T]=-1);;
		g[x]<g[y]&&(x^=y^=x^=y),Sx[T]=x,Sy[T]=y,Sg[T]=g[x],Sv[T]=v[x],
		v[x]&&v[y]&&(tot-=2),g[x]==g[y]&&++g[x],v[x]^=v[y],f[y]=x;
	}
	I void Back() {~Sx[T]&&(f[Sy[T]]=0,g[Sx[T]]=Sg[T],(v[Sx[T]]=Sv[T])&&v[Sy[T]]&&(tot+=2)),--T;}
}
int ans[M+5];line p[M+5];I void Solve(CI l,CI r,CI Mn)
{
	#define Revoke() W(U::T^O) U::Back()
	if(l>r) return;RI i,mid=l+r>>1,O=U::T;
	for(i=l;i<=mid;++i) s[i].p<Mn&&(U::Union(s[i].x,s[i].y),0);
	for(i=Mn;i<=m;++i) if(p[i].p<=mid&&(U::Union(p[i].x,p[i].y),0),!U::tot) {ans[mid]=i;break;}
	Revoke();for(i=l;i<=mid;++i) s[i].p<Mn&&(U::Union(s[i].x,s[i].y),0);Solve(mid+1,r,Mn);
	Revoke();if(!ans[mid]) return;for(i=Mn;i<=ans[mid];++i) p[i].p<l&&(U::Union(p[i].x,p[i].y),0);
	Solve(l,mid-1,ans[mid]);Revoke();
}
int main()
{
	RI i;for(scanf("%d%d",&n,&m),U::tot=n,i=1;i<=n;++i) U::v[i]=1;
	for(i=1;i<=m;++i) scanf("%d%d%d",&s[i].x,&s[i].y,&s[i].v),(p[i]=s[i]).p=i;
	for(sort(p+1,p+m+1),i=1;i<=m;++i) s[p[i].p].p=i;
	for(Solve(1,m,1),i=1;i<=m;++i) ans[i]?printf("%d\n",p[ans[i]].v):puts("-1");return 0;
}