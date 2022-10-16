#include<bits/stdc++.h>
using namespace std;
char s[3];
long long ans=1e12;
void func2(long long a,long long b)
{
	if(s[2]=='+')
		ans=min(a+b,ans);
	else
		ans=min(a*b,ans);
}
void func3(long long a,long long b,long long c)
{
	if(s[1]=='+')
	{
		func2(a+b,c);
		func2(a+c,b);
		func2(b+c,a);
	}
	else
	{
		func2(a*b,c);
		func2(a*c,b);
		func2(b*c,a);
	}
}
void func4(long long a,long long b,long long c,long long d)
{
	if(s[0]=='+')
	{
		func3(a+b,c,d);
		func3(a+c,b,d);
		func3(a+d,b,c);
		func3(b+c,a,d);
		func3(b+d,a,c);
		func3(c+d,a,b);
	}
	else
	{
		func3(a*b,c,d);
		func3(a*c,b,d);
		func3(a*d,b,c);
		func3(b*c,a,d);
		func3(b*d,a,c);
		func3(c*d,a,b);
	}
}
int main()
{
	long long a,b,c,d;
	cin>>a>>b>>c>>d>>s[0]>>s[1]>>s[2];
	func4(a,b,c,d);
	cout<<ans;
}