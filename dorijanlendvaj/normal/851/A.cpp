#include <bits/stdc++.h>

using namespace std;

int n,k,t;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n>>k>>t;
	if (t<=k) cout<<t<<endl;
	else if (t>k && t<=n) cout<<k<<endl;
	else cout<<n+k-t<<endl;
}