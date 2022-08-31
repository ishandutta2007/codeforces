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
int n,m,i,j,t;
string st;
int main()
{
	cin>>st;
	for (i=0;i<st.length();i++)
	{
		if (st[i]!=st[st.length()-1-i]) t++;
	}
	if (t==2||(!t&&(st.length()&1))) cout<<"YES";
	else cout<<"NO";
	return 0;
}