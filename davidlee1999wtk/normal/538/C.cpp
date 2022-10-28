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
#define INF 200000000
#define N 100005
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int a[N],b[N];
int main()
{
	int n,m,ans=0,flag,t,l,r,mid,x,now,i;
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		if(i==1)
			ans=b[i]+a[i]-1;
		else
		{
			t=a[i]-a[i-1];
			x=b[i]-b[i-1];
			if(abs(x)>t)
			{
				printf("IMPOSSIBLE\n");
				return 0;
			}
			x=abs(x);
			ans=max(ans,max(b[i],b[i-1]));
			l=0,r=INF;
			now=0;
			while(l<=r)
			{
				mid=(l+r)>>1;
				if(mid+abs(mid-x)<=t)
					now=mid,l=mid+1;
				else r=mid-1;
			}
			ans=max(ans,min(b[i],b[i-1])+now);
		}
		if(i==m)
			ans=max(ans,b[i]+n-a[i]);
	}
	cout<<ans<<endl;
	return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);