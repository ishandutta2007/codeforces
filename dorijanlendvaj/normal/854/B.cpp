#include <bits/stdc++.h>

using namespace std;

int n,k;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n>>k;
	if (k==0 || k==n) cout<<0<<' ';
	else cout<<1<<' ';
	cout<<min(n-k,k*2)<<endl;
}