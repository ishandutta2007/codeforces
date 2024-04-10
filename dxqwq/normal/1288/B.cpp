#include <bits/stdc++.h>
using namespace std;
int dig(long long k)
{
	int res=-1;
	while(k) ++res,k/=10;
	return res;
}
int main() 
{
	int T;
	long long n,m;
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		cout<<n*dig(m+1)<<endl;
	}
	return 0;
}