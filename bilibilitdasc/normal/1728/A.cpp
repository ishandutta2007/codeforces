#include <iostream>
#include <algorithm>
#pragma GCC optimize(3)
using namespace std;
int t,n;
int a[25];
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;++i) cin>>a[i];
		cout<<(max_element(a+1,a+n+1)-a)<<endl;
	}
	return 0;
}