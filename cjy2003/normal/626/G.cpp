#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
struct data
{
	int p,l,cnt,id;
	friend bool operator < (data a,data b)
	{
		if(1ull*a.p*a.l*(b.l+b.cnt+1)*(b.l+b.cnt)==1ull*b.p*b.l*(a.l+a.cnt+1)*(a.l+a.cnt))return a.id<b.id;
		else return 1ull*a.p*a.l*(b.l+b.cnt+1)*(b.l+b.cnt)>1ull*b.p*b.l*(a.l+a.cnt+1)*(a.l+a.cnt);
	}
};
int n,t,q,l[200020],cnt[200020],p[200020],res;
set<data>able,used;
double ans;
inline void ins(int id)
{
//	printf("i%d\n",id);
	ans-=1.0*p[id]*cnt[id]/(cnt[id]+l[id]);
	if(cnt[id]<l[id])able.erase(data{p[id],l[id],cnt[id],id});
	if(cnt[id])used.erase(data{p[id],l[id],cnt[id]-1,id});
	++cnt[id];--res;
	if(cnt[id])used.insert(data{p[id],l[id],cnt[id]-1,id});
	if(cnt[id]<l[id])able.insert(data{p[id],l[id],cnt[id],id});
	ans+=1.0*p[id]*cnt[id]/(cnt[id]+l[id]);
}
inline void era(int id)
{
	ans-=1.0*p[id]*cnt[id]/(cnt[id]+l[id]);
	if(cnt[id]<l[id])able.erase(data{p[id],l[id],cnt[id],id});
	if(cnt[id])used.erase(data{p[id],l[id],cnt[id]-1,id});
	--cnt[id];++res;
	if(cnt[id])used.insert(data{p[id],l[id],cnt[id]-1,id});
	if(cnt[id]<l[id])able.insert(data{p[id],l[id],cnt[id],id});
	ans+=1.0*p[id]*cnt[id]/(cnt[id]+l[id]);
}
void work()
{
	while(res&&able.size())ins(able.begin()->id);
}
int main()
{
	scanf("%d %d %d",&n,&t,&q);
	for(int i=1;i<=n;++i)scanf("%d",&p[i]);
	for(int i=1;i<=n;++i)scanf("%d",&l[i]);
	for(int i=1;i<=n;++i)able.insert(data{p[i],l[i],0,i});
	res=t;
	work();
	int op,x;
	while(q--)
	{
		scanf("%d %d",&op,&x);
		if(op==1)
		{
			if(cnt[x]<l[x])able.erase(data{p[x],l[x],cnt[x],x});
			if(cnt[x])used.erase(data{p[x],l[x],cnt[x]-1,x});
			ans-=1.0*p[x]*cnt[x]/(cnt[x]+l[x]);
			++l[x];
			ans+=1.0*p[x]*cnt[x]/(cnt[x]+l[x]);
			if(cnt[x]<l[x])able.insert(data{p[x],l[x],cnt[x],x});
			if(cnt[x])used.insert(data{p[x],l[x],cnt[x]-1,x});
			if(cnt[x])era(x);
		}
		else
		{
			if(cnt[x]<l[x])able.erase(data{p[x],l[x],cnt[x],x});
			if(cnt[x])used.erase(data{p[x],l[x],cnt[x]-1,x});
			ans-=1.0*p[x]*cnt[x]/(cnt[x]+l[x]);
			--l[x];
			ans+=1.0*p[x]*cnt[x]/(cnt[x]+l[x]);
		//	printf("%.12lf\n",ans);
			if(cnt[x]<l[x])able.insert(data{p[x],l[x],cnt[x],x});
			if(cnt[x])used.insert(data{p[x],l[x],cnt[x]-1,x});
			if(cnt[x]>l[x])era(x);
		}
	//	for(int i=1;i<=n;++i)printf("%d ",cnt[i]);printf("\n");
	//	printf("%.12lf\n",ans);		
		if(used.size())era(used.rbegin()->id);
		work();
	//	for(int i=1;i<=n;++i)printf("%d ",cnt[i]);printf("\n");
		printf("%.12lf\n",ans);
	}
	return 0;
}