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
long long n,m,i,j,x,y;
long long dfs(long long x)
{
	if (x&1) return x/2+1;
	return dfs(x/2);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	while (m--)
	{
		cin>>x;
		cout<<n+1-dfs(2*n-x)<<endl;
	}
	return 0;
}