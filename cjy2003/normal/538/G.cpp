#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
using namespace std;
void no()
{
	printf("NO");
	exit(0);
}
int n,l,cnt;
long long A,B;
long long sa[2000020],sb[2000020];
bool vis[2000020];
int ansa[2000020],ansb[2000020];
struct data
{
	long long t,x,y;
	friend bool operator < (data a,data b){return a.t%l<b.t%l;}
}p[200020];
long long al=-1000000000,ar=1000000000,bl=-1000000000,br=1000000000;
inline long long fl(long long x,long long y)
{
	long long r=x%y;
	if(r<0)r+=y;
	return (x-r)/y;
}
inline long long ce(long long x,long long y)
{
	long long r=x%y;
	if(r<=0)r+=y;
	return (x+y-r)/y;
}
int f;
inline void work1(long long a,long long b,long long c)
{
	if(a<0)a=-a,b=-b;
//	printf("1 %lld %lld %lld\n",a,b,c);
/*	if(a&1)
	{
		if(fa!=((b+c)&1))no();
		fa=(b+c)&1;
	}
	else if((b+c)&1)no();*/
	if(a==0)
	{
		if(b>c||b<-c)no();
	}
	else
	{
		ar=min(ar,fl(c-b,a));
		al=max(al,ce(-b-c,a));
	}
}
inline void work2(long long a,long long b,long long c)
{
	if(a<0)a=-a,b=-b;
//	printf("2 %lld %lld %lld\n",a,b,c);
/*	if(a&1)
	{
		if(fb!=((b+c)&1))no();
		fb=(b+c)&1;
	}
	else if((b+c)&1)no();*/
	if(a==0)
	{
		if(b>c||b<-c)no();
	}
	else
	{
		br=min(br,fl(c-b,a));
		bl=max(bl,ce(-b-c,a));
	}
}
int main()
{
	scanf("%d %d",&n,&l);
	f=l&1;
	long long t,x,y;
	p[cnt=1]=data{0,0,0};
	while(n--)
	{
		scanf("%lld %lld %lld",&t,&x,&y);
		p[++cnt]=data{t,x+y,x-y};
		if(((x+y)&1)!=(t&1))no();
	}
//	printf("%lld %lld %lld %lld\n",al,ar,bl,br);
	sort(p+1,p+1+cnt);
	for(int i=1;i<cnt;++i)
	{
		work1(p[i+1].t/l-p[i].t/l,p[i].x-p[i+1].x,p[i+1].t%l-p[i].t%l);
		work2(p[i+1].t/l-p[i].t/l,p[i].y-p[i+1].y,p[i+1].t%l-p[i].t%l);
	}
	work1(p[cnt].t/l+1,-p[cnt].x,l-p[cnt].t%l);
	work2(p[cnt].t/l+1,-p[cnt].y,l-p[cnt].t%l);
	if((al&1)!=f)++al;
	if((ar&1)!=f)--ar;
	if((bl&1)!=f)++bl;
	if((br&1)!=f)--br;
	if(al>ar||bl>br)no();
//	printf("%lld %lld %lld %lld\n",al,ar,bl,br);
	A=al,B=bl;
//	printf("%lld %lld\n",A,B); 
	for(int i=1;i<=cnt;++i)vis[p[i].t%l]=1,sa[p[i].t%l]=p[i].x-A*(p[i].t/l),sb[p[i].t%l]=p[i].y-B*(p[i].t/l);
	int lst=0;
	vis[l]=1,sa[l]=A,sb[l]=B;
	for(int i=1;i<=l;++i)
		if(vis[i])
		{
			int p,lim;
			p=lst+1,lim=abs(sa[i]-sa[lst]);
			assert(lim<=i-lst);
			for(int j=1;j<=lim;++j)ansa[p]=sa[i]>sa[lst]?1:-1,++p;
			while(p<=i)ansa[p]=1,++p,ansa[p]=-1,++p;
			p=lst+1,lim=abs(sb[i]-sb[lst]);
			assert(lim<=i-lst);
			for(int j=1;j<=lim;++j)ansb[p]=sb[i]>sb[lst]?1:-1,++p;
			while(p<=i)ansb[p]=1,++p,ansb[p]=-1,++p;
			lst=i;
		}
//	if(cnt==1001&&l==2000000)printf("%lld %lld %lld %lld %d %d\n",sa[0],sa[1],sb[0],sb[1],ansa[1],ansb[1]);
	for(int i=1;i<=l;++i)
		if(ansa[i]==1)
		{
			if(ansb[i]==1)putchar('R');
			else putchar('U');
		}
		else
		{
			if(ansb[i]==1)putchar('D');
			else putchar('L');
		}
	return 0;
}