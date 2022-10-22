#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 2000
using namespace std;
int n,w,lim,ql,qr,id[N+5],ans[N+5],ct,f[N+5];
I int Q(CI l1,CI r1,CI l2,CI r2)
{
	printf("? %d %d\n",r1-l1+1,r2-l2+1);
	for(RI i=l1;i<=r1;++i) printf("%d ",id[i]);putchar('\n');
	for(RI i=l2;i<=r2;++i) printf("%d ",id[i]);putchar('\n'),fflush(stdout);
	RI t;scanf("%d",&t);return t;
}
int main()
{
	RI Tt,i,x,l,r,u;srand(324682339),scanf("%d",&Tt);W(Tt--)
	{
		for(scanf("%d",&n),i=1;i<=n;++i) f[id[i]=i]=0;random_shuffle(id+1,id+n+1);
		for(i=n-1;!Q(i,i,i+1,n);--i);for(f[x=i--]=1;i;--i) f[i]=Q(i,i,x,x);
		l=x+1,r=n;W(l^r) u=l+r-1>>1,Q(x,x,x+1,u)?r=u:l=u+1;f[r]=1;
		for(ct=0,i=1;i<=n;++i) !f[i]&&(ans[++ct]=id[i]);sort(ans+1,ans+ct+1);
		for(printf("! %d ",ct),i=1;i<=ct;++i) printf("%d ",ans[i]);putchar('\n'),fflush(stdout);
	}return 0;
}