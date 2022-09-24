#include <bits/stdc++.h>

using namespace std;

unsigned long long ma,m,b;

unsigned long long bananas(unsigned long long a,unsigned long long b)
{
	return (a-1)*a/2*b+(b-1)*b/2*a;
}

int main()
{
	cin>>m>>b;
	for (int y=b;y>=0;--y)
	{
		unsigned long long x=m*(b-y);
		ma=max(ma,bananas(x+1,y+1));
	}
	cout<<ma<<endl;
}