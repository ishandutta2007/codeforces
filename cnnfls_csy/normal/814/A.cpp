#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
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
#define sqr(x) (x)*(x)
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
ll n,m,i,j,na[105],nb[105];
string st;
int main()
{
	cin>>n>>m;
	for (i=1;i<=n;i++) cin>>na[i];
	 for (i=1;i<=m;i++) cin>>nb[i];
	sort(nb+1,nb+m+1);
	j=m;
	for (i=1;i<=n;i++)
	{
		if (!na[i])
		{
			na[i]=nb[j--];
		}
	}
	for (i=2;i<=n;i++)
	{
		if (na[i]<na[i-1])
		{
			cout<<"Yes";
			return 0;
		}
	}
	cout<<"No";
	return 0;
}