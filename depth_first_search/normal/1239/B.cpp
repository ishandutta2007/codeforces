#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con cosnt
#define CI Con int&
#define I inline
#define W while
#define N 300000
using namespace std;
int n,a[N+5],p[N+5];char s[N+5];
int main()
{
	RI i,Mn=n,res=0,ans=0,tx=1,ty=1;for(scanf("%d%s",&n,s+1),i=1;i<=n;++i)
		a[i]=s[i]=='('?1:-1,p[i]=p[i-1]+a[i],Mn>p[i]?(Mn=p[i],res=1):Mn==p[i]&&++res;
	if(p[n]) return puts("0\n 1 1"),0;ans=res;RI t=0,g=0;
	RI nxt1=n,nxt2=n;for(i=n-1;i;--i)
		p[i]==Mn?(t=0,nxt1=i):(t+=p[i]==Mn+1),
		(p[i]==Mn||p[i]==Mn+1)?(g=0,nxt2=i):(g+=p[i]==Mn+2),
		~a[i]&&(ans<t&&(ans=t,tx=i,ty=nxt1),ans<res+g&&(ans=res+g,tx=i,ty=nxt2));
	RI v=0,w=0,k=0;for(t=g=0,i=1;i<=n;++i) p[i]==Mn+1&&++t,p[i]==Mn+2&&++g;
	RI lim=t;for(nxt1=nxt2=i=1;i<=n;++i)
	{
		W(v^res) p[nxt1]==Mn&&++v,p[nxt1]==Mn+1&&--t,nxt1=nxt1%n+1;
		W(w^lim||k^res) p[nxt2]==Mn+1&&++w,p[nxt2]==Mn&&++k,p[nxt2]==Mn+2&&--g,nxt2=nxt2%n+1;
		!~a[i]&&ans<t&&(ans=t,tx=i,ty=nxt1),p[i]==Mn&&--v,p[i]==Mn+1&&++t,
		!~a[i]&&ans<res+g&&(ans=res+g,tx=i,ty=nxt2),p[i]==Mn+1&&--w,p[i]==Mn&&--k,p[i]==Mn+2&&++g;
	}
	return printf("%d\n%d %d",ans,tx,ty),0;
}