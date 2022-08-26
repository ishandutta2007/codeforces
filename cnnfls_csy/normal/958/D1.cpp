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
int n,i,j;
double ans[200005],a,b,c;
map<double,int> cnt;
string st;
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>st;
		st.erase(0,1);
		//cerr<<st<<endl;
		for (j=0;j<st.length();j++)
		{
			if (!isdigit(st[j])) break;
		}
		sscanf(st.substr(0,j).c_str(),"%lf",&a);
		st.erase(0,j+1);
		for (j=0;j<st.length();j++)
		{
			if (!isdigit(st[j])) break;
		}
		sscanf(st.substr(0,j).c_str(),"%lf",&b);
		st.erase(0,j+2);
		for (j=0;j<st.length();j++)
		{
			if (!isdigit(st[j])) break;
		}
		sscanf(st.substr(0,j).c_str(),"%lf",&c);
		cnt[(a+b)/c]++;
		ans[i]=(a+b)/c;
	}
	for (i=1;i<=n;i++) cout<<cnt[ans[i]]<<' ';
	return 0;
}