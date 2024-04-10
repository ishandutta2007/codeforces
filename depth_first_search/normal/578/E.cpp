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
using namespace std;
int n,v[N+5];char s[N+5];set<int> S[2];
I int Solve(RI x)
{
	RI i,t=0;for(i=1;i<=n;++i) S[s[i]=='R'].insert(i);
	#define Nxt(x,p) S[x].lower_bound(p)
	#define Mn(x) *S[x].begin()
	RI p=0;for(i=1;i<=n;S[x].erase(v[i]=p),++i,x^=1)
		p=Nxt(x,p)==S[x].end()?(++t,Mn(x)):*Nxt(x,p),
		Nxt(x^1,p)==S[x^1].end()&&p^Mn(x)&&Mn(x)<Mn(x^1)&&(p=Mn(x),++t);
	return t;
}
int main()
{
	RI i,t=0;for(scanf("%s",s+1),n=strlen(s+1),i=1;i<=n;++i) s[i]=='L'?++t:--t;
	for(printf("%d\n",t?Solve(t==-1):Solve(s[1]=='R')),i=1;i<=n;++i) printf("%d ",v[i]);return 0;
}