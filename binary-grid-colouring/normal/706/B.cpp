#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[123456];
int Find(int x)
{
	int l = 0, r = n;
	int ans = 0;
	while(l <= r)
	{
		int mid =(l+r)>>1;
		if(a[mid]<=x)
		{
			l = mid + 1;
			ans = mid;
		}
		else r=mid-1;
	}
	return ans;
}
int main()
{
	int x,y;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int q;
	sort(a+1,a+n+1);
	a[0] = -1;
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		cin>>x;
		cout<<Find(x)<<endl;
	} 
	return 0;
 }