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
ll b,m,i,j,ans,x;
int main()
{
	cin>>m>>b;
	for (i=0;i<=b;i++)
	{
		x=(b-i)*m;
		ans=max(ans,(i*(i+1)/2)*(x+1)+(x*(x+1)/2)*(i+1));
	}
	cout<<ans;
	return 0;
}