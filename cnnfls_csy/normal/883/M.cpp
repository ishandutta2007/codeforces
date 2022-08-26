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
int x,y,xx,yy;
int main()
{
	cin>>x>>y>>xx>>yy;
	if (x==xx) xx++;
	if (y==yy) yy++;
	cout<<(abs(x-xx)+1+abs(y-yy)+1)*2;
	return 0;
}