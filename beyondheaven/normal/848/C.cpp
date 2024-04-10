#include<bits/stdc++.h>
typedef long long LL;
const int MaxN = 100123;

int n,m,q,a[MaxN],p[MaxN];
LL ans[MaxN];
std::set<int>s[MaxN];

struct Command
{
	int a,b,c,id;
	Command(int _a=0,int _b=0,int _c=0,int _id=0):
		a(_a),b(_b),c(_c),id(_id){}
};

struct BinaryIndexedTree
{
	LL c[MaxN];
	void add(int x,LL v){if(x)for(;x<=n;x+=(x&-x))c[x]+=v;}
	LL sum(int x)
	{
		LL res=0;
		for(;x;x-=(x&-x))res+=c[x];
		return res;
	}
	LL sum(int l,int r){return sum(r)-sum(l-1);}
	BinaryIndexedTree(){memset(c,0,sizeof(c));}
	
	#ifdef Dubug
	bool empty()
	{
		for(int i=0;i<=n+5;++i)if(c[i])return false;
		return true;
	}
	#endif
}BIT;

void Solve(std::vector<Command>&V)
{
	if(static_cast<int>(V.size())==1)return;
	int mid=(V.size()+1)/2;
	
	std::vector<Command>L(V.begin(),V.begin()+mid),
		R(V.begin()+mid,V.end());
	Solve(L);Solve(R);
	
	auto cmp=[&](const Command&x,const Command&y){return x.a<y.a;};
	std::sort(L.begin(),L.end(),cmp);
	std::sort(R.begin(),R.end(),cmp);
	
	auto I=[&](std::vector<Command>::iterator&p)
	{
		if(!p->id)BIT.add(p->b,p->c);
		++p;
	};
	
	auto Q=[&](std::vector<Command>::iterator&p)
	{
		if(p->id)ans[p->id]+=p->c*BIT.sum(p->b,n);
		++p;
	};
	
	auto p1=L.begin(),p2=R.begin();
	while(p1!=L.end()||p2!=R.end())
	{
		if(p1==L.end())Q(p2);
		else if(p2==R.end())I(p1);
		else if(p1->a<=p2->a)I(p1);
		else Q(p2);
	}
	
	for(auto&o:L)if(!o.id)BIT.add(o.b,-o.c);
	
	#ifdef Dubug
	assert(BIT.empty());
	#endif
}

int main()
{
	std::vector<Command>V;
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	scanf("%d",a+i),s[a[i]].insert(i);
	
	for(int i=1;i<=n;++i)
	{
		auto it=s[a[i]].find(i);
		if(it!=s[a[i]].begin())p[i]=*std::prev(it);
		V.push_back(Command(i,p[i],i-p[i],0));
	}
	
	for(int i=1,op,b,c;i<=m;++i)
	{
		scanf("%d%d%d",&op,&b,&c);
		if(op==1)
		{
			V.push_back(Command(b,p[b],p[b]-b,0));
			auto it=s[a[b]].find(b);
			if(it!=--s[a[b]].end())
			{
				int u=*std::next(it);
				V.push_back(Command(u,p[u],p[u]-u,0));
				p[u]=p[b];
				V.push_back(Command(u,p[u],u-p[u],0));
			}
			s[a[b]].erase(b);
			
			it=s[c].insert(b).first;
			if(it!=s[c].begin())p[b]=*std::prev(it);
			else p[b]=0;
			if(it!=--s[c].end())
			{
				int u=*std::next(it);
				V.push_back(Command(u,p[u],p[u]-u,0));
				p[u]=b;
				V.push_back(Command(u,p[u],u-p[u],0));
			}
			V.push_back(Command(b,p[b],b-p[b],0));
			
			a[b]=c;
		}
		else
		{
			++q;
			V.push_back(Command(c,b,1,q));
			if(b!=1)V.push_back(Command(b-1,b,-1,q));
		}
	}
	
	Solve(V);
	for(int i=1;i<=q;++i)printf("%lld\n",ans[i]);
	return 0;
}