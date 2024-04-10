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
char mp[55][55];
char s[6];
int main()
{
	int n,m,i,j,ans=0;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		scanf("%s",mp[i]+1);
	for(i=1;i<n;i++)
		for(j=1;j<=m;j++)
		{
			s[1]=mp[i][j];
			s[2]=mp[i][j+1];
			s[3]=mp[i+1][j];
			s[4]=mp[i+1][j+1];
			sort(s+1,s+1+4);
			if(s[1]=='a'&&s[2]=='c'&&s[3]=='e'&&s[4]=='f')
				ans++;
		}
	cout<<ans<<endl;
	return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);