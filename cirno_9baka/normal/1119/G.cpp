#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int m,n,i,s,k,c,t,l[N],ans[N],j,a[N];
vector<int> g[N];
vector<int> ind[N];
vector<int> hh;
struct str{
	int a,x;
};
bool operator <(str a,str b)
{
	return a.a>b.a;
}
priority_queue<str> q;
void Add(int x)
{
	++l[x];
	if(l[x]<g[x].size())
		q.push((str){g[x][l[x]]+t,x});
}
int main()
{
	scanf("%d %d",&m,&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		c+=a[i];
		while(a[i]>=m)
		{
			a[i]-=m;
			hh.push_back(i);
		}
		a[i]%=m;
	}
	printf("%d\n",(c+m-1)/m);
	a[1]+=(c+m-1)/m*m-c;
	while(a[1]>=m)
	{
		hh.push_back(1);
		a[1]-=m;
	}
	for(i=1;i<=n;++i)
	{
		if(a[i]==0)
			continue;
		int y=m;
		++k;
		for(j=i;j<=n;++j)
			if(y>=a[j])
			{
				g[k].push_back(a[j]);
				ind[k].push_back(j);
				y-=a[j];
				a[j]=0;
			}
			else
			{
				a[j]-=y;
				g[k].push_back(y);
				ind[k].push_back(j);
				break;
			}
	}
	for(i=1;i<=k;++i)
		q.push((str){g[i][0],i});
	int pp=0;
	for(i=1;i<=n;++i)
	{
		while(!q.empty()&&q.top().a==t)
		{
			str x=q.top();
			q.pop();
			Add(x.x);
		}
		if(!q.empty())
		{
			ans[i]=q.top().a-t;
			t=q.top().a;
		}
		pp+=ans[i];
	}
	ans[1]+=m-pp;
	for(i=1;i<=n;++i)
		printf("%d ",ans[i]);
	printf("\n");
	for(auto it:hh)
	{
		for(i=1;i<=n;++i)
			printf("%d ",it);
		printf("\n");
	}
	for(i=1;i<=k;++i)
	{
		int s=0,l=1;
		for(j=0;j<g[i].size();++j)
		{
			s=0;
			while(s<g[i][j]&&l<=n)
			{
				s+=ans[l];
				++l;
				printf("%d ",ind[i][j]);
			}
		}
		while(l<=n)
		{
			++l;
			printf("1 ");
		}
		printf("\n");
	}
}