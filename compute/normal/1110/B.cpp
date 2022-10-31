#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int arr[maxn];
int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	priority_queue<int,vector<int>,greater<int> > q; 
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		if(i) q.push(arr[i]-arr[i-1]-1);
	}
	long long ans=n;
	for(int i=0;i<n-k;i++)
	{
		ans+=q.top();
		q.pop();
	}
	printf("%lld\n",ans);
}