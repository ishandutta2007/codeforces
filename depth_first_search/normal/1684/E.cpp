#include<bits/stdc++.h>
#define Cn const
#define CI Cn int&
#define N 100000
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
int n,m,k,a[N+5],p[N+5];pair<int,int> w[N+5];map<int,int> C;
int main()
{
	int Tt,i,j,c,d,t,ans;read(Tt);while(Tt--)
	{
		for(C.clear(),read(n,k),i=1;i<=n;++i) read(a[i]),++C[a[i]];
		m=0;for(map<int,int>::iterator it=C.begin();it!=C.end();++it) w[++m]=make_pair(it->second,it->first);
		for(i=0;i<=n;++i) p[i]=0;for(sort(w+1,w+m+1),i=1;i<=m;++i) w[i].second<=n&&(p[w[i].second]=i);
		for(i=j=c=t=d=0,ans=1e9;i<=n;++i)
		{
			if(i) {if(p[i-1]) p[i-1]<=j&&(--c,t-=w[p[i-1]].first);else if(++d>k) break;}
			while(j<m&&(w[j+1].second<i||t+w[j+1].first<=k)) ++j,w[j].second>=i&&(t+=w[j].first,++c);
			ans=min(ans,m-c+d-i);
		}writeln(ans);
	}return 0;
}