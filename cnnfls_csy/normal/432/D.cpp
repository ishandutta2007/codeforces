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
int n,m,i,j,l,r,z[1000005],cntz[1000005];
string st;
vector<int> id,cnt;
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
	cntz[st.length()]=1;
	for (i=1;i<=st.length();i++) cntz[z[i]]++;
	for (i=st.length();i;i--) cntz[i]+=cntz[i+1];
	for (i=1;i<st.length();i++)
	{
		if (z[i]+i==st.length())
		{
			id.push_back(z[i]);
			cnt.push_back(cntz[z[i]]);
		}
	}
	cout<<id.size()+1<<endl;
	for (i=id.size()-1;i>-1;i--)
	{
		cout<<id[i]<<' '<<cnt[i]<<endl;
	}
	cout<<st.length()<<" 1";
	return 0;
}