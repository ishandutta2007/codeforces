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
long long n,i,j;
vector<long long> ans;
int main()
{
	for (i=1;i<=9;i++)
	{
		for (j=1;j<=1e10;j*=10)
		{
			ans.push_back(i*j);
		}
	}
	sort(ans.begin(),ans.end());
	cin>>n;
	cout<<*lower_bound(ans.begin(),ans.end(),n+1)-n;
	return 0;
}