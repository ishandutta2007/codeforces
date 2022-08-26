#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<queue>
#include<stack>
using namespace std;
int n;
string st1,st2;
int main()
{
	cin>>st1>>st2;
	if (st1==st2) cout<<-1;
	else cout<<max(st1.length(),st2.length());
	return 0;
}