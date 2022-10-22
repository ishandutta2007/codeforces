#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
int a[200005];
int S(int key)
{
	int l=1,r=n;
	while(r>=l)
	{
		int mid=(l+r)/2;
		if(a[mid]>key&&a[mid-1]<=key) return mid-1;
		else if(a[mid]>key) r=mid-1;
		else l=mid+1;
	}
}
int main()
{
	cin>>n>>m;
	int i;
	for(i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	a[0]=-1000000009;
	a[++n]=1000000009;
	for(i=1;i<=m;i++)
	{
		int x;
		cin>>x;
		cout<<S(x)<<" ";
	}
	return 0;
}