#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<set>
#include<map>
#define sqr(x) (x)*(x)
using namespace std;
long long n,i,j,num[1000005],s;
vector<long long> ex;
map<long long,int> nu;
int main()
{
	for (i=1;i<=2147483648ll;i*=2) ex.push_back(i);
	cin>>n;
	for (i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
		nu[num[i]]++;
	}
	for (i=1;i<=n;i++)
	{
		nu[num[i]]--;
		for (j=0;j<ex.size();j++)
		{
			if (nu.count(ex[j]-num[i])) s+=nu[ex[j]-num[i]];
		}
	}
	cout<<s;
	return 0;
}