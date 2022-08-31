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
int len,i;
int main()
{
	cin>>len;
	for (i=5;i<=len;i+=4)
	{
		cout<<"aabb";
	}
	if (len%4==1) cout<<"a";
	if (len%4==2) cout<<"aa";
	if (len%4==3) cout<<"aab";
	if (len%4==0) cout<<"aabb";
	return 0;
}