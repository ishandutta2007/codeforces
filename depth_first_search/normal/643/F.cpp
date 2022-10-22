#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define P 130
#define LL long long
using namespace std;
int n,p,q,a[P+5],b[P+5];unsigned C[P+5];
I int gcd(CI x,CI y) {return y?gcd(y,x%y):x;}
int main()
{
	RI i,j,k,g;for(scanf("%d%d%d",&n,&p,&q),p=min(p,n-1),i=0;i<=p;++i)
	{
		for(j=1;j<=i;++j) a[j]=n-j+1,b[j]=j;
		for(j=1;j<=i;++j) for(k=1;k<=i;++k) g=gcd(a[j],b[k]),a[j]/=g,b[k]/=g;
		for(C[i]=j=1;j<=i;++j) C[i]*=a[j];
	}
	unsigned w,t,s=0;for(i=1;i<=q;s^=i*t,++i) for(w=1,t=j=0;j<=p;w*=i,++j) t+=C[j]*w;
	return printf("%u\n",s),0;
}