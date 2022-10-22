#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 300000
#define LL long long
using namespace std;
int n,a[N+5];LL ans;
int Mx[N+5],Mn[N+5],c[2*N+5];I void Solve(CI l,CI r)
{
	if(l==r) return (void)++ans;RI i,p,q,mid=l+r>>1;Solve(l,mid),Solve(mid+1,r);
	Mx[mid]=Mn[mid]=a[mid],Mx[mid+1]=Mn[mid+1]=a[mid+1];
	for(i=mid-1;i>=l;--i) Mx[i]=max(Mx[i+1],a[i]),Mn[i]=min(Mn[i+1],a[i]);
	for(i=mid+2;i<=r;++i) Mx[i]=max(Mx[i-1],a[i]),Mn[i]=min(Mn[i-1],a[i]);
	for(i=l;i<=mid;++i) p=i+Mx[i]-Mn[i],mid<p&&p<=r&&Mn[i]<Mn[p]&&Mx[p]<Mx[i]&&++ans;
	for(i=mid+1;i<=r;++i) p=i-Mx[i]+Mn[i],l<=p&&p<=mid&&Mn[i]<Mn[p]&&Mx[p]<Mx[i]&&++ans;
	for(i=mid,p=q=mid+1;i>=l;ans+=c[Mn[i]-i+n],--i)
		{W(q<=r&&Mn[q]>Mn[i]) ++c[Mx[q]-q+n],++q;W(p^q&&Mx[p]<Mx[i]) --c[Mx[p]-p+n],++p;}
	W(p^q) --c[Mx[p]-p+n],++p;
	for(i=mid,p=q=mid+1;i>=l;ans+=c[Mx[i]+i],--i)
		{W(q<=r&&Mx[q]<Mx[i]) ++c[Mn[q]+q],++q;W(p^q&&Mn[p]>Mn[i]) --c[Mn[p]+p],++p;}
	W(p^q) --c[Mn[p]+p],++p;
}
int main()
{
	RI i,x,y;for(scanf("%d",&n),i=1;i<=n;++i) scanf("%d%d",&x,&y),a[x]=y;
	return Solve(1,n),printf("%lld\n",ans),0;
}