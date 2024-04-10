#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 100000
#define X 998244353
#define C(x,y) (1LL*Fc[x]*Ic[y]%X*Ic[(x)-(y)]%X)
using namespace std;
int n,f[N+5],g[N+5],Fc[N+5],Ic[N+5];char s[N+5][2];
I int QP(RI x,RI y) {RI t=1;W(y) y&1&&(t=1LL*t*x%X),x=1LL*x*x%X,y>>=1;return t;}
int main()
{
	RI i,t=0;for(scanf("%d",&n),i=1;i<=n;++i) scanf("%s",s[i]);
	for(Fc[0]=i=1;i<=n;++i) Fc[i]=1LL*Fc[i-1]*i%X;for(Ic[i=n]=QP(Fc[n],X-2);i;--i) Ic[i-1]=1LL*Ic[i]*i%X;
	for(i=1;i<=n;++i) if(s[i][0]=='W'||s[i][1]=='B') break;i>n&&++t;
	for(i=1;i<=n;++i) if(s[i][0]=='B'||s[i][1]=='W') break;i>n&&++t;
	RI c=0,cW=0,cB=0,cWW=0,cBB=0;for(i=1;i<=n;++i)
		s[i][0]=='?'&&s[i][1]=='?'&&++c,s[i][0]=='W'&&s[i][1]=='W'&&++cWW,s[i][0]=='B'&&s[i][1]=='B'&&++cBB,
		(s[i][0]=='W'&&s[i][1]=='?'||s[i][0]=='?'&&s[i][1]=='W')&&++cW,(s[i][0]=='B'&&s[i][1]=='?'||s[i][0]=='?'&&s[i][1]=='B')&&++cB;
	for(cW+=c,cB+=c,i=max(max(cWW,cBB),1);i<=min(cWW+cW,cBB+cB);++i) t=(t+1LL*C(cW,i-cWW)*C(cB,i-cBB))%X;
	if(!cWW&&!cBB) for(i=1;i<=c;++i) t=(t-C(c,i)+X)%X;return printf("%d\n",t),0;
}