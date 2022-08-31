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
int n,m,i,j,num[100005],ans,x,c1,c2;
int main()
{
	ios::sync_with_stdio(0); 
	cin>>n;
	for (i=1;i<=n;i++){cin>>x;if (x==1) c1++; else c2++;}
	cout<<min(c1,c2)+max(0,(c1-c2)/3); 
	return 0;
}