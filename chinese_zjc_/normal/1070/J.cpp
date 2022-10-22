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
int T,n,m,k,c[26],ans;
char a[200005];
bool dp[30005];
signed main()
{
	std::ios::sync_with_stdio(false);
	std::cin>>T;
	dp[0]=true;
	while(T--)
	{
		std::cin>>n>>m>>k;
		std::fill(c,c+26,0);
		for(int i=1;i<=k;++i)
			std::cin>>a[i],++c[a[i]-'A'];
		ans=INF;
		for(int i=0;i!=26;++i)
		{
			std::fill(dp+1,dp+1+n,false);
			for(int j=0;j!=26;++j)
			{
				if(i==j)continue;
				for(int k=n;k>=c[j];--k)
					dp[k]|=dp[k-c[j]];
			}
			for(int j=0;j<=n;++j)
			{
				if(!dp[j])continue;
				int A=n-j,B=std::max(0ll,m-(k-j-c[i]));
				if(c[i]<A+B)continue;
				ans=std::min(ans,A*B);
			}
		}
		std::cout<<ans<<std::endl;
	}
	return 0;
}