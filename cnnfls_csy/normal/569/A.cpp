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
int n,m,i,j,s,cnt,now;
int main()
{
	cin>>n>>s>>m;
	//cnt=1;
	while (s<n)
	{
		s*=m;
		cnt++;
	}
	cout<<cnt;
	return 0;
}