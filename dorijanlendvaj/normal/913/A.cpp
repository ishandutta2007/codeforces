#include <bits/stdc++.h>

using namespace std;

long long n,m;

long long bpot(long long n,long long k)
{
	if (k==0) return 1;
	long long a=bpot(n,k/2);
	if (k%2)
	{
		return a*a*n;
	}
	else return a*a;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n>>m;
	if (n>30) cout<<m<<endl;
	else
	{
		cout<<m%bpot(2,n)<<endl;
	}
}