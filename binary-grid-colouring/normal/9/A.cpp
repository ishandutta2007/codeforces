#include  <bits/stdc++.h>
using namespace std;

int main()
{
	int a,b;
	cin>>a>>b;
	a=max(a,b);
	printf("%d/%d\n",(7-a)/__gcd(7-a,6),6/__gcd(7-a,6));
	return 0;
}