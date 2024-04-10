#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include<iomanip>
#define sqr(x) (x)*(x)
#define ll long long
using namespace std;
int n,m,i,j,l,r,z[1000005],ans;
string st;
int main()
{
	cin>>st;
	for (i=1;i<=st.length();i++)
	{
		if (i<=r)
		{
			z[i]=min(z[i-l],r-i);
		}
		while (st[z[i]]==st[i+z[i]]) z[i]++;
		if (i>r)
		{
			l=i;
			r=r+z[i];
		}
	}
	for (i=1;i<st.length();i++)
	{
		if (i+z[i]<st.length())
		{
			ans=max(ans,z[i]);
		}
		else ans=max(ans,(int)st.length()-i-1);
	}
	for (i=1;i<st.length();i++)
	{
		if (i+z[i]==st.length()&&z[i]<=ans)
		{
			cout<<st.substr(0,z[i]);
			return 0;
		}
	}
	cout<<"Just a legend";
	return 0;
}