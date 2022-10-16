#include<bits/stdc++.h>
using namespace std;
int n,k,a[200003];
bool check(int x,bool c)
{
	int cnt=0;
	for(int i=0;i<n;i++)
		if(c==0)
		{
			cnt++;
			c=1;
		}
		else
			if(a[i]<=x)
			{
				cnt++;
				c=0;
			}
	return cnt>=k;
}
int main()
{
	cin>>n>>k;
	for(int i=0;i<n;i++)scanf("%d",a+i);
	int l=1,r=1000000000;
	while(l!=r){
		int mid=(l+r)/2;
		if(check(mid,0)||check(mid,1))
			r=mid;
		else
			l=mid+1;
	}
	cout<<l;
}