#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<map>
#define sqr(x) (x)*(x)
using namespace std;
int n,m,i,j,num[500005],dp[5005];
string st,st1;
vector<int> bi[500005];
map<string,string> mp;
int main()
{
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++)
	{
		cin>>st>>st1;
		mp[st1]=st;
	}
	while (m--)
	{
		cin>>st>>st1;
		st1.erase(st1.length()-1);
		printf("%s %s; #%s\n",st.c_str(),st1.c_str(),mp[st1].c_str());
	}
	return 0;
}