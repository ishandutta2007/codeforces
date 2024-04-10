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
long long n,m,i,s;
int main()
{
	cin>>n>>m;
	if (n>m) swap(n,m);
	s=1;
	for (i=2;i<=n;i++) s*=i;
	cout<<s;
	return 0;
}