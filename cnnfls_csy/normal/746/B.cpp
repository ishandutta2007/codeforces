#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
using namespace std;
string st;
int n,i,j,m;
int main()
{
	cin>>n>>st;
	st=' '+st;
	for (i=n-1;i>0;i-=2) cout<<st[i];
	if (n%2==1)
	for (i=1;i<=n;i+=2)
	cout<<st[i];
	else 
	for (i=2;i<=n;i+=2)
	cout<<st[i];
	return 0;
}