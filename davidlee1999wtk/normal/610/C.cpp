#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#define INF 1000000000
#define N 100005
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int mp[1005][1005];
int main()
{
	int k,i,j,cf=1,m;
	mp[1][1]=1;
	cin>>k;
	for(m=1;m<=k;m++)
	{
		for(i=1;i<=cf;i++)
			for(j=cf+1;j<=cf*2;j++)
				mp[i][j]=mp[i][j-cf];
		for(i=cf+1;i<=cf*2;i++)
			for(j=1;j<=cf;j++)
				mp[i][j]=mp[i-cf][j];
		for(i=cf+1;i<=cf*2;i++)
			for(j=cf+1;j<=cf*2;j++)
				mp[i][j]=mp[i-cf][j-cf]*-1;
		cf*=2;
	}
	for(i=1;i<=cf;i++)
	{
		for(j=1;j<=cf;j++)
			printf("%c",mp[i][j]==1?'+':'*');
		cout<<endl;
	}
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")
//#define O2 __attribute__((optimize("-O2")))