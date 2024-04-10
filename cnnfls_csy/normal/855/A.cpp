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
int n,m,i,j;
set<string> s;
string st;
int main()
{
	ios::sync_with_stdio(0);
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>st;
		if (s.count(st))
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
			s.insert(st);
		}
	}
	return 0;
}