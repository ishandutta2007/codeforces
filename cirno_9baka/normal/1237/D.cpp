#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int n,i,ans,j,k,m,u,a[500005],mx,mn=1<<30,r;
priority_queue<int> q,del;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		mn=min(mn,a[i]);
		mx=max(mx,a[i]);
	}
	if((mx+1)/2<=mn)
	{
		for(i=1;i<=n;i++)
			printf("-1 ");
		return 0;
	}
	for(i=n+1;i<=4*n;i++)
		a[i]=a[i-n];
	r=1;
	q.push(a[1]);
	for(i=1;i<=n;i++)
	{
		while(1)
		{
			if(!q.empty()&&(q.top()+1)/2>a[r+1])
				break;
			r++;
			q.push(a[r]);
			while(!del.empty()&&q.top()==del.top())
			{
				q.pop();
				del.pop();
			}
		}
		printf("%d ",r-i+1);
		del.push(a[i]);
		while(!del.empty()&&q.top()==del.top())
		{
			q.pop();
			del.pop();
		}
	}
}