#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[12];
int main()
{
	int n;
	ll ans=0;
	ll ans1=0,ans2=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		a[i%9]++;
		ans1 += n/i;
	}
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			ans2 +=a[i]*a[j]*a[i*j%9];
		}
	}
	ans=ans2-ans1;
	cout<<ans<<endl;
	return 0;
}