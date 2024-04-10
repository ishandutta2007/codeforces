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
double x,y,z,t1,t2;
int main()
{
	cin>>x>>y>>z>>t1>>t2;
	y+=z/60;x+=y/60;
	if (x>12) x-=12;
	y/=5;z/=5;
	if (t1>t2) swap(t1,t2);
	if (!(((t1<x&&t2>x)||(t1<y&&t2>y)||(t1<z&&t2>z))&&((x<t1||y<t1||z<t1||x>t2||y>t2||z>t2))))
	{
		cout<<"YES";
		return 0;
	}
	if (t1<t2) swap(t1,t2);
	if (x>t1) x-=12;
	if (y>t1) y-=12;
	if (z>t1) z-=12;
	t1-=12;
	if (!(((t1<x&&t2>x)||(t1<y&&t2>y)||(t1<z&&t2>z))&&((x<t1||y<t1||z<t1||x>t2||y>t2||z>t2))))
	{
		cout<<"YES";
		return 0;
	}
	cout<<"NO";
	return 0;
}