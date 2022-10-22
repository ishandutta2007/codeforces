#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define X 1000000007
using namespace std;
const int Pt=19,P[19]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};
struct LB {int v[Pt];I bool A(RI x) {for(RI i=Pt-1;~i;--i) if(x>>i&1) {if(v[i]) x^=v[i];else return v[i]=x;}return 0;}}B;
int main()
{
	RI n,i,x,v,t=0;scanf("%d",&n);W(n--) {for(scanf("%d",&x),v=i=0;i^Pt;++i) W(!(x%P[i])) x/=P[i],v^=1<<i;!B.A(v)&&++t;}
	RI p=1;for(i=1;i<=t;++i) p=2LL*p%X;return printf("%d\n",p-1),0;
}