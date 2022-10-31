#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <cmath>
#define LL long long 
#define inf 1000000007
using namespace std;
LL n,k;
int judge(LL x)
{
	double t=(double)(x)*(double)(k+1);
	if (t>n/2)return 0; else return 1;
}
int main()
{
	cin>>n>>k;
	LL left=0;
	LL right=n;
	while (left<right)
	{
		LL mid=(left+right)/2 + 1;
		if (judge(mid))left=mid;
		else right=mid-1;
	}
	cout<<left<<" "<<left*k<<" "<<n-left*(k+1)<<endl;
	return 0;
}