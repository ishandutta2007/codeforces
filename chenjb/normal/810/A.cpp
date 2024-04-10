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
	int n,k;
	int a[200];
	cin>>n>>k;
	double sum=0;
	for(int i=1;i<=n;i++)
		{
			cin>>a[i];	
			sum+=a[i];
		}
	int ans=0;
	while (round(sum/n)<k)
	{
		ans++;
		sum+=k;
		n++;
	}
	cout<<ans<<endl;
	return 0;
}