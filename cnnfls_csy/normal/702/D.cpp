#include <iostream>
#include <algorithm>
using namespace std;
long long n,k,a,b,t;
int main()
{
	cin>>n>>k>>a>>b>>t;
	if (k>n) cout<<n*a;
		else cout<<min(min(n*b,(n-1)/k*t+n*a),min(k*a+(n-k)*b,n/k*k*a+(n/k-1)*t+b*(n-n/k*k)));
	return 0;
}