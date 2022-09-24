#include <bits/stdc++.h>

using namespace std;

long long l10(long long n)
{
	long long rj=0;
	while (n)
	{
		n/=10;
		++rj;
	}
	return rj;
}

long long inv(long long n)
{
	long long rj=0;
	while (n)
	{
		rj*=10;
		rj+=n%10;
		n/=10;
	}
	return rj;
}

long long k,p,r;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>k>>p;
	for (long long i=1;i<=k;++i)
	{
		//cout<<r<<endl;
		r+=i*(pow(10,l10(i)))+inv(i);
		//cout<<r<<endl<<endl;
		r%=p;
	}
	cout<<r<<endl;
}