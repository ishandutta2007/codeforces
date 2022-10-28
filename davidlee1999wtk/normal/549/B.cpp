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
int a[105],now[105];
int mp[105][105];
char s[105];
int main()
{
	int n,i,j,flag;
	vector<int> ans;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for(j=1;j<=n;j++)
			if(s[j]=='1')
				mp[i][j]=1;
	}
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	flag=1;
	while(flag)
	{
		flag=0;
		for(i=1;i<=n;i++)
			if(a[i]==now[i])
			{
				ans.push_back(i);
				flag=1;
				for(j=1;j<=n;j++)
					if(mp[i][j])
						now[j]++;
			}
	}
	cout<<ans.size()<<endl;
	for(i=0;i<ans.size();i++)
		printf("%d ",ans[i]);
	return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);