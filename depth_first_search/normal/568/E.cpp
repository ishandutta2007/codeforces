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
#define K 1000
using namespace std;
int n,m,a[N+5],b[N+5],c,s[N+5],p[N+5],lst[N+5];
struct S
{
	int x,y;I S(CI a=0,CI b=0):x(a),y(b){}
	I bool operator >= (Con S& o) Con {return x>=o.x;} 
	I bool operator < (Con S& o) Con {return x<o.x;} 
}f[N+5];
int v[N+5];I void Fill(CI x,CI y)
{
	#define G(x) (lower_bound(b+1,b+m+1,x)-b-1)
	if(y==1) return;RI k=lst[x];if(!k)
	{
		for(k=1;k^x;++k) if(~a[k]&&p[k]==y-1&&a[k]<a[x]) break;if(k==x) W(~a[--k]);
	}
	return !~a[k]&&(a[k]=b[G(a[x])],v[G(a[x])]=1),Fill(k,y-1);
}
int main()
{
	RI i,x,y,w,t=0;for(scanf("%d",&n),i=1;i<=n;++i) scanf("%d",a+i);a[++n]=2e9;
	for(scanf("%d",&m),i=1;i<=m;++i) scanf("%d",b+i);
	for(sort(b+1,b+m+1),i=1;i<=m;++i) s[i]=b[i];c=unique(s+1,s+m+1)-s-1;
	for(i=1;i<=n;++i) if(~a[i])
		f[p[i]=f[t]<a[i]?++t:lower_bound(f+1,f+t+1,a[i])-f]=S(a[i],i),lst[i]=f[p[i]-1].y;
	else for(f[t]<s[c]&&(f[++t]=S(s[c],i),0),x=c,y=t;x;f[y]=S(s[x--],i)) W(y^1&&f[y-1]>=s[x]) --y;
	for(Fill(f[t].y,t),i=x=1;i^n;printf("%d ",a[i++])) if(!~a[i]) {W(v[x]) ++x;a[i]=b[x++];}return 0;
}