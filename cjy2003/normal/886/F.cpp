#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
struct point
{
	int x,y;
}p[2020];
int n,sumx,sumy,ans;
bool used[2020];
map<pair<int,int>,vector<int> >mp;
map<pair<long long,long long>,bool>st;
long long pos[2020];
long long gcd(long long a,long long b)
{
	if(!a||!b)return a+b;
	return gcd(b,a%b);
}
void check(long long cs,long long sn)
{
	long long g=gcd(cs,sn);
	cs/=g,sn/=g;
	if(cs<0||(cs==0&&sn<0))cs=-cs,sn=-sn;
//	printf("%lld %lld\n",cs,sn);
	if(st[make_pair(cs,sn)])return;
	st[make_pair(cs,sn)]=1;
	if(!cs)
	{
		for(int i=1;i<=n;++i)pos[i]=p[i].y;
		sort(pos+1,pos+1+n);
		for(int i=2;2*i<=n+1;++i)if(pos[i]+pos[n+1-i]!=pos[1]+pos[n])return;
		++ans;
		return;
	}
	for(int i=1;i<=n;++i)pos[i]=p[i].x*cs+p[i].y*sn;
	sort(pos+1,pos+1+n);
	for(int i=2;2*i<=n+1;++i)if(pos[i]+pos[n+1-i]!=pos[1]+pos[n])return;
	++ans;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d %d",&p[i].x,&p[i].y),sumx+=p[i].x,sumy+=p[i].y;
	if(2ll*sumx%n==0&&2ll*sumy%n==0)
	{
		for(int i=1;i<=n;++i)
			if(p[i].x*n==sumx&&p[i].y*n==sumy)used[i]=1;
			else mp[make_pair(p[i].x,p[i].y)].emplace_back(i);
		int mx=2ll*sumx/n,my=2ll*sumy/n;
		for(int i=1;i<=n;++i)
			if(!used[i])
			{
				auto o=make_pair(mx-p[i].x,my-p[i].y);
				if(mp[o].size())
				{
					used[i]=1;
					used[mp[o].back()]=1;
					mp[o].pop_back();
				}
			}
		int m=0;
		for(int i=1;i<=n;++i)if(!used[i])p[++m]=p[i];
		n=m;
		if(!n)return printf("-1"),0;
	}
	sumx=sumy=0;
	for(int i=1;i<=n;++i)sumx+=p[i].x,sumy+=p[i].y;
//	printf("%d %d\n",sumx,sumy);
	for(int i=1;i<=n;++i)check(1ll*(p[1].y+p[i].y)*n-2ll*sumy,2ll*sumx-1ll*(p[1].x+p[i].x)*n);
	printf("%d",ans);
	return 0;
}