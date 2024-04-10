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
int num[10000],z,c[10],cf[10]={0,1,10,100,1000,10000,100000,1000000};
int main()
{
	int n,i,now,j,ans=0;
	cin>>i;
		j=i;
		while(j)
		{
			z++;
			ans=max(ans,j%10);
			c[z]=j%10;
			j/=10;
		}
	//reverse(c+1,c+1+z);
	cout<<ans<<endl;
	for(i=1;i<=ans;i++)
	{
		now=0;
		for(j=1;j<=z;j++)
			if(c[j])
				now+=cf[j],c[j]--;
		printf("%d ",now);
	}
	return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);