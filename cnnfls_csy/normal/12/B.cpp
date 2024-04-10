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
string st,st1;
int n,m,i,j,cnt;
int main()
{
	cin>>st>>st1;
	if (st.length()!=st1.length())
	{
		cout<<"WRONG_ANSWER";
		return 0;
	}
	if (st=="0")
	{
		if (st1=="0")
		{
			cout<<"OK";
		}
		else cout<<"WRONG_ANSWER";
		return 0;
	}
	for (i=0;i<st.length();i++)
	{
		if (st[i]=='0')
		{
			cnt++;
			st.erase(i,1);
			i--;
		}
	}
	sort(st.begin(),st.end());
//	cerr<<st<<' '<<cnt<<endl;
	for (i=1;i<=cnt;i++) st.insert(1,"0");
	if (st!=st1) cout<<"WRONG_ANSWER";
	else cout<<"OK";
	return 0;
}