#include<iostream>
using namespace std;
long long change1(long long x)
{
	long long t=0;
	while(x)
	{
		if(x%10!=0)
			t=t*10+x%10;
		x/=10;
	}
	return t;
}
long long change2(long long x)
{
	long long t=0;
	while(x)
	{
		t=t*10+x%10;
		x/=10;
	}
	return t;
}
int main()
{
	long long a,b,c;
	cin>>a>>b;
	c=a+b;
	a=change1(a);
	a=change2(a);
	c=change1(c);
	c=change2(c);
	b=change1(b);
	b=change2(b);
	if(a+b==c)
		cout<<"YES";
	else
		cout<<"NO";
}