#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+7;
long long a[maxn];
long long tree[maxn];
long long n,t;
void add(long long x,long long val)
{
	while(x<maxn)
	{
		tree[x]+=val;
		x+=x&-x;
	}
}
long long query(long long x)
{
	long long ret=0;
	while(x>0)
	{
		ret+=tree[x];
		x-=x&-x;
	}
	return ret;
}
int change()
{
	int low=0,high=n;
	while(high-low>1)
	{
		int mid=(high+low)>>1;
		if(query(mid)<=t)
			low=mid;
		else high=mid;
	}
	return high;
}
int main()
{
	memset(tree,0,sizeof(tree));
	scanf("%lld%lld",&n,&t);
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		sum+=a[i];
		add(i,a[i]);
	}
	long long ans=0;
	int cnt=n;
	while(sum!=0&&t!=0)
	{
		while(sum!=0&&t<sum)
		{
			int index=change();
			sum-=a[index];
			add(index,-a[index]);
			cnt--;
		}
		if(sum==0) break;
		ans+=t/sum*cnt;
		t%=sum;
		//cout<<sum<<endl;
	}
	cout<<ans<<endl;
}