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
long long dif[1005],now,n,i,ans;
int main()
{
	cin>>n>>now;
	for (i=1;i<=n;i++)
	{
		cin>>dif[i];
	}
	sort(dif+1,dif+n+1);
	for (i=1;i<=n;i++)
	{
		while (now*2<dif[i])
		{
			now*=2;
			ans++;
		}
		now=max(now,dif[i]);
	}
	cout<<ans;
	return 0;
}