#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
using namespace std;
int a,b,n,x,y,i,s;
int main()
{
	cin>>x>>y>>n;
	for (i=1;i<=n;i++)
	if (i%x==0&&i%y==0) s++;
	cout<<s;
	return 0;
}