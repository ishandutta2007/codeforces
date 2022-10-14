#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		long long p,q;
		cin>>p>>q;
        if((p-p/2)*(p/2+1)>=q) cout<<"YES\n"; else cout<<"NO\n";
	}
	return 0;
}