#include<bits/stdc++.h>
using namespace std;
int n,i,q,m,c,c0,tot;
struct str{
	int t,a,b;
}a[500005];
long long ans;
multiset<pair<int,int> > s;
bool cmp(str a,str b)
{
	return a.t<b.t;
}
int main()
{
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d %d %d %d",&n,&m,&c,&c0);
		for(i=1;i<=n;i++)
			scanf("%d %d %d",&a[i].t,&a[i].a,&a[i].b);
		sort(a+1,a+1+n,cmp);
		a[n+1].t=m;
		s.clear();
		s.insert(make_pair(0,c0));
		ans=0;
		tot=c0;
		for(i=1;i<=n+1;i++)
		{
			int m=a[i].t-a[i-1].t;
			while(m&&!s.empty())
			{
				pair<int,int> x=*(s.begin());
				s.erase(s.begin());
				if(m>=x.second)
				{
					m-=x.second;
					ans+=1ll*x.first*x.second;
				}
				else
				{
					ans+=1ll*m*x.first;
					x.second-=m;
					m=0;
					s.insert(x);
				}
			}
			if(m!=0)
				break;
			tot-=a[i].t-a[i-1].t;
			s.insert(make_pair(a[i].b,a[i].a));
			tot+=a[i].a;
			while(tot>c)
			{
				set<pair<int,int> >::iterator it=s.end();
				--it;
				s.erase(it);
				if(tot-c>=it->second)
					tot-=it->second;
				else
				{
					s.insert(make_pair(it->first,it->second-tot+c));
					tot=c;
				}
			}
		}
		if(i<=n+1)
			printf("-1\n");
		else
			printf("%lld\n",ans);
	}
}