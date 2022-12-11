#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
set<pair<int,int> >s;
int n,q;
bool in[200020];
int a[200020],pos[200020];
int mx[200020],cnt;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		s.insert(make_pair(a[i],i));
		in[i]=1;
	}
	scanf("%d",&q);
	int c,x,w;
	while(q--)
	{
		scanf("%d",&c);
		if(c==2)
		{
			scanf("%d",&w);
			mx[++cnt]=w;
			while(s.size()&&s.begin()->first<=w)
			{
				in[s.begin()->second]=0;
				pos[s.begin()->second]=cnt;
				s.erase(s.begin());
			}
		}
		else
		{
			scanf("%d %d",&x,&w);
			if(in[x])s.erase(make_pair(a[x],x));
			else in[x]=1;
			s.insert(make_pair(a[x]=w,x));
		}
	}
	for(int i=cnt;i;--i)mx[i]=max(mx[i],mx[i+1]);
	for(int i=1;i<=n;++i)
	{
		if(!in[i])a[i]=mx[pos[i]];
		printf("%d ",a[i]);
	}
	return 0;
}