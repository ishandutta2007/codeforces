#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
int n,q,f[100010];
long long t[100010];
multiset<long long>s[100010],mi,mx;
int tot,id[100010],dy[100010],cnt[100010];
long long down[100010];
void erase(int x,int y)
{
	bool fl1=0,fl2=0;
	if(down[y]==*s[x].begin())mi.erase(mi.lower_bound(down[y]+t[x]/(cnt[x]+2))),fl1=1;
	if(down[y]==*s[x].rbegin())mx.erase(mx.lower_bound(down[y]+t[x]/(cnt[x]+2))),fl2=1;
	s[x].erase(s[x].lower_bound(down[y]));
	if(fl1&&s[x].size())mi.insert(*s[x].begin()+t[x]/(cnt[x]+2));
	if(fl2&&s[x].size())mx.insert(*s[x].rbegin()+t[x]/(cnt[x]+2));
}
void insert(int x,int y)
{
	bool fl1=s[x].size()==0,fl2=s[x].size()==0;
	if(s[x].size()&&down[y]<*s[x].begin())mi.erase(mi.lower_bound(*s[x].begin()+t[x]/(cnt[x]+2))),fl1=1;
	if(s[x].size()&&down[y]>*s[x].rbegin())mx.erase(mx.lower_bound(*s[x].rbegin()+t[x]/(cnt[x]+2))),fl2=1;
	s[x].insert(down[y]);
	if(fl1)mi.insert(down[y]+t[x]/(cnt[x]+2));
	if(fl2)mx.insert(down[y]+t[x]/(cnt[x]+2));
}
void del(int x)
{
	int y=f[x],z=f[y],w=f[z];
	erase(w,z);
	erase(z,y);
	erase(y,x);
	down[z]-=t[y]/(cnt[y]+2);
	down[y]-=t[x]/(cnt[x]+2)+t[y]-t[y]/(cnt[y]+2)*(cnt[y]+1);
	if(s[y].size())
	{
		mi.erase(mi.lower_bound(*s[y].begin()+t[y]/(cnt[y]+2)));
		mx.erase(mx.lower_bound(*s[y].rbegin()+t[y]/(cnt[y]+2)));
	}
	--cnt[y];
	if(s[y].size())
	{
		mi.insert(*s[y].begin()+t[y]/(cnt[y]+2));
		mx.insert(*s[y].rbegin()+t[y]/(cnt[y]+2));
	}	
	down[y]+=t[y]-t[y]/(cnt[y]+2)*(cnt[y]+1);
	down[z]+=t[y]/(cnt[y]+2);
	insert(z,y);
	insert(w,z);
}
void ins(int x)
{
	int y=f[x],z=f[y],w=f[z];
	erase(w,z);
	erase(z,y);
	down[z]-=t[y]/(cnt[y]+2);
	down[y]-=t[y]-t[y]/(cnt[y]+2)*(cnt[y]+1);
	if(s[y].size())
	{
		mi.erase(mi.lower_bound(*s[y].begin()+t[y]/(cnt[y]+2)));
		mx.erase(mx.lower_bound(*s[y].rbegin()+t[y]/(cnt[y]+2)));
	}
	++cnt[y];
	if(s[y].size())
	{
		mi.insert(*s[y].begin()+t[y]/(cnt[y]+2));
		mx.insert(*s[y].rbegin()+t[y]/(cnt[y]+2));
	}	
	down[y]+=t[x]/(cnt[x]+2)+t[y]-t[y]/(cnt[y]+2)*(cnt[y]+1);
	down[z]+=t[y]/(cnt[y]+2);
	insert(y,x);
	insert(z,y);
	insert(w,z);
}
void print()
{
	for(int i=1;i<=n;++i)printf("%lld ",down[i]);printf("\n");
}
int main()
{
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;++i)scanf("%lld",&t[i]);
	for(int i=1;i<=n;++i)scanf("%d",&f[i]),++cnt[f[i]];
	for(int i=1;i<=n;++i)down[f[i]]+=t[i]/(cnt[i]+2),down[i]+=t[i]-t[i]/(cnt[i]+2)*(cnt[i]+1);
	for(int i=1;i<=n;++i)s[f[i]].insert(down[i]);
	for(int i=1;i<=n;++i)
		if(cnt[i])
		{
			mi.insert(*s[i].begin()+t[i]/(cnt[i]+2));
			mx.insert(*s[i].rbegin()+t[i]/(cnt[i]+2));
		}
	int c,x,y;
	while(q--)
	{
		scanf("%d",&c);
		if(c==1)scanf("%d %d",&x,&y);
		else if(c==2)scanf("%d",&x);
		if(c==1)del(x)/*,print()*/,f[x]=y,ins(x)/*,print()*/;
		else if(c==2)printf("%lld\n",down[x]+t[f[x]]/(cnt[f[x]]+2));
		else printf("%lld %lld\n",*mi.begin(),*mx.rbegin());
	}
	return 0;
}