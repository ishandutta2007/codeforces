#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <cstdlib>
#include <stack>
#include <queue>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
#define mp make_pair
using namespace std;
long long n,H;
bool check(long long mid)
{
	if (mid>2500000000ll)return 1;
	if (mid<=H)return 1ll*mid*(mid+1)/2 >= n;

	long long width=H-1+mid;
	long long now;
	if (width%2==0)
	{
		now=1ll*(width/2)*(width/2 + 1);
	}
	else
	{
		now=1ll * (width/2 + 1)*(width/2 + 1);
	}

	now=now - 1ll*(H-1)*H/2;

	return now>=n;

}
int main()
{
	cin>>n>>H;
	long long l=1,r=n;
	while (l<r)
	{
		long long mid=(l+r)/2;
		if (check(mid))r=mid; else l=mid+1;
	}
	cout<<l<<endl;
}