// Problem: CF538G Berserk Robot 
// Contest: Luogu

// URL: https://www.luogu.com.cn/problem/CF538G
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int n,L;
struct node
{
	int t,x,y;
	bool operator<(const node&a)const
	{return (t%L<a.t%L)||(t%L==a.t%L&&t<a.t);}
}a[200005];
int divu(int x,int y);
int divd(int x,int y)
{
	if(x>=0) return x/y;
	return -divu(-x,y);
}
int divu(int x,int y)
{
	if(x>0) return (x-1)/y+1;
	return -divd(-x,y);
}
#define divd_ divd
#define divu_ divu
// int divd_(int x,int y)
// {
	// printf("floor %lld %lld %lld\n",x,y,divd(x,y));
	// return divd(x,y);
// }
// int divu_(int x,int y)
// {
	// printf("ceil %lld %lld %lld\n",x,y,divu(x,y));
	// return divu(x,y);
// }
bool A[2000013],B[2000013];
signed main()
{
	n=read()+1,L=read();
	for(int i=2,X,Y; i<=n; ++i)
	{ 
		a[i].t=read(),X=read(),Y=read(),
		a[i].x=X+Y,a[i].y=X-Y;
		if((a[i].t+X+Y)&1) puts("NO"),exit(0);
		//cout<<a[i].t<<" "<<a[i].x<<" "<<a[i].y<<endl;
	}
	sort(a+1,a+n+1);
	// bool dX_rin_tie_tie=0,rin_dX_tie_tie=0;
	// bool dx_rin_tie_tie=0,rin_dx_tie_tie=0;
	// for(int i=1; i<=n; ++i)
	// {
		// int S=a[i].x&1;
		// int T=a[i].t%L;
		// int G=a[i].t/L;
		// if(G&1)
		// {
			// if((S+T)&1) dX_rin_tie_tie=1;//
			// else dx_rin_tie_tie=1;//
		// } 
		// else {if((S+T)&1) puts("NO"),exit(0);}
		// S=a[i].y&1;
		// if(G&1)
		// {
			// if((S+T)&1) rin_dX_tie_tie=1;//
			// else rin_dx_tie_tie=1;//
		// } 
		// else {if((S+T)&1) puts("NO"),exit(0);}
	// }
	int xmn=-L,xmx=L,ymn=-L,ymx=L;
	for(int i=1; i<=n; ++i)
	{
		//printf("%lld %lld %lld\n",a[i].t,a[i].x,a[i].y);
		int d=a[i+1].t%L-a[i].t%L;
		int g=a[i+1].t/L-a[i].t/L;
		if(d<0) d+=L,--g;
		if(d>=L) d-=L,++g;
		//g loops and d steps
		int xl=a[i+1].x-a[i].x-d,xr=a[i+1].x-a[i].x+d;
		int yl=a[i+1].y-a[i].y-d,yr=a[i+1].y-a[i].y+d;
		if(g>0)
		{
			xmx=min(xmx,divd_(xr,g)),xmn=max(xmn,divu_(xl,g));
			ymx=min(ymx,divd_(yr,g)),ymn=max(ymn,divu_(yl,g));
		}
		else if(g<0)
		{
			xmx=min(xmx,divd_(-xl,-g)),xmn=max(xmn,divu_(-xr,-g));
			ymx=min(ymx,divd_(-yl,-g)),ymn=max(ymn,divu_(-yr,-g));
		}
		else if(a[i].x-d>a[i+1].x||a[i].x+d<a[i+1].x||
		a[i].y-d>a[i+1].y||a[i].y+d<a[i+1].y) puts("NO"),exit(0);
	}
	
	// if(dX_rin_tie_tie&&dx_rin_tie_tie) puts("NO"),exit(0);
	// if(rin_dX_tie_tie&&rin_dx_tie_tie) puts("NO"),exit(0);
	// if(dX_rin_tie_tie)
	// {
		// if(!(xmn&1)) ++xmn; 
		// if(!(xmx&1)) --xmx;
	// }
	// if(dx_rin_tie_tie)
	// {
		// if((xmn&1)) ++xmn; 
		// if((xmx&1)) --xmx;
	// }
// 	
	// if(rin_dX_tie_tie)
	// {
		// if(!(ymn&1)) ++ymn;
		// if(!(ymx&1)) --ymx;
	// }
	// if(rin_dx_tie_tie)
	// {
		// if((ymn&1)) ++ymn;
		// if((ymx&1)) --ymx;
	// }
	if((xmn+L)&1) ++xmn;
	if((xmx+L)&1) --xmx;
	if((ymn+L)&1) ++ymn;
	if((ymx+L)&1) --ymx;
	if(xmn>xmx||ymn>ymx) puts("NO"),exit(0);
	
	//printf("%lld %lld\n",xmn,ymn);
	
	int pos=1,p0s=1,sumx=-xmn,sumy=-ymn;
	//printf("X %lld %lld\n",xmn,xmx);
	for(int i=1; i<n; ++i)
	{
		if(a[i].t%L==a[i+1].t%L) continue;
		int g=a[i+1].t/L-a[i].t/L;
		int W=a[i+1].x-a[i].x-xmn*g;
		if(W>0) for(int i=1; i<=W&&pos<=2000003; ++i) A[pos++]=1,++sumx;
		else for(int i=1; i<=-W&&pos<=2000003; ++i) A[pos++]=0,--sumx;
		//printf("%lld %lld\n",pos,a[i+1].t%L);
		while(pos<=a[i+1].t%L) A[pos++]=1,A[pos++]=0;
		if(pos!=a[i+1].t%L+1) puts("NO"),exit(0);
		
		W=a[i+1].y-a[i].y-ymn*g;
		if(W>0) for(int i=1; i<=W&&p0s<=2000003; ++i) B[p0s++]=1,++sumy;
		else for(int i=1; i<=-W&&p0s<=2000003; ++i) B[p0s++]=0,--sumy;
		while(p0s<=a[i+1].t%L) B[p0s++]=1,B[p0s++]=0;
		if(p0s!=a[i+1].t%L+1) puts("NO"),exit(0);
	}
	for(int i=1; i<=sumx&&pos<=2000003; ++i) A[pos++]=0;
	for(int i=1; i<=-sumx&&pos<=2000003; ++i) A[pos++]=1;
	if(pos>L+1) puts("NO"),exit(0);
	while(pos<=L) A[pos++]=1,A[pos++]=0;
	if(pos!=L+1) puts("NO"),exit(0);
	for(int i=1; i<=sumy&&p0s<=2000003; ++i) B[p0s++]=0;
	for(int i=1; i<=-sumy&&p0s<=2000003; ++i) B[p0s++]=1;
	if(p0s>L+1) puts("NO"),exit(0);
	while(p0s<=L) B[p0s++]=1,B[p0s++]=0;
	if(p0s!=L+1) puts("NO"),exit(0);
	//for(int i=1; i<=L; ++i) printf("%lld%lld\n",A[i],B[i]);
	for(int i=1; i<=L; ++i)
	{
		if(A[i]) if(B[i]) printf("R"); else printf("U");
		else if(B[i]) printf("D"); else printf("L");
		//printf("%lld%lld\n",A[i],B[i]);
	}
	//puts("");
	return 0;
}