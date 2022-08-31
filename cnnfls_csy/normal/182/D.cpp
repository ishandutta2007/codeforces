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
string st1,st2,sa;
int n,m,i,j,g,ans;
bool same;
vector<int> yz;
int gcd(int x,int y)
{
	 return y?gcd(y,x%y):x;
}
int main()
{
	cin>>st1>>st2;
	if (st1[0]!=st2[0])
	{
		cout<<0;
		return 0;
	}
	if (st1.length()<st2.length()) swap(st1,st2); 
	g=gcd(st1.length(),st2.length());
	yz.push_back(1);
	if (g!=1) yz.push_back(g);
	for (i=2;i*i<=g;i++)
	{
		if (!(g%i))
		{
			yz.push_back(i);
			if (i*i!=g)
			{
				yz.push_back(g/i);
			}
		}
	}
	//cout<<yz.size();
	for (i=0;i<yz.size();i++)
	{
		if (st1.substr(0,yz[i])!=st2.substr(0,yz[i])) continue;
		sa="";
		for (j=0;j<yz[i];j++) sa.push_back(st1[j]); 
		same=1;
		for (j=0;j<st1.length();j++)
		{
			if (sa[j%sa.length()]!=st1[j])
			{
				same=0;
				break;
			}
		}
		if (!same) continue;
		for (j=0;j<st2.length();j++)
		{
			if (sa[j%sa.length()]!=st2[j])
			{
				same=0;
				break;
			}
		}
		if (!same) continue;
		ans++;
	}
	cout<<ans;
	return 0;
}