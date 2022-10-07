#include<bits/stdc++.h>
using namespace std;
int n,i,dep[100005],l,r,j,k,quq;
long long s;
bool check(int m)
{
	int i,j;
	dep[1]=1;
	long long ans=s-n-(n-1);
	long long y=n-1;
	for(i=2;y;i++)
	{
		for(j=1;j<=y&&j<=1ll*dep[i-1]*m;j++)
			if(!(ans-(y-j)<=1ll*(y-j-1)*(y-j)/2))
				break;
		j--;
		if(j==0)
			return false;
		dep[i]=j;
		dep[i+1]=0;
		y-=j;
		ans-=y;
	}
	if(ans!=0)
		return false;
	return true;
}
int main()
{
	cin>>n>>s;
	l=1;
	r=n;
	while(l<r)
	{
		int mid=l+r>>1;
		if(check(mid))
			r=mid;
		else
			l=mid+1;
	}
	if(l==n)
	{
		printf("No");
		return 0;
	}
	check(l);
	printf("Yes\n");
	for(i=2;dep[i];i++)
	{
		k=dep[i];
		quq+=dep[i-1];
		for(j=dep[i-1];k;j--)
			for(int p=1;p<=l&&k;p++)
			{
				printf("%d ",quq-j+1);
				k--;
			}
	}
}