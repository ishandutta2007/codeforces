#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=(int)(2e9);
const ll INF=(ll)(5e18);
const int N=300010;

int T,n,a[N],t[N];
bool cmp(int x,int y){return x>y;}
bool check(int x)
{
	int now=1;
	for(int i=1;i<=n;i++)
	{
		if(t[i]==1) return 1;
		if(now+1ll*(t[i]-1)*(x+1)>n) return 0;
		now++;
	}
	return 1;
}

int main()
{
	cin>>T;
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) 
		{
			scanf("%d",&a[i]);
			t[a[i]]++;
		}
		sort(t+1,t+n+1,cmp);
		int l=0,r=n-2,mid,best;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if(check(mid)) l=mid+1,best=mid;
			else r=mid-1;
		}
		printf("%d\n",best);
		for(int i=1;i<=n;i++) t[i]=0;
	}
	return 0;
}