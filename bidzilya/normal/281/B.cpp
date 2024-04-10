#include <iostream>
#include <queue>
#include <string>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <iomanip>
using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
const double eps = 1e-9;
const double PI = acos(-1.0);

long long x,y,n;

bool _less(long long na,long long nb,long long a,long long b)
{
	long long t1=x*nb-na*y;
	if (t1<0)t1*=-1;
	long long t2=x*b-a*y;
	if (t2<0)t2*=-1;
	return (t1*b < t2*nb);
}

int main()
{
	#ifndef ONLINE_JUDGE 
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	cin >> x >> y >> n;
	long long aa=-1,ab;
	for (long long i=1; i<=n; i++)
	{
		long long t=(i*x)%y;
		long long a=i*x/y;
		if (t>y-t){t=y-t;a++;}
		if (aa==-1 || _less(a,i,aa,ab))
		{
			aa=a;
			ab=i;
		}
	}
	cout << aa << "/" << ab << endl;
	return 0;
}