#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 500000
#define LL long long
using namespace std;
int n,m;
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	#define pc(c) (FC==FE&&(clear(),0),*FC++=c)
	int OT;char oc,FI[FS],FO[FS],OS[FS],*FA=FI,*FB=FI,*FC=FO,*FE=FO+FS;
	I void clear() {fwrite(FO,1,FC-FO,stdout),FC=FO;}
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
	I void readc(char& x) {W(isspace(x=tc()));}
	Tp I void writeln(Ty x) {W(OS[++OT]=x%10+48,x/=10);W(OT) pc(OS[OT--]);pc('\n');}
}using namespace FastIO;
int f0[N+5],g0[N+5],t0[N+5],f1[N+5],g1[N+5],t1[N+5],tg[N+5];vector<pair<int,LL> > v[N+5];
I int fa(int* f,CI x) {return f[x]?fa(f,f[x]):x;}
I int QT(CI x,CI t) {return max(f1[x]?QT(f1[x],t1[x]):0,tg[x]>=t?tg[x]:0);}
I LL QS(CI x,CI t)
{
	LL s=f0[x]?QS(f0[x],max(t,t0[x])):0;if(v[x].empty()||v[x].back().first<t) return s;s+=v[x].back().second;
	if(v[x][0].first>=t) return s;return s-(--lower_bound(v[x].begin(),v[x].end(),make_pair(t,0LL)))->second;
}
int main()
{
	RI Tt,i;for(read(n,Tt),i=1;i<=n;++i) g0[i]=g1[i]=1;
	char op;RI x,y;for(RI T=1;T<=Tt;++T) switch(readc(op),op)
	{
		case 'U':read(x,y),(x=fa(f0,x))^(y=fa(f0,y))&&(g0[x]<g0[y]&&(swap(x,y),0),g0[f0[y]=x]+=g0[y],t0[y]=T);break;
		case 'M':read(x,y),(x=fa(f1,x))^(y=fa(f1,y))&&(g1[x]<g1[y]&&(swap(x,y),0),g1[f1[y]=x]+=g1[y],t1[y]=T);break;
		case 'A':read(x),x=fa(f0,x),v[x].push_back(make_pair(T,(v[x].empty()?0:v[x].back().second)+g0[x]));break;
		case 'Z':read(x),x=fa(f1,x),tg[x]=max(tg[x],T);break;case 'Q':read(x),writeln(QS(x,QT(x,0)));break;
	}return clear(),0;
}