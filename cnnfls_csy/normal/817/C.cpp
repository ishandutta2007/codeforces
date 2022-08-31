#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
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
using namespace std;
long long n,m,i,j,l,r,mid,ans;
bool check(long long x)
{
	int i,sum=0;
	char s[105]; 
	string st;
	sprintf(s,"%I64d",x);
	st=s;
	for (i=0;i<st.length();i++)
	{
		sum+=st[i]-'0'; 
	}
	return x-sum>=m;
}
int main()
{
	cin>>n>>m;
	ans=n+1;
	l=1;r=n;
	while (l<r)
	{
		mid=(l+r+1)/2;
		if (check(mid))
		{
			ans=mid;
			r=mid-1;
		}
		else l=mid;
	}
	cout<<n-ans+1;
	return 0;
}