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
int n,i,s=1;
char ch;
int main()
{
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>ch;
		if (ch=='1') s++;
			else break;
	}
	cout<<min(s,n);
	return 0;
}