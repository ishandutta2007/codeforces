#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int l,r,id[30],n=1;
struct edge
{
	int x,y,w;
};
vector<edge>e;
int main()
{
	scanf("%d %d",&l,&r);
	printf("YES\n");
	r-=l;
	for(int i=19,sum=1;~i;--i)
	{
		id[i]=++n;
		if(r>>i&1)
		{
			e.emplace_back(edge{1,id[i],sum});
			sum+=1<<i;
		}
	}
	++n;
	for(int i=19;i>=0;--i)
	{
		for(int j=i-1;j>=0;--j)e.emplace_back(edge{id[i],id[j],1<<j});
		e.emplace_back(edge{id[i],n,l});
	}
	e.emplace_back(edge{1,n,l});
	printf("%d %d\n",n,(int)e.size());
	for(auto p:e)printf("%d %d %d\n",p.x,p.y,p.w);
	return 0;
}