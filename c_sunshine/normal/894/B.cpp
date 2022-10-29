#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long LL;
const int M=1000000007;
LL fpw(LL a,LL b,LL c)
{
	LL s=1;
	for(a%=c;b;b>>=1,a=a*a%c)
		if(b&1)s=s*a%c;
	return s;
}
int main()
{
	LL a,b,c;
	cin>>a>>b>>c;
	if(c==-1&&(a+b&1))cout<<0<<endl;
	else cout<<fpw(fpw(2,a-1,M),b-1,M)<<endl;
	return 0;
}