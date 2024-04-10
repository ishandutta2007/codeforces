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

const int N=2e5+5;
int n,m,fa[N],p[N],q[N],pos[N],flag;

set<int> s;

int find(int x);

signed main()
{
	n=read();
	for(int i=1;i<=(n<<1);++i)
	{
		char s[5];
		scanf("%s",s+1);
		if(s[1]=='-')
		{
			int x=read();
			pos[x]=i;
			fa[i]=find(fa[i-1]);
			p[i]=0,q[i]=x;
		}
		else fa[i]=i,p[i]=1;
	}
	for(int i=1;i<=n;++i)
	{
		int p=find(pos[i]-1);
		q[p]=i;
		fa[p]=find(p-1);
	}
	flag=1;
	for(int i=1;i<=(n<<1);++i)
		if(p[i]==0)
		{
			if(s.empty())
				flag=0;
			else
			{
				if(*s.begin()!=q[i])
					flag=0;
				else s.erase(s.begin());
			}
		}
		else s.insert(q[i]);
	if(flag)
	{
		printf("YES\n");
		for(int i=1;i<=(n<<1);++i)
			if(p[i]==1) printf("%lld ",q[i]);
	}
	else printf("NO\n");
	return 0;
}

int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}