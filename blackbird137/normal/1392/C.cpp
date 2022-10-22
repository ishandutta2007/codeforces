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
int t,n,a[N],tot,ans;

struct Node
{
	int val,l,r,ll,rr;
}b[N];

queue<int> qu;

signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		for(int i=1;i<=n;++i)
			a[i]=read();
		tot=ans=0;
		for(int i=1;i<=n;++i)
			if(a[i]!=a[i-1])
			{
				b[++tot].val=a[i];
				b[tot].l=i;
				b[tot].r=i;
				b[tot].ll=tot-1;
				b[tot].rr=tot+1;
			}
			else
			{
				b[tot].r=i;
				b[tot].rr=tot+1;;
			}
		for(int i=2;i<=tot;++i)
			if(b[i].val<b[i-1].val&&(i==tot||b[i].val<b[i+1].val))
				qu.push(i);
		while(!qu.empty())
		{
			int x=qu.front();
			qu.pop();
			if(b[x].rr==tot+1)
			{
				ans+=b[b[x].ll].val-b[x].val;
				b[x].val=b[b[x].ll].val;
				b[x].l=b[b[x].ll].l;
				b[x].ll=b[b[x].ll].ll;
				b[b[x].ll].rr=x;
				
				if(b[x].ll!=0&&b[x].val<b[b[x].ll].val&&(b[x].rr==tot+1||b[x].val<b[b[x].rr].val))
					qu.push(x);
			}
			else
			{
				int tmp=min(b[b[x].ll].val,b[b[x].rr].val);
				ans+=tmp-b[x].val;
				if(b[b[x].ll].val<=tmp)
				{
					b[x].l=b[b[x].ll].l;
					b[x].ll=b[b[x].ll].ll;
					b[b[x].ll].rr=x;	
				}
				if(b[b[x].rr].val<=tmp)
				{
					
					b[x].r=b[b[x].rr].r;
					b[x].rr=b[b[x].rr].rr;	
					b[b[x].rr].ll=x;
				}
				b[x].val=tmp;
				if(b[x].ll!=0&&b[x].val<b[b[x].ll].val&&(b[x].rr==tot+1||b[x].val<b[b[x].rr].val))
					qu.push(x);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}