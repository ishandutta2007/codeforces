#include<bits/stdc++.h>
#define Cn const
#define CI Cn int&
#define N 200000
using namespace std;
namespace FastIO
{
	#define FS 100000
	#define Tp template<typename Ty>
	#define Ts template<typename Ty,typename... Ar>
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	#define pc(c) (FC==FE&&(clear(),0),*FC++=c)
	int OT;char oc,FI[FS],FO[FS],OS[FS],*FA=FI,*FB=FI,*FC=FO,*FE=FO+FS;
	void clear() {fwrite(FO,1,FC-FO,stdout),FC=FO;}struct IO_Cl {~IO_Cl() {clear();}}CL;
	Tp void read(Ty& x) {x=0;while(!isdigit(oc=tc()));while(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts void read(Ty& x,Ar&... y) {read(x),read(y...);}
	Tp void writeln(Ty x) {while(OS[++OT]=x%10+48,x/=10);while(OT) pc(OS[OT--]);pc('\n');}
}using namespace FastIO;
int n,m,a[N+5],f[N+5],pre[N+5],dc,dv[N+5];set<int> G[N+5];multiset<int> H;
struct Data {int x,y,z;bool operator < (Cn Data& o) Cn {return x<o.x;}}s[N+5];
class SegmentTree
{
	private:
		#define PT int l=1,int r=n,int o=1
		#define LT l,u,o<<1
		#define RT u+1,r,o<<1|1
		int V[N<<2];
	public:
		void Bd(PT) {if(V[o]=n+1,l==r) return;int u=l+r>>1;Bd(LT),Bd(RT);}
		void U(int L,int R,int v,PT)
		{
			if(v>=V[o]) return;if(L<=l&&r<=R) return (void)(V[o]=v);
			int u=l+r>>1;L<=u&&(U(L,R,v,LT),0),R>u&&(U(L,R,v,RT),0);
		}
		void G(int v=n,PT)
		{
			if(v=min(v,V[o]),l==r) return (void)(f[l]=v);int u=l+r>>1;G(v,LT),G(v,RT);
		}
}S;
int main()
{
	int Tt,i,j,x,y,c,lim,ans;read(Tt);while(Tt--)
	{
		for(read(n,m),i=1;i<=n;++i) read(a[i]),dv[i]=a[i];
		#define GV(x) (lower_bound(dv+1,dv+dc+1,x)-dv)
		sort(dv+1,dv+n+1),dc=unique(dv+1,dv+n+1)-dv-1;for(i=1;i<=dc;++i) G[i].clear();
		for(i=1;i<=n;++i) a[i]=GV(a[i]),pre[i]=G[a[i]].empty()?-1:*--G[a[i]].end(),G[a[i]].insert(i);
		for(S.Bd(),i=1;i<=m;++i) read(x,y),S.U(x,y,x);S.G();
		for(c=0,i=1;i<=n;++i) pre[i]>=f[i]&&(s[++c]=(Data){*G[a[i]].lower_bound(f[i]),pre[i],i},0);
		for(sort(s+1,s+c+1),H.clear(),i=1;i<=c;++i) H.insert(s[i].y);if(!c) {writeln(0);continue;}
		for(ans=lim=n,i=j=1;i<=lim;++i)
		{
			while(j<=c&&s[j].x<i) H.erase(H.find(s[j].y)),H.insert(s[j].z),lim=min(lim,s[j].z),++j;
			ans=min(ans,*--H.end()-i+1);
		}writeln(ans);
	}return 0;
}