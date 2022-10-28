#include<bits/stdc++.h>
using namespace std ;
long fact(long n)
{
	if(n==1)return 1;
	return n*fact(n-1);
}
int main()
{
	long a,b;
	cin>>a>>b;
	cout<<fact(min(a,b));
	return 0;
}