#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,m,i,j,f[N],lazy[N*4],ans;
priority_queue<int> q,del;
struct str{
	int a,x;
}c[N];
struct seg{
	int l,r,x;
	bool operator <(const seg &a)const
	{
		return a.r>r;
	}
};
set<seg> p;
bool cmp(str a,str b)
{
	if(a.a==b.a)
		return a.x<b.x;
	return a.a>b.a;
}
bool ins(seg a,seg b)
{
	return (a.l<=b.l)&&(b.l<=a.r)&&(a.r<=b.l);
}
void Erase(seg x)
{
	//cout<<2<<' '<<x.l<<' '<<x.r<<endl;
	auto it=p.find(x);
	auto tt=it,t2=it;
	++t2;
	if(t2!=p.end())
		del.push(t2->l-it->r);
	if(tt!=p.begin())
	{
		--tt;
		del.push(it->l-tt->r);
		if(t2!=p.end())
			q.push(t2->l-tt->r);
	}
	p.erase(it);
}
void Insert(seg x)
{
	//cout<<1<<' '<<x.l<<' '<<x.r<<endl;
	p.insert(x);
	auto it=p.find(x);
	auto tt=it,t2=it;
	++t2;
	if(t2!=p.end())
		q.push(t2->l-it->r);
	if(tt!=p.begin())
	{
		--tt;
		q.push(it->l-tt->r);
		if(t2!=p.end())
			del.push(t2->l-tt->r);
	}
}
void Add(int l,int r)
{
	auto it=p.lower_bound((seg){0,l,0});
	auto it2=p.lower_bound((seg){0,r,0});
	seg tmp=(seg){l,r,1};
	if(it!=p.end()&&ins(*it,tmp)&&it2!=p.end()&&ins(tmp,*it2))
	{
		seg t2=(seg){it->l,it2->r,1};
		Erase(*it);
		Erase(*it2);
		Insert(t2);
	}
	else
		if(it!=p.end()&&ins(*it,tmp))
		{
			seg t2=(seg){it->l,r,1};
			Erase(*it);
			Insert(t2);
		}
		else
			if(it2!=p.end()&&ins(tmp,*it2))
			{
				seg t2=(seg){l,it2->r,1};
				Erase(*it2);
				Insert(t2);
			}
			else
				Insert((seg){l,r,1});
}
void Add2(int l,int r)
{
	if(r-l>0||(r-l==0&&(l==1||l==n)))
		Insert((seg){l,r,0});
}
void modify(int i,int l,int r,int ll,int rr,int x)
{
	if(l>=ll&&r<=rr)
	{
		lazy[i]=max(lazy[i],x);
		return;
	}
	int mid=l+r>>1;
	if(mid>=ll)
		modify(i<<1,l,mid,ll,rr,x);
	if(mid<rr)
		modify(i<<1|1,mid+1,r,ll,rr,x);
}
void Deal(seg a,seg b,int x)
{
	if(a.r>=b.l-1)
		return;
	int l=a.r+1,r=b.l-1;
	if(a.x^b.x)
	{
		if(a.x)
			modify(1,1,n,l,l+r>>1,x);
		else
			modify(1,1,n,(l+r>>1)+1,r,x);
	}
	else
		if(a.x)
			modify(1,1,n,l,r,x);
}
void Output(int i,int l,int r,int x)
{
	if(l==r)
	{
		printf("%d ",max(x,lazy[i]));
		return;
	}
	int mid=l+r>>1;
	Output(i<<1,l,mid,max(x,lazy[i]));
	Output(i<<1|1,mid+1,r,max(x,lazy[i]));
}
int main()
{
	scanf("%d",&n);
	bool flag=true;
	for(i=1;i<=n;++i)
	{
		scanf("%d",&c[i].a);
		c[i].x=i;
	}
	for(i=2;i<n;++i)
		if(c[i].a!=c[i+1].a&&c[i].a!=c[i-1].a)
			flag=false;
	if(flag)
	{
		puts("0");
		for(i=1;i<=n;++i)
			printf("%d ",c[i].a);
		return 0;
	}
	p.insert((seg){1,n,0});
	sort(c+1,c+1+n,cmp);
	for(i=1;i<=n;)
	{
		for(j=i;c[i].a==c[j].a;++j)
		{
			f[c[j].x]=1;
			auto it=p.lower_bound((seg){0,c[j].x,0});
			if(it!=p.end())
			{
				seg tmp=*it;
				if(tmp.l<=c[j].x&&tmp.r>=c[j].x)
				{
					Erase(*it);
					Add2(tmp.l,c[j].x-1);
					Add2(c[j].x+1,tmp.r);
				}
			}
			int l=c[j].x,r=c[j].x;
			if(f[c[j].x-1])
				--l;
			if(f[c[j].x+1])
				++r;
			if(r-l+1>=2||c[j].x==1||c[j].x==n)
				Add(l,r);
			it=p.lower_bound((seg){0,c[j].x,0});
			if(it->l<=c[j].x&&c[j].x<=it->r)
			{
				auto tt=it;
				if(tt!=p.begin())
				{
					--tt;
					Deal(*tt,*it,c[j].a);
				}
				tt=it;
				++tt;
				if(tt!=p.end())
					Deal(*it,*tt,c[j].a);
				modify(1,1,n,it->l,it->r,c[j].a);
			}
			else
			{
				auto tt=it;
				--tt;
				Deal(*tt,*it,c[j].a);
			}
			//cout<<c[j].x<<endl;
			//for(auto it:p)
			//	cout<<it.l<<' '<<it.r<<' '<<it.x<<endl;
		}
		while(!del.empty()&&q.top()==del.top())
			q.pop(),del.pop();
		if(!q.empty())
			ans=max(ans,q.top()/2);
		i=j;
	}
	printf("%d\n",ans);
	Output(1,1,n,0);
}