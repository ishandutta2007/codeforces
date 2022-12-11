#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<cmath>
#include<cassert>
using namespace std;
int gcd(int a,int b)
{
	if(!b)return a;
	return gcd(b,a%b);
}
const long double EPS=1e-10;
long double eps;
struct point
{
	long double x,y;
	friend point operator * (point a,long double b){return point{a.x*b,a.y*b};}
	friend point operator + (point a,point b){return point{a.x+b.x,a.y+b.y};}
	friend point operator - (point a,point b){return point{a.x-b.x,a.y-b.y};}
	friend long double operator ^ (point a,point b){return a.x*b.y-a.y*b.x;}
}p[25050],f[25050];
int A[25050],B[25050],C[25050];
long double cur;
struct line
{
	point a,b;
	long double f(long double x){return (x-a.x)*(b.y-a.y)/(b.x-a.x)+a.y;}
}l[25050];
struct Data
{
	long double x;int id;
	friend bool operator < (Data a,Data b){return a.x<b.x;}
}a[50050];
struct index
{
	int p;
	friend bool operator < (index a,index b)
	{
		if(A[a.p]==A[b.p]&&B[a.p]==B[b.p]&&C[a.p]==C[b.p])return a.p<b.p;
		else 
		{
			long double fa=l[a.p].f(cur),fb=l[b.p].f(cur);
			if(fa==fb)return a.p<b.p;
			else return fa<fb;
		}
	}
};
set<index>s;
int n;
long double v[25050];
int sgn(long double x)
{
	if(fabs(x)<eps)return 0;
	return x>0?1:-1;
}
bool inter(int a,int b)
{
	if(A[a]==A[b]&&B[a]==B[b]&&C[a]==C[b])
	{
		if(l[a].a.x>l[b].a.x)swap(a,b);
		return l[a].b.x>=l[b].a.x;
	}
	if(sgn((l[a].b-l[a].a)^(l[b].a-l[a].a))*sgn((l[a].b-l[a].a)^(l[b].b-l[a].a))==1)return 0;
	swap(a,b);
	if(sgn((l[a].b-l[a].a)^(l[b].a-l[a].a))*sgn((l[a].b-l[a].a)^(l[b].b-l[a].a))==1)return 0;
	return 1;
}
bool check(long double t)
{
	eps=t*EPS;
	for(int i=1;i<=n;++i)
	{
		l[i].a=p[i],l[i].b=p[i]+f[i]*t;
		if(l[i].a.x>l[i].b.x)swap(l[i].a,l[i].b);
		a[i*2-1]=Data{l[i].a.x,i};
		a[i*2]=Data{l[i].b.x,-i};
	}
	sort(a+1,a+1+2*n);
	s.clear();
	for(int i=1;i<=2*n;++i)
	{
		cur=a[i].x;
		if(a[i].id>0)
		{
			auto it=s.insert(index{a[i].id}).first;
			if(it!=s.begin()&&inter(it->p,prev(it)->p))return 1;
			if(next(it)!=s.end()&&inter(it->p,next(it)->p))return 1;
		}
		else
		{
			auto it=s.lower_bound(index{-a[i].id});
			if(it->p!=-a[i].id)assert(0);
			// {
			// //	printf("%d:",-a[i].id);
			// //	for(auto x:s)printf("%d ",x.p);printf("\n");
			// 	auto it1=it,it2=it;
			// 	bool ok1=it1!=s.begin(),ok2=next(it2)!=s.end();
			// 	if(ok1)it1=prev(it1);
			// 	if(ok2)it2=next(it2);
			// 	while(1)
			// 	{
			// 		if(ok1&&it1->p==-a[i].id){it=it1;break;}
			// 		if(ok2&&it2->p==-a[i].id){it=it2;break;}
			// 		ok1=ok1&&it1!=s.begin();
			// 		ok2=ok2&&next(it2)!=s.end();
			// 		if(ok1)it1=prev(it1);
			// 		if(ok2)it2=next(it2);
			// 	}
			// }
			if(it!=s.begin()&&next(it)!=s.end()&&inter(prev(it)->p,next(it)->p))return 1;
			s.erase(it);
		}
	}
	return 0;
}
int main()
{
	scanf("%d",&n);
	for(int i=1,x0,y0,fx,fy;i<=n;++i)
	{
		scanf("%d %d %d %d %Lf",&x0,&y0,&fx,&fy,&v[i]);
		p[i].x=x0,p[i].y=y0,f[i].x=fx,f[i].y=fy;
		long double c=v[i]/sqrt(f[i].x*f[i].x+f[i].y*f[i].y);
		f[i].x*=c,f[i].y*=c;
		A[i]=fy,B[i]=-fx,C[i]=y0*fx-x0*fy;
		int g=gcd(gcd(A[i],B[i]),C[i]);
		A[i]/=g,B[i]/=g,C[i]/=g;
		if(A[i]<0)A[i]=-A[i],B[i]=-B[i],C[i]=-C[i];
	}
	long double l=0,r=1e10,mid;
	while(l+1e-8<r)
	{
		mid=(l+r)/2;
		if(check(mid))r=mid;
		else l=mid;
	}
	if(l>1e10-1)printf("No show :(\n");
	else printf("%.12Lf",l);
	return 0;
}