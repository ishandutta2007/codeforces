#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#define int long long

using namespace std;

int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}

const int N=1e6+5;
int n,m,k,a[N],b[N],c[N],cnt[N],num[N][10],sum;

struct Node
{
	int l,id;
	bool operator < (const Node &x)const
	{
		return l<x.l;
	}
}p[N];

vector<int> peo[N];

signed main()
{
	//freopen("yangli.in","r",stdin);
	//freopen("std.out","w",stdout);
	for(int i=1;i<=6;++i)
		a[i]=read();
	sort(a+1,a+1+n);
	n=read();
	for(int i=1;i<=n;++i)
		b[i]=read();
	for(int i=1;i<=n;++i)
		for(int j=6;j>=1;--j)
		{
			p[++m]=(Node){b[i]-a[j],i};
			c[++k]=b[i]-a[j];
		}
	sort(c+1,c+1+k);
	k=unique(c+1,c+1+k)-c-1;
	for(int i=1;i<=m;++i)
		p[i].l=lower_bound(c+1,c+1+k,p[i].l)-c;
	sort(p+1,p+1+m);
	for(int i=1;i<=m;++i)
		num[p[i].id][++cnt[p[i].id]]=c[p[i].l];
	for(int i=1;i<=m;++i)
		peo[p[i].l].push_back(p[i].id);
	memset(cnt,0,sizeof(cnt));
	int now=0,ans=1e18,flag=0;
	for(int i=1;i<=n;++i)
	{
		now=max(now,num[i][1]);
		cnt[i]=1;
	}
	for(int i=1;i<=k;++i)
	{	
		int left=c[i];
		if(flag) left=flag;
		ans=min(ans,now-left);
		for(int j=0;j<peo[i].size();++j)
		{
			if(cnt[peo[i][j]]==6)
			{
				if(flag==0)
					flag=c[i];
			}
			else
			{
				cnt[peo[i][j]]++;
				now=max(now,num[peo[i][j]][cnt[peo[i][j]]]);
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}