#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
const int N=50005;
int n,i;
int x[N],y[N],dx[N],dy[N],s[N];
ld eps=0.0000000001;
struct str{
	ld x,y,a,b,k,j;
}p[N];
ld cur;
struct Cmp
{
	bool operator() (const int &a, const int &b)
	{
		return p[a].k*cur+p[a].j<p[b].k*cur+p[b].j;
	}
};
set<int,Cmp> e;
struct pts{
	ld x,y;
};
struct node{
	ld s;
	int x,f;
}t[N];
pts operator -(pts a,pts b)
{
	return (pts){a.x-b.x,a.y-b.y};
}
ld operator *(pts a,pts b)
{
	return a.x*b.y-a.y*b.x;
}
bool ins(str a,str b)
{
	if(min(b.x,b.a)>max(a.a,a.x)||min(a.x,a.a)>max(b.a,b.x)||min(a.y,a.b)>max(b.y,b.b)||min(b.y,b.b)>max(a.y,a.b))
		return false;
	pts c=(pts){a.x,a.y};
	pts d=(pts){a.a,a.b};
	pts e=(pts){b.x,b.y};
	pts f=(pts){b.a,b.b};
	if(((d-c)*(e-c))*((d-c)*(f-c))<eps)
		if(((f-e)*(c-e))*((f-e)*(d-e))<eps)
			return true;
	return false;
}
bool cmp(node a,node b)
{
	return a.s<b.s;
}
bool check(ld m)
{
	int i,k=0;
	for(i=1;i<=n;++i)
	{
		ld st=m*s[i]/sqrt((ld)dx[i]*dx[i]+dy[i]*dy[i]);
		p[i]=(str){x[i],y[i],dx[i]*st+x[i],dy[i]*st+y[i]};
		if(p[i].x>p[i].a)
		{
			swap(p[i].x,p[i].a);
			swap(p[i].y,p[i].b);
		}
		p[i].k=(p[i].y-p[i].b)/(p[i].x-p[i].a);
		p[i].j=p[i].y-p[i].k*p[i].x;
		t[++k]=(node){p[i].x,i,1};
		t[++k]=(node){p[i].a+eps,i,-1};
	}
	sort(t+1,t+1+k,cmp);
	e.clear();
	for(i=1;i<=k;++i)
	{
		cur=t[i].s;
		if(t[i].f==1)
		{
			auto it=e.lower_bound(t[i].x);
			if(it!=e.end())
				if(ins(p[*it],p[t[i].x]))
					return true;
			if(it!=e.begin())
			{
				--it;
				if(ins(p[*it],p[t[i].x]))
					return true;
			}
			e.insert(t[i].x);
		}
		else
		{
			auto it=e.lower_bound(t[i].x);
			if(*it!=t[i].x)
				return true;
			auto tmp=it;
			++tmp;	
			if(tmp!=e.end())
				if(ins(p[*tmp],p[t[i].x]))
					return true;
			tmp=it;
			if(tmp!=e.begin())
			{
				--tmp;
				if(ins(p[*tmp],p[t[i].x]))
					return true;
			}
			e.erase(it);
		}
	}
	return false;
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%d %d %d %d %d",&x[i],&y[i],&dx[i],&dy[i],&s[i]);
	ld l=0,r=100000000000.0;
	while((r-l)/max((ld)1,l)>eps)
	{
		ld mid=(l+r)/2;
		if(check(mid))
			r=mid;
		else
			l=mid;
	}
	if(l>90000000000.0)
		puts("No show :(");
	else
		printf("%.12LF",l);
}