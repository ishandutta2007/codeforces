#include<bits/stdc++.h>
//#define TIME
using namespace std;
typedef long long ll;
int n,m;
int ans;
int main()
{
	int i,j;
	cin>>n>>m;
	int a1,b1,a2,b2;
	cin>>a1>>b1>>a2>>b2;
	ans=n;
	for(i=m;i>0;i--)
	{
		ans+=i;
		if(i==b1) ans-=a1;
		if(i==b2) ans-=a2;
		if(ans<0) ans=0;
	}
	cout<<ans;
	return 0;
}