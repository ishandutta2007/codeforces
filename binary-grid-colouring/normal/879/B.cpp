#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;

int a[567];
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int tmp = a[1];
	int cnt = 0;
	int ans = 0;
	for(int i=2;i<=n;i++)
	{
		if(tmp>a[i])
		{
			cnt++;
		}
		else {
			tmp = a[i];
			cnt = 1;
		}
		if(tmp == n){
			ans = n;
			break;
		}
		if(cnt == k)
		{
			ans = tmp;
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
 }