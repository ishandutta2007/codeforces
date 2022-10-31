
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#define rep(i,n) for(int i=1;i<=n;i++)
#define mp make_pair
#define pb push_back
using namespace std;
long long n;
int main()
{
	cin>>n;
	long long tt=0;
	long long now=0;
	while (now*10+9<=n)
	{
		now=now*10+9;
		tt++;
	}
	long long ans=tt*9;
	long long x=n-now;
	while (x!=0)
	{
		ans=ans+x%10;
		x/=10;
	}
	cout<<ans<<endl;
}