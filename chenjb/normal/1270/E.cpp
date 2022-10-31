#include <cstdio>
#include <iostream>	
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
#define LL long long 
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=1;i<=n;++i)
#define x0 gtmshb
#define x1 gtmjtjl
#define y0 gtmsub
#define y1 gtmsf
const long long base=288230376151711744LL;
int n,x[11000],y[11000];
vector<int> ans;
int main()
{	
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d%d",&x[i],&y[i]);
	while (1)
	{
		int allodd=1,alleven=1;
		for(int i=1;i<=n;i++)
		if ((x[i]+y[i])%2==0)allodd=0;
		else alleven=0;
		if (allodd){ for(int i=1;i<=n;i++)x[i]--; continue; }
		if (alleven)
		{ 
			for(int i=1;i<=n;i++)
			{
				int tx=x[i];
				int ty=y[i];
				x[i]=(tx+ty)/2;
				y[i]=(tx-ty)/2;
			}
			continue;
		}
		break;
	}
	ans.clear();
	for(int i=1;i<=n;i++)if ((x[i]+y[i])&1)ans.pb(i);
	int ret=ans.size();
	cout<<ret<<endl;
	for(int i=0;i<=ret-1;i++)printf("%d%c",ans[i],i==ret-1?'\n':' ');


	return 0;
}