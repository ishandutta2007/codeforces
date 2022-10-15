#include <bits/stdc++.h>

using namespace std;

bool lucky(int t) 
{
	int h=t/60;
	int m=t%60;
	if(h/10==7 || h%10==7 || m/10==7 || m%10==7)
		return 1;
	return 0;
}

int main() 
{
	int x,h,m;
	cin>>x>>h>>m;	
	int t=60*h+m;
	int ans=0;
	while(lucky(t)==0)
	{
		t-=x;
		if(t<0)
			t+=24*60;
		ans++;
	}
	cout<<ans<<"\n";
	return 0;
}