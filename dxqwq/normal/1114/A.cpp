#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x,y,z,a,b,c;
	cin>>x>>y>>z>>a>>b>>c;
	if(a<x)
	{
		cout<<"NO";
		return 0;
	}
	if(a+b<x+y)
	{
		cout<<"NO";
		return 0;
	}
	if(a+b+c<x+y+z)
	{
		cout<<"NO";
		return 0;
	}
	cout<<"YES";
	return 0;
}