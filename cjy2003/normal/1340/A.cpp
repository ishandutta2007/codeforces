#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
int T,n,p[100010],pre[100010],nxt[100010],pos[100010],mx;
multiset<int>s;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		s.clear();
		for(int i=1;i<=n;++i)scanf("%d",&p[i]),pre[i]=i-1,nxt[i]=i+1,pos[p[i]]=i,s.insert(1);
		mx=1;
		bool flag=1;
		for(int i=1;i<=n;++i)
		{
			if(pos[i]-pre[pos[i]]!=*prev(s.end()))
			{
			//	printf("%d %d\n",pos[i],pre[pos[i]]);
				flag=0;
				break;
			}
			s.erase(s.lower_bound(pos[i]-pre[pos[i]]));
			if(nxt[pos[i]]!=n+1)
			{
				s.erase(s.lower_bound(nxt[pos[i]]-pos[i]));
				s.insert(nxt[pos[i]]-pre[pos[i]]);
			}
			nxt[pre[pos[i]]]=nxt[pos[i]];
			pre[nxt[pos[i]]]=pre[pos[i]];
		}
		if(!flag)printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}