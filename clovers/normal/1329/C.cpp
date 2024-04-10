#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
typedef pair<int,int> pii;
const int N=2200001;
#define mk make_pair

int t,h,g,n;
int dep[N],vis[N],pos[N],a[N];//x->id
vector<int> ans;
int b[N];

bool del(int x)
{
	int now=x;
	while(a[now])
	{
		if(a[now<<1]>a[now<<1|1]) now=now<<1;
		else now=now=now<<1|1;
	}
	now>>=1; int tmp=now;
	if(dep[now]==g) return 0;
	while(now) 
	{
		pos[a[now]]=pos[a[now>>1]];
		now>>=1;
	}
	while(a[x])
	{
		if(!a[x<<1]&&!a[x<<1|1]) a[x]=0;
		else
		{
			if(a[x<<1]>a[x<<1|1])
			{
				a[x]=a[x<<1];
				x=x<<1;
			}
			else
			{
				a[x]=a[x<<1|1];
				x=x<<1|1;
			}
		}
	} 
	return 1;
}

signed main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&h,&g);
		n=(1<<h)-1;
		ans.clear();
		dep[1]=1;
		int sum=0;
		for(int i=1;i<=n;i++) 
		{
			scanf("%lld",&a[i]);
			pos[a[i]]=i;
			sum+=a[i];
			b[i]=a[i];
			dep[i]=dep[i>>1]+1;
		}
		sort(b+1,b+n+1);
		int rest=n,num=n;
		while(rest>(1<<g)-1)
		{
			int tmp=pos[b[num]];
			if(!del(pos[b[num]]))
			{
				num--;
				continue;
			}
			//del(pos[num]);
			ans.push_back(tmp);
			sum-=b[num];
			num--;
			rest--;
		}
		printf("%lld\n",sum);
		for(int i=0;i<(int)ans.size();i++) printf("%lld ",ans[i]); puts("");
		for(int i=0;i<=n;i++) a[i]=0;
	}
	return 0;
}