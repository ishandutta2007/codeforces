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
int l,r;
int main()
{
	cin>>l>>r;
	if (l==r&&(l%2)) cout<<l;
	else cout<<2;
	return 0;
}