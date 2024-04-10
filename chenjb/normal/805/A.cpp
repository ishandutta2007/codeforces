#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <set>
#include <map>
#include <cmath>
#define LL long long 
using namespace std;
int main()
{
	int l,r;
	cin>>l>>r;
	int maxp=l,maxnum=1;
	for(int i=2;i<=sqrt(r);i++)
	{
		int ans=(r/i)-((l-1)/i);
		if (ans>maxnum)maxnum=ans,maxp=i;
	}
	cout<<maxp<<endl;
	return 0;
}