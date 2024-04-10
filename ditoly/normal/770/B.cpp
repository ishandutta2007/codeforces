#include<iostream>
#define ll long long
using namespace std;
int p[20];
void ts(ll x){for(int i=0;x;++i,x/=10)p[i]=x%10;}
ll ti(){ll r=0;for(int i=20;i--;)r=r*10+p[i];return r;}
int sum(){int r=0;for(int i=0;i<20;++i)r+=p[i];return r;}
int main()
{
	ll x,ans;int i,j,mx;
	cin>>x;ts(ans=x);mx=sum();
	for(i=1;i<20;++i)if(p[i])
	{
		for(--p[i],j=0;j<i;++j)p[j]=9;
		if(sum()>mx)mx=sum(),ans=ti();
	}
	cout<<ans;
}