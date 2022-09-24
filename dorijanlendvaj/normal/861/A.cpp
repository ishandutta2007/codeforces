#include <bits/stdc++.h>

using namespace std;

long long n,k;

long long zav(long long n)
{
	long long b=0,l=n;
	while (l%10==0)
	{
		++b;
		l/=10;
	}
	return b;
}

long long po(long long a,long long b)
{
	if (b==0) return 1;
	return a*po(a,b-1);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n>>k;
	while (zav(n)<k)
	{
		long long p=n/po(10,zav(n));
		if (p%2==0) n*=5;
		else if (p%5==0) n*=2;
		else n*=10;
		//cout<<n<<endl;
	}
	cout<<n<<endl;
}