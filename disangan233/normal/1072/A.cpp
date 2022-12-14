#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,ans=0;
	cin>>a>>b>>c;
	int d=2*(a+b)-4;
	for(int i=1;i<=c;i++)
	{
		ans+=d;d-=16;
	}
	cout<<ans<<endl;
}