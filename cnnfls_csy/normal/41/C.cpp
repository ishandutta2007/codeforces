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
int n,m,i,j,pos;
int main()
{
	cin>>st;
	st1=st.substr(1);
	while ((pos=(int(st1.find("dot"))))!=-1&&pos!=st1.length()-3)
	{
		st1.erase(pos,3);
		st1.insert(pos,".");
	}
	if ((pos=(int(st1.find("at"))))!=-1&&pos!=st1.length()-2)
	{
		st1.erase(pos,2);
		st1.insert(pos,"@");
	}
	st=st.substr(0,1)+st1;
	cout<<st;
	return 0;
}