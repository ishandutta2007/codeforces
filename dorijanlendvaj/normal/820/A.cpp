#include <bits/stdc++.h>

using namespace std;

int c,a,b,v,r,o;

int main()
{
	cin>>c>>a>>b>>v>>r;
	while (true)
	{
		++o;
		c-=a;
		if (c<=0)
		{
			cout<<o<<endl;
			break;
		}
		a=min(a+v,b);
		c+=r;
	}
}