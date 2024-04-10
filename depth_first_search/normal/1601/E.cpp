#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 300000
#define LL long long
using namespace std;
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
int n,k,Qt,a[N+5],v[N+5],Q[N+5],T,S[N+5];LL ans[N+5],G[N+5];
vector<pair<int,int> > q[N+5];vector<pair<int,int> >::iterator it;
I void Init() {RI i,H=1,T=0;for(i=n;i;--i) {W(H<=T&&Q[H]>=i+k) ++H;W(H<=T&&a[Q[T]]>a[i]) --T;Q[++T]=i,v[i]=a[Q[H]];}}
I int F1(CI a) {RI l=1,r=T+1,u;W(l^r) v[S[u=l+r>>1]]>=a?r=u:l=u+1;return r;}
I int F2(CI i) {RI l=1,r=T+1,u;W(l^r) S[u=l+r>>1]<=i?r=u:l=u+1;return r;}
int main()
{
	RI i,j;for(read(n,Qt,k),i=1;i<=n;++i) read(a[i]);Init();
	RI x,y;for(i=1;i<=Qt;++i) read(x,y),y-x+1>k?(q[x].push_back(make_pair(i,y)),0):ans[i]=a[x];
	for(RI d=0;d^k;++d) for(T=0,i=n-d;i>=1;i-=k)
	{
		W(T&&v[S[T]]>v[i]) --T;S[++T]=i,G[T]=G[T-1]+1LL*(S[T-1]-S[T])/k*v[i];
		for(it=q[i-1].begin();it!=q[i-1].end();++it)
		{
			if(j=i-2+((it->second-(i-2)-1)/k+1)*k-(k-2),x=F1(a[i-1]),y=F2(j),x<=y) ans[it->first]=1LL*a[i-1]*((j-i)/k+1);
			else ans[it->first]=1LL*a[i-1]*((S[x-1]-i)/k+1)+G[x-1]-G[y]+1LL*v[S[y]]*((j-S[y])/k);
		}
	}
	for(i=1;i<=Qt;++i) writeln(ans[i]);return clear(),0;
}