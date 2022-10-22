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
int n,t,a[10],b[N+5];
struct Data
{
	int x,y;I bool operator < (Con Data& o) Con {return b[x]-a[y]<b[o.x]-a[o.y];}
}s[6*N+5];
I bool cmp(CI x,CI y) {return x>y;}
int main()
{
	RI i,j;for(i=1;i<=6;++i) scanf("%d",a+i);for(scanf("%d",&n),i=1;i<=n;++i) scanf("%d",b+i);
	RI Mx=0;for(sort(a+1,a+7,cmp),i=1;i<=n;++i) Mx=max(Mx,b[i]-a[1]);
	for(i=1;i<=n;++i) for(j=1;j<=6;++j) s[++t].x=i,s[t].y=j;sort(s+1,s+t+1);
	RI ans=2e9;for(i=1;i<=t;++i)
	{
		if(ans=min(ans,Mx-(b[s[i].x]-a[s[i].y])),s[i].y==6) break;
		Mx=max(Mx,b[s[i].x]-a[s[i].y+1]);
	}return printf("%d\n",ans),0;
}