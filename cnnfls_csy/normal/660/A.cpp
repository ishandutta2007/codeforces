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
int n,m,i,j,last,now;
vector<int> ans;
int gcd(int x,int y)
{
	return y?gcd(y,x%y):x;
}
int main()
{
	cin>>n;
	cin>>last;
	ans.push_back(last);
	for (i=2;i<=n;i++)
	{
		cin>>now;
		if (gcd(last,now)!=1)
		{
			ans.push_back(1);
		}
		last=now;
		ans.push_back(now);
	}
	cout<<ans.size()-n<<endl;
	for (i=0;i<ans.size();i++) cout<<ans[i]<<' ';
	return 0;
}