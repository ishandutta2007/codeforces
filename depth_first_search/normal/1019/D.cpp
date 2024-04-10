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
#define LL long long
using namespace std;
int n,a[N+5];LL m;struct P {int id,x,y;}p[N+5];
struct S {int i,j;double k;I bool operator < (Cn S& o) Cn {return k<o.k;}}s[N*N+5];
I bool cmp(Cn P& A,Cn P& B) {return A.x<B.x;}
I void F1(RI l,RI r,Cn P& A,Cn P& B)
{
	RI mid;LL s;W(l<=r) {mid=l+r>>1,s=abs(1LL*(p[mid].x-A.x)*(p[mid].y-B.y)-1LL*(p[mid].x-B.x)*(p[mid].y-A.y));
		if(s==2*m) printf("Yes\n%d %d\n%d %d\n%d %d\n",A.x,A.y,B.x,B.y,p[mid].x,p[mid].y),exit(0);s<2*m?r=mid-1:l=mid+1;}
}
I void F2(RI l,RI r,Cn P& A,Cn P& B)
{
	RI mid;LL s;W(l<=r) {mid=l+r>>1,s=abs(1LL*(p[mid].x-A.x)*(p[mid].y-B.y)-1LL*(p[mid].x-B.x)*(p[mid].y-A.y));
		if(s==2*m) printf("Yes\n%d %d\n%d %d\n%d %d\n",A.x,A.y,B.x,B.y,p[mid].x,p[mid].y),exit(0);s<2*m?l=mid+1:r=mid-1;}
}
int main()
{
	RI i,j,c=0;for(scanf("%d%lld",&n,&m),i=1;i<=n;++i) scanf("%d%d",&p[i].x,&p[i].y);
	for(sort(p+1,p+n+1,cmp),i=1;i<=n;++i) a[p[i].id=i]=i;
	for(i=1;i<=n;++i) for(j=i+1;j<=n;++j) s[++c]=(S){i,j,1.0*(p[j].y-p[i].y)/(p[j].x-p[i].x)};sort(s+1,s+c+1);
	RI mn,mx;for(i=1;i<=c;++i) mn=min(a[s[i].i],a[s[i].j]),mx=max(a[s[i].i],a[s[i].j]),swap(p[mn],p[mx]),
		swap(a[s[i].i],a[s[i].j]),mn^1&&(F1(1,mn-1,p[a[s[i].i]],p[a[s[i].j]]),0),mx^n&&(F2(mx+1,n,p[a[s[i].i]],p[a[s[i].j]]),0);
	return puts("No"),0;
}