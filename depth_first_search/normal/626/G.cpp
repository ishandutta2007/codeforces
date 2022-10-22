#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 200000
#define DB double
#define eps 1e-12
using namespace std;
int n,m,p[N+5],l[N+5],s[N+5];DB ans;
struct Data
{
	int id;DB x;I Data(CI i=0,Con DB& a=1):id(i),x(a){}
	I bool operator < (Con Data& o) Con {return fabs(x-o.x)>eps?x<o.x:id<o.id;}
};set<Data> S[2];
#define Calc(i,s) (1.0*p[i]*(s)/(l[i]+(s)))
#define A(i) Calc(i,s[i]+1)-Calc(i,s[i])
#define D(i) Calc(i,s[i])-Calc(i,s[i]-1)
I void Add()
{
	RI k=(--S[1].end())->id;ans+=(--S[1].end())->x,
	S[1].erase(--S[1].end()),s[k]&&(S[0].erase(Data(k,D(k))),0),
	++s[k]^l[k]&&(S[1].insert(Data(k,A(k))),0),S[0].insert(Data(k,D(k)));
}
I void Del()
{
	RI k=S[0].begin()->id;ans-=S[0].begin()->x;
	S[0].erase(S[0].begin()),s[k]^l[k]&&(S[1].erase(Data(k,A(k))),0),
	--s[k]&&(S[0].insert(Data(k,D(k))),0),S[1].insert(Data(k,A(k)));
}
int main()
{
	RI Qt,i,t=0,op,x,y;for(scanf("%d%d%d",&n,&m,&Qt),i=1;i<=n;++i) scanf("%d",p+i);
	for(i=1;i<=n;++i) scanf("%d",l+i),S[1].insert(Data(i,A(i)));
	W(t^m&&S[1].size()) Add(),++t;W(Qt--&&~scanf("%d%d",&op,&x))
	{
		s[x]^l[x]&&(S[1].erase(Data(x,A(x))),0),s[x]&&(S[0].erase(Data(x,D(x))),0);
		if(ans-=Calc(x,s[x]),op==1) {if(++l[x],t^m) {++s[x],ans+=Calc(x,s[x]),++t;goto End;}}
		else if(--l[x],s[x]>l[x]) {--s[x],ans+=Calc(x,s[x]),S[1].size()?(Add(),0):--t;goto End;}
		ans+=Calc(x,s[x]);W(s[x]&&S[1].size()&&D(x)<(--S[1].end())->x) ans-=D(x),--s[x],Add();
		W(s[x]^l[x]&&S[0].size()&&A(x)>S[0].begin()->x) ans+=A(x),++s[x],Del();
		End:s[x]^l[x]&&(S[1].insert(Data(x,A(x))),0),s[x]&&(S[0].insert(Data(x,D(x))),0);
		printf("%.15lf\n",ans);
	}return 0;
}