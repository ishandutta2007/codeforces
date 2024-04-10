#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define R(x) (1LL*rand()*rand()*rand()%(x)+1)
using namespace std;
int n,k;I int Q(CI a,CI b,CI c,CI d)
{
	printf("? %d %d\n",b-a+1,d-c+1);for(RI i=a;i<=b;++i) printf("%d%c",i," \n"[i==b]);for(RI i=c;i<=d;++i) printf("%d%c",i," \n"[i==d]);
	fflush(stdout);string res;return cin>>res,res[0]=='F'?1:(res[0]=='S'?-1:0);
}
int main()
{
	srand(888);RI Tt,i,x;scanf("%d",&Tt);W(Tt--)
	{
		scanf("%d%d",&n,&k);for(i=1;i<=30;++i) if(x=R(n),x^1&&Q(1,1,x,x)==-1) {puts("! 1");goto E;}
		for(i=0;(1<<i+1)<=n&&!Q(1,1<<i,(1<<i)+1,1<<i+1);++i);
		for(x=1<<i--;~i;--i) x+(1<<i)<=n&&!Q(1,1<<i,x+1,x+(1<<i))&&(x+=1<<i);printf("! %d\n",x+1);E:fflush(stdout);
	}return 0;
}