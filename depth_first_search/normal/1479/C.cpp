#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 32
#define Add(x,y,z) (tot+=sprintf(s+tot,"%d %d %d\n",x,y,z),++cnt)
using namespace std;
int L,R,cnt,tot;char s[10000000];
int main()
{
	RI i,j,t;scanf("%d%d",&L,&R),puts("YES"),Add(1,22,L);
	for(i=1;i<=20;++i) for(t=i^1?1<<i-2:L,j=i+1;j<=21;++j) Add(i,j,t);
	for(t=R-L,i=2;i<=21;++i) t>>(i-2)&1&&(t^=1<<i-2,Add(i,22,t+1));
	End:return printf("22 %d\n",cnt),puts(s),0;
}