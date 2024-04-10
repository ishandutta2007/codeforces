#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
int a,b,c,d;
int main()
{
	cin>>a>>b>>c>>d;
	printf("%d\n",a==d && (c==0 || a!=0));
	return 0;
}