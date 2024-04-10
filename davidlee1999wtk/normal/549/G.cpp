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
int p[N];
int main()
{
	int n,i,z;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
		p[i]+=i;
	}
	sort(p+1,p+1+n);
	z=unique(p+1,p+1+n)-(p+1);
	if(z!=n)
	{
		printf(":(\n");
		return 0;
	}
	for(i=1;i<=n;i++)
		printf("%d ",p[i]-i);
	return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);