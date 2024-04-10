#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
using namespace std;
long long n,m,i,j,sum,to;
vector<long long> ans;
int main()
{
	cin>>n;
	sum=n*(n+1)/2;
	if (sum&1) cout<<"1\n"; else cout<<"0\n";
	sum/=2;
	for (i=n;i;i--)
	{
		if (sum>=i)
		{
			sum-=i;
			ans.push_back(i);
		}
	}
	cout<<ans.size();
	for (i=0;i<ans.size();i++) cout<<' '<<ans[i];
	return 0;
}