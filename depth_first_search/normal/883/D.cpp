#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 1000000
using namespace std;
int n,m,c,w[N+5],g[N+5],p[N+5];char s[N+5];
int f[N+5];I bool Check(CI x)
{
	RI i;for(i=1;i<=c;++i) f[i]=0,(w[i]<=x||f[i-1]>=p[w[i]-x-1])&&(f[i]=p[w[i]]),
		i^1&&(w[i]<=x||f[i-2]>=p[w[i]-x-1])&&(f[i]=max(f[i],p[min(w[i-1]+x,n)])),f[i-1]>=p[w[i]-1]&&(f[i]=p[min(w[i]+x,n)]);
	return f[c]>=m;
}
int main()
{
	RI i;for(scanf("%d%s",&n,s+1),i=1;i<=n;++i) s[i]=='P'&&(w[++c]=i);
	if(c==1)
	{
		RI p1=0,t1=0;for(i=w[1]-1;i;--i) s[i]=='*'&&(++t1,p1=w[1]-i);RI p2=0,t2=0;for(i=w[1]+1;i<=n;++i) s[i]=='*'&&(++t2,p2=i-w[1]);
		if(t1==t2) printf("%d %d\n",t1,min(p1,p2));else t1>t2?printf("%d %d\n",t1,p1):printf("%d %d\n",t2,p2);return 0;
	}
	RI l=0,r=n,mid;for(i=1;i<=n;++i) s[i]=='*'&&(g[++m]=i),p[i]=m;W(l^r) Check(mid=l+r-1>>1)?r=mid:l=mid+1;return printf("%d %d\n",m,r),0;
}