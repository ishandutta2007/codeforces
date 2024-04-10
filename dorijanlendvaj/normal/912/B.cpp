#include <bits/stdc++.h>

using namespace std;

long long l2(long long a)
{
	long long rj=0;
	while (a)
	{
		a/=2;
		++rj;
	}
	return rj;
}

long long a2n(long long k)
{
	long long a=1;
	for (long long i=0;i<k;++i) a*=2;
	return a;
}

long long n,k;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n>>k;
	if (k==1) cout<<n<<endl;
	else cout<<a2n(l2(n))-1<<endl;
}