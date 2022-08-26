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
int n,m,k;
int main()
{
	cin>>n>>m>>k;
	while (k--)
	{
		if (n<m) n++; else m++;
	}
	cout<<min(n,m)*2;
	return 0;
}