#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<map>
#define sqr(x) (x)*(x)
using namespace std;
int n,m,i,j,s,t;
map<char,vector<int>/**/> wz;
string st1,st2;
int main()
{
	cin>>st1>>st2;
	for (i=0;i<st1.length();i++) 
	{
		wz[st1[i]].push_back(i);
	}
	for (i=0;i<st2.length();i++)
	{
		if (wz[st2[i]].empty()) {cout<<-1;return 0;}
	}
	s=j=0;
	for (i=0;i<st2.length();i++)
	{
		if (wz[st2[i]].back()<j) {j=0;s++;} 
		j=*lower_bound(wz[st2[i]].begin(),wz[st2[i]].end(),j)+1;
	}
	cout<<s+1;
	return 0;
}