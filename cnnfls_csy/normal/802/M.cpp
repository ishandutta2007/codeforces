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
int n,m,i,j,num[100005],s;
int main()
{
	cin>>n>>m;
	for (i=1;i<=n;i++) cin>>num[i];
	sort(num+1,num+n+1);
	for (i=1;i<=m;i++) s+=num[i];
	cout<<s;
	return 0;
}