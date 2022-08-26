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
int n,m,i,j,x,y,a,b;
string st;
int main()
{
	cin>>n>>x>>y>>a>>b;
	if (x*n+a*2>y*n+b*2) cout<<"Second";
		else if (x*n+a*2<y*n+b*2) cout<<"First";
			else cout<<"Friendship"; 
	return 0;
}