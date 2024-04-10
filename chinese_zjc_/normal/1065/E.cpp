//This Code was made by Chinese_zjc_.
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<queue>
#include<stack>
#include<vector>
#include<stack>
#include<cstring>
#include<string>
#include<fstream>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<bitset>
#define int long long
#define double long double
const int INF = 0x3fffffffffffffff;
const double eps = 1e-12;
const double PI = acos(-1);
const int MOD = 998244353;
int power(int A,int B)
{
	int res=1;
	while(B)
	{
		if(B&1)
			res=res*A%MOD;
		B>>=1;
		A=A*A%MOD;
	}
	return res;
}
int sum1(int x)
{
	return x*(x+1)/2%MOD;
}
int n,m,k,b[200005],ans=1;
signed main()
{
	std::ios::sync_with_stdio(false);
	std::cin>>n>>m>>k;
	for(int i=1;i<=m;++i)
	{
		std::cin>>b[i];
		ans=ans*sum1(power(k,b[i]-b[i-1]))%MOD;
	}
	ans=ans*power(k,n-b[m]*2)%MOD;
	std::cout<<ans<<std::endl;
	return 0;
}