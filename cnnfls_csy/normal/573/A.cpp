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
int n,i,x;
vector<int> num;
int main()
{
	cin>>n;
	for (i=1;i<=n;i++) 
	{
		cin>>x;
		num.push_back(x);
	}
	for (i=0;i<n;i++)
	{
		while (!(num[i]%2)) num[i]/=2;
		while (!(num[i]%3)) num[i]/=3;
	}
	sort(num.begin(),num.end());
	if (num[0]==num.back()) cout<<"Yes";
	else cout<<"No";
	return 0;
}