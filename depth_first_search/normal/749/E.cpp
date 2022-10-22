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
#define DB double
#define LL long long
using namespace std;
int n,a[N+5];
struct TreeArray
{
	LL a[N+5];I void U(RI x,CI v) {W(x) a[x]+=v,x-=x&-x;}
	I LL Q(RI x,LL t=0) {W(x<=n) t+=a[x],x+=x&-x;return t;}
}C,S;
int main()
{
	RI i;LL t=0;DB g=0;for(scanf("%d",&n),i=1;i<=n;++i)
		scanf("%d",a+i),t+=C.Q(a[i]),g-=1.0*S.Q(a[i])*(n-i+1),C.U(a[i],1),S.U(a[i],i);
	for(i=1;i<=n;++i) g+=1.0*(n-i+1)*i*(i-1)/4;
	return printf("%.12lf\n",t+g/(1LL*n*(n+1)/2)),0;
}