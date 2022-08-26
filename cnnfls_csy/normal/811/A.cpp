#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#define sqr(x) (x)*(x)
using namespace std;
int n,m,i;
int main()
{
	cin>>n>>m;
	for (i=1;n>-1&&m>-1;i++)
	{
		if (i&1) n-=i;
		else m-=i;
	}
	if (n<0) cout<<"Vladik"; else cout<<"Valera";
	return 0;
}