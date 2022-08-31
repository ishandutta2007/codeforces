#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
#include<set>
using namespace std;
set<string> a;
string st;
int i;
int main()
{
	cin>>st;
	for (i=0;i<st.length();i++)
	a.insert(st.substr(i)+st.substr(0,i));
	cout<<a.size();
	return 0;
}