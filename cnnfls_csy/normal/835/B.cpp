#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<set>
#define sqr(x) (x)*(x)
using namespace std;
int n,m,i,j,sum;
string st;
multiset<int> s;
int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>st;
	for (i=0;i<st.length();i++)
	{
		sum+=st[i]-'0';
		s.insert(st[i]-'0');
	}
	while (sum<n)
	{
		sum+=9-(*s.begin());
		s.erase(s.begin());
	}
	cout<<st.length()-s.size();
	return 0;
}