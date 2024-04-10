#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 200000
using namespace std;
int n,a[N+5],c[N+5],s[N+5],p[N+5];vector<int> g[N+5];
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	char oc,FI[FS],*FA=FI,*FB=FI;
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
}using namespace FastIO;
int m,ans,w[2*N+5];I void Solve()
{
	RI i;for(i=0;i<=2*m;++i) w[i]=-1;w[m]=p[1];
	RI v=m;for(i=2;i^m;++i) ~w[v+=s[i]]?ans=max(ans,p[i+1]-1-w[v]):w[v]=p[i];
}
int main()
{
	RI i,t=0;for(read(n),i=1;i<=n;++i) read(a[i]),g[a[i]].push_back(i),++c[a[i]]>c[t]&&(t=a[i]);
	RI j,k,x,y,o;for(i=1;i<=n;++i) if(i^t&&c[i])
	{
		#define Set(j) (s[++m]=a[j]==t?1:(a[j]==i?-1:0),p[m]=j)
		if(m=0,1LL*c[i]*c[i]>n) {for(j=0;j<=n+1;++j) Set(j);Solve();continue;}
		for(j=0;j^c[i];++j)
		{
			o=upper_bound(g[t].begin(),g[t].end(),g[i][j])-g[t].begin(),x=0,y=max(o-(j+1),0);
			if(y) for(;x<=j&&g[i][x]<g[t][y-1];++x);if(o<=c[t]-1) for(k=1;k<=j&&o<c[t]-1&&(j==c[i]-1||g[t][o+1]<g[i][j+1]);++k) ++o;else --o;
			m=0,Set(max(x?g[i][x-1]:0,y?g[t][y-1]:0));
			W(x<=j||y<=o) x<=j&&(y>o||g[i][x]<g[t][y])?(Set(g[i][x]),++x):(Set(g[t][y]),++y);
			Set(min(j==c[i]-1?n+1:g[i][j+1],o==c[t]-1?n+1:g[t][o+1])),Solve();
		}
	}return printf("%d\n",ans),0;
}