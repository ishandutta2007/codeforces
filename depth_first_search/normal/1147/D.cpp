#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 1000
#define X 998244353
using namespace std;
int n,m,fg,ct,c[2*N+5],u[2*N+5],v[2*N+5];char s[N+5];vector<int> g0[2*N+5],g1[2*N+5];
I bool Col(CI x)
{
	for(vector<int>::iterator it=g0[x].begin();it!=g0[x].end();++it) if(~c[*it]?c[*it]^c[x]:(c[*it]=c[x],!Col(*it))) return 0;
	for(vector<int>::iterator it=g1[x].begin();it!=g1[x].end();++it) if(~c[*it]?c[*it]==c[x]:(c[*it]=c[x]^1,!Col(*it))) return 0;return 1;
}
int main()
{
	RI i,j,t,ans=0;for(scanf("%s",s+1),n=strlen(s+1),m=1;m^n;++m)
	{
		#define add0(x,y) (g0[x].push_back(y),g0[y].push_back(x))
		#define add1(x,y) (g1[x].push_back(y),g1[y].push_back(x))
		for(i=0;i<=n+m;++i) c[i]=u[i]=v[i]=-1,g0[i].clear(),g1[i].clear();
		for(i=1;i<n-i+1;++i) add0(i,n-i+1);for(i=1;i<m-i+1;++i) add0(n+i,n+m-i+1);
		for(i=1;i<=m;++i) s[i]=='0'&&(add0(i,n+i),0),s[i]=='1'&&(add1(i,n+i),0);for(v[n+m]=1,i=m+1;i<=n;++i) s[i]^'?'&&(v[i]=s[i]&1);
		for(ct=0,fg=i=1;i<=n+m;++i) if(!~c[i]&&(c[i]=ct,ct+=2,!Col(i))) break;
		if(fg) for(i=1;i<=n+m;++i) if(~v[i]) if(!~u[c[i]]) u[c[i]]=v[i];else if(u[c[i]]^v[i]) {fg=0;break;}
		if(fg) {for(t=1,i=0;i^ct;i+=2) if(~u[i]&&u[i]==u[i+1]) {t=0;break;}else !~u[i]&&!~u[i+1]&&(t=2*t%X);ans=(ans+t)%X;}
	}return printf("%d\n",ans),0;
}