#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
#include<map>
using namespace std;
long long n,m,i,j,num[100005],sum,pr[100005];
map<long long,vector<long long>/**/> fi;
int main()
{
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>num[i];
		fi[num[i]].push_back(i);
		sum+=num[i];
	}
	if (sum&1) {cout<<"NO";return 0;}
	sum/=2;
	for (i=1;i<=n;i++)
	{
		pr[i]=pr[i-1]+num[i];
	}
	for (i=1;i<=n;i++)
	{
		if (pr[i]==sum) {cout<<"YES";return 0;}
		if (pr[i]>sum&&fi[abs(pr[i]-sum)].begin()<upper_bound(fi[abs(pr[i]-sum)].begin(),fi[abs(pr[i]-sum)].end(),i)) {cout<<"YES";return 0;}
		if (pr[i]<sum&&fi[abs(pr[i]-sum)].end()>upper_bound(fi[abs(pr[i]-sum)].begin(),fi[abs(pr[i]-sum)].end(),i)) {cout<<"YES";return 0;}
	}
	cout<<"NO";
	return 0;
}