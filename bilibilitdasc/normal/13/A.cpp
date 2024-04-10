#include <bits/stdc++.h> 
using namespace std;
int x,ans;
int gcd(int a,int b)
{
	if(a%b)
	return gcd(b,a%b);
	return b;
}
int main()
{
	cin>>x;
	for(int i=2;i<x;i++)
	{
		int h=x;
		while(h)
		{
			ans+=h%i;
			h/=i;
		}
	}
	int deno=x-2;
	int gcdd=gcd(ans,deno);
	cout<<ans/gcdd<<'/'<<deno/gcdd;
	return 0;
}