#include <bits/stdc++.h>
#define ll long long 
#define ld long double
using namespace std;
ll a,b,n,aa,bb;
int main()
{	
	cin>>n;
	aa=0;
	bb=0;
	ll ans=0;
	for(int i=1;n>=i;i++)
	{
		cin>>a>>b;
		if(i==1)
			ans+=min(a+1,b+1);
		else
		{
			ans+=max((ll)0,min(a,b)-max(aa,bb)+1);
		}
		aa=a;
		bb=b;
		if(aa==bb)
			aa++,bb++;
	}
	cout<<ans;
    return 0;	
}