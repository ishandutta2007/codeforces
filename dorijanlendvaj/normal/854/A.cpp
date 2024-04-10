#include <bits/stdc++.h>

using namespace std;

int a;

int gcd(int a,int b)
{
	if (b==0) return a;
	if (a==0) return b;
	return gcd(b,a%b);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>a;
	for (int i=(a-1)/2;i>0;--i)
	{
		if (gcd(a,a-i)==1)
		{
			cout<<i<<' '<<a-i<<endl;
			return 0;
		}
	}
}