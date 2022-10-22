#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<bitset>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<queue>
#include<map>

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
int t,n,a[N],cnt;

struct Node
{
	int l,r;
	bool operator < (const Node &x)const
	{
		if((x.r-x.l+1)==(r-l+1))
			return x.l<l;
		return (x.r-x.l+1)>(r-l+1);
	}
};

inline void work(int l,int r);

int main()
{
	t=read();
	while(t--)
	{
		n=read();
		work(1,n);
		for(int i=1;i<=n;++i)
			printf("%d ",a[i]);
		printf("\n");
	}
	return 0;
}

inline void work(int l,int r)
{
	cnt=0;
	priority_queue<Node> qu;
	qu.push((Node){l,r});
	while(!qu.empty())
	{
		l=qu.top().l;
		r=qu.top().r;
		qu.pop();
		if((r-l+1)%2==1)
		{
			int mid=(l+r)>>1;
			a[mid]=++cnt;
			if(l<=mid-1)
				qu.push((Node){l,mid-1});
			if(mid+1<=r)
				qu.push((Node){mid+1,r});
		}
		else
		{
			int mid=(l+r-1)>>1;
			a[mid]=++cnt;
			if(l<=mid-1)
				qu.push((Node){l,mid-1});
			if(mid+1<=r)
				qu.push((Node){mid+1,r});
		}
			
	}
}