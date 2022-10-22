#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 1000
using namespace std;
int n,x[N+5],y[N+5],p[N+5],c[4];
int main()
{
	RI i,t=0;for(scanf("%d",&n),i=1;i<=n;++i) scanf("%d%d",x+i,y+i);W(true)
	{
		for(c[0]=c[1]=c[2]=c[3]=0,i=1;i<=n;++i) ++c[p[i]=(x[i]&1)<<1|(y[i]&1)];
		if((c[0]||c[3])&&(c[1]||c[2])) {for(printf("%d\n",c[1]+c[2]),i=1;i<=n;++i) (p[i]==1||p[i]==2)&&printf("%d ",i);break;}
		if(c[0]&&c[3]) {for(printf("%d\n",c[3]),i=1;i<=n;++i) p[i]==3&&printf("%d ",i);break;}
		if(c[1]&&c[2]) {for(printf("%d\n",c[2]),i=1;i<=n;++i) p[i]==2&&printf("%d ",i);break;}
		for(i=1;i<=n;++i) x[i]>>=1,y[i]>>=1;
	}return 0;
}