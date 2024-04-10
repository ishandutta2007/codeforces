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
string st,st1="heidi";
int i,j;
int main()
{
	cin>>st;
	for (i=0;i<st.length();i++)
	{
		//cerr<<st1[j];
		if (st[i]==st1[j]) j++;
		if (j==5) {cout<<"YES";return 0;}
	}
	cout<<"NO";
	return 0;
}