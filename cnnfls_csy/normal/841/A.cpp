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
int n,m,i,j;
string st;
int main()
{
	cin>>n>>m>>st;
	sort(st.begin(),st.end());
	for (i=0;i<st.length();)
	{
		for (j=i;j<st.size()&&st[j]==st[i];j++);
		if (j-i>m)
		{
			cout<<"NO";
			return 0;
		}
		i=j;
	}
	cout<<"YES";
	return 0;
}