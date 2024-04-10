#include <bits/stdc++.h>

using namespace std;

int x,y,a,b,n;

int main()
{
	cin>>x>>y>>a>>b>>n;
	int wo=x*(a-1)+y*(b-1);
	cout<<max(n-wo,0)<<' ';
	if (a<b)
	{
		int ans=0;
		while (x>0 && n>=a) n-=a,--x,++ans;
		while (y>0 && n>=b) n-=b,--y,++ans;
		cout<<ans;
	}
	else
	{
		int ans=0;
		while (y>0 && n>=b) n-=b,--y,++ans;
		while (x>0 && n>=a) n-=a,--x,++ans;
		cout<<ans;
	}
}