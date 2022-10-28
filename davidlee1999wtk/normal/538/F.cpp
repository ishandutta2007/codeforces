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
#define N 200005
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int a[N],c[N];

int main()
{
	int n,j,k,r,i,now;
	LL ans=0;
	cin>>n;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<n;i++)
	{
		j=i-1;
		for(k=1;k<=j;k=r+1)
		{
			r=j/(j/k);
			if(a[i]<a[j/k])
			{
				c[k]++;
				c[r+1]--;
				ans+=r-k+1;
			}
		}
		if(a[i]<a[0])
		{
			c[i]++;
			ans+=n-i;
		}
	}
	//cout<<ans<<endl;
	now=0;
	for(i=1;i<n;i++)
	{
		now+=c[i];
		printf("%d ",now);
	}
	return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);