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
#define S 320
using namespace std;
int n,m,Qt,o[2*N+5],ans[N+5];map<int,int> p[N+5];struct node {int x,y;}q[N+5];
vector<node> s[N+5];vector<node>::iterator it;
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	#define pc(c) (FC==FE&&(clear(),0),*FC++=c)
	int OT;char oc,FI[FS],FO[FS],OS[FS],*FA=FI,*FB=FI,*FC=FO,*FE=FO+FS;
	I void clear() {fwrite(FO,1,FC-FO,stdout),FC=FO;}
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
	Tp I void writeln(Ty x) {W(OS[++OT]=x%10+48,x/=10);W(OT) pc(OS[OT--]);pc('\n');}
}using namespace FastIO;
namespace U
{
	int f[N+5];I int fa(CI x) {return f[x]^x?f[x]=fa(f[x]):x;}
	I void Union(RI x,RI y) {(x=fa(x))^(y=fa(y))&&(f[y]=x);}
	I bool Chk(CI x,CI y) {return f[x]&&f[y]&&fa(x)==fa(y);}
}
int main()
{
	RI i,x,y,z;for(read(n,m),i=1;i<=m;++i) read(x,y,z),s[z].push_back((node){x,y});
	RI t,sz=sqrt(n/log2(n));for(read(Qt),i=1;i<=Qt;++i) read(q[i].x,q[i].y);for(i=1;i<=m;++i)
	{
		for(t=0,it=s[i].begin();it!=s[i].end();++it) o[++t]=it->x,o[++t]=it->y;
		for(sort(o+1,o+t+1),t=unique(o+1,o+t+1)-o-1,x=1;x<=t;++x) U::f[o[x]]=o[x];
		for(it=s[i].begin();it!=s[i].end();++it) U::Union(it->x,it->y);
		if(s[i].size()>sz) for(x=1;x<=Qt;++x) U::Chk(q[x].x,q[x].y)&&++ans[x];
		else for(x=1;x<=t;++x) for(y=x+1;y<=t;++y) U::Chk(o[x],o[y])&&++p[o[x]][o[y]];
		for(x=1;x<=t;++x) U::f[o[x]]=0;
	}
	for(i=1;i<=Qt;++i) printf("%d\n",ans[i]+p[q[i].x][q[i].y]+p[q[i].y][q[i].x]);return 0;
}