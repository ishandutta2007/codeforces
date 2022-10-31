#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#define LL long long 
#define inf 1000000007
using namespace std;
int main()
{
	LL a,b;
	cin>>a>>b;
	LL t=min(a,b);
	LL ans=1;
	for(LL i=1;i<=t;i++)ans*=i;
	cout<<ans<<endl;
	return 0;
}