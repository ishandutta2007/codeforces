#include <iostream>
#define int long long
using namespace std;
main()
{
	int n, cur=2;
	cin>>n;
	for(int a=1; a<=n; a++)
	{
		cout<<(a+1)*(a+1)*a-cur<<"\n";
		cur=a;
	}
}