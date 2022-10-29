#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;

ll n,s,cnt[N],son[N];

bool check(ll x)
{
	ll now=1,dep=1,sum=0,cnt=0;
	while(cnt+now<=n)
	{
		sum+=now*dep;
		cnt+=now;
		now*=x; dep++;
	}
	ll rest=n-cnt;
	sum+=rest*dep;
	return sum<=s;
}

ll dep[N];
void init(ll k)
{
	ll now=(n+1)*n/2,back=n,front=1;
	for(int i=1;i<=n;i++) dep[i]=i;
	for(int i=1;i<=n;i++) cnt[dep[i]]++;
	ll rest=now-s;
	while(rest>0)
	{
		//cout<<rest<<" "<<front<<" "<<back<<" "<<k<<endl;
		if(back-(front+1)<=rest&&cnt[front]*k>=cnt[front+1]+1)
		{
			rest-=(back-(front+1));
			cnt[back]--; cnt[front+1]++;
			back--;
		}
		else front++;
	}
}

int main() 
{
	scanf("%lld%lld",&n,&s);
	if(s<n*2-1||s>(n+1)*n/2)
	{
		puts("NO");
		return 0;
	}
	ll l=1,r=n-1,mid,best=-1;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(check(mid)) r=mid-1,best=mid;
		else l=mid+1;
	}
	puts("YES");
	init(best);
	int pre=1,now=2;
	for(int i=2;i<=n;i++)
	{
		int tmp=pre;
		for(int j=1;j<=cnt[i];j++)
		{
			if(son[pre]==best) pre++;
			printf("%d ",pre);
			son[pre]++;
		}
		pre=tmp+cnt[i-1];
	}
	return 0;
}//