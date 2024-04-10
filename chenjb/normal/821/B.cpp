#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define LL long long
using namespace std;
LL ans;
LL a,b;
int main()
{
	cin>>a>>b;
	ans=0;
	for(int i=0;i<=b;i++)
	{
		LL t1=(b-i)*a;
		LL sum=i*(i+1)/2*(t1+1)+t1*(t1+1)/2*(i+1);
		ans=max(ans,sum);
	}
	cout<<ans<<endl;
	return 0;
}