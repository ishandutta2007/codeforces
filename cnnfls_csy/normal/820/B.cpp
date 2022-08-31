#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include<iomanip>
#define sqr(x) (x)*(x)
#define ll long long
using namespace std;
double m,ans=1,fi;
int n,i,j;
int main()
{
	cin>>n>>m;
	fi=(180-(180.0*(n-2)/n))/2;
	for (i=2;i<=n-2;i++)
	{
		if (fabs(fi*i-m)<fabs(fi*ans-m)) ans=i;
	}
	cout<<2<<' '<<1<<' '<<ans+2;
	return 0;
}