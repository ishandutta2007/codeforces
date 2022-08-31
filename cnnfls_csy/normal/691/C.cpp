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
string st;
int n,m,i,j,be,en,dot;
int main()
{
	cin>>st;
	st="0"+st;
	for (dot=0;dot<st.length()&&st[dot]!='.';dot++);
	if (dot==st.length()) st=st+".0";
	for (be=0;be<st.length()&&(st[be]=='.'||st[be]=='0');be++);
	for (dot=0;st[dot]!='.';dot++);
	for (i=be+1;i<st.length();i++)
	{
		if (!(st[i]=='.'||st[i]=='0')) en=i;
	}
	if (st[be]=='\0') {cout<<0;return 0;} 
	if (be<en)
	{
		cout<<st[be]<<'.';
		for (i=be+1;i<=en;i++)
		{
			if (st[i]!='.') cout<<st[i];
		}
	}
	else cout<<st[be];
	if (be!=dot-1)
	{
		cout<<'E';
		if (dot>=be) cout<<dot-be-1;
		else cout<<dot-be;
	}
	return 0;
}