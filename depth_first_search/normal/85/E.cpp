#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 5000
#define X 1000000007
using namespace std;
int n;struct P {int x,y;}p[N+5];
int c[N+5];I bool Col(CI x,CI v) {for(RI i=1;i<=n;++i)
	if(abs(p[x].x-p[i].x)+abs(p[x].y-p[i].y)>v&&(~c[i]?c[i]==c[x]:(c[i]=c[x]^1,!Col(i,v)))) return 0;return 1;}
int res;I bool Check(CI v) {RI i;for(i=1;i<=n;++i) c[i]=-1;
	for(res=i=1;i<=n;++i) if(!~c[i]&&(res=2LL*res%X,c[i]=1,!Col(i,v))) return 0;return 1;}
int main()
{
	RI i;for(scanf("%d",&n),i=1;i<=n;++i) scanf("%d%d",&p[i].x,&p[i].y);
	RI l=0,r=1e4,mid;W(l^r) Check(mid=l+r-1>>1)?r=mid:l=mid+1;return Check(r),printf("%d\n%d\n",r,res),0;
}