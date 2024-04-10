#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
#define pb push_back
using namespace std;
string st1,st2,st3;
int i;
int main()
{
	cin>>st1>>st2;
	for (i=0;i<st1.length();i++)
	{
		if (st1[i]<st2[i]) {cout<<-1;return 0;}
		st3.pb(min(st1[i],st2[i]));
	}
	cout<<st3;
	return 0;
}