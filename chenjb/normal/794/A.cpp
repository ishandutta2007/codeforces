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
	int a,b,c;
	cin>>a>>b>>c;
	int n;
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int t;
		cin>>t;
		if (b<t&&t<c)ans++;
	}
	cout<<ans<<endl;
	return 0;
}