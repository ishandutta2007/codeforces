#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	long long t,n,a,b,k;
	cin>>t>>n>>a>>b>>k;
	long long na,nb;
	na=(n+1)/2;
	nb=n/2;
	long long op=0,ed=t,mid;
	while(op<ed)
	{
		mid=(op+ed+1)>>1;
		long long x=min(mid,a),y=min(mid,b);
		if(x*na+y*nb>=k*mid) op=mid;
						else ed=mid-1;
	//		cout<<op<<" "<<ed<<endl;
	}
	printf("%lld\n",op);
	return 0;
}