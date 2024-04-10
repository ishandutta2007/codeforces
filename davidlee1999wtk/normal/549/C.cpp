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
int main()
{
	int n,k,a=0,b=0,za,zb,op,i,t;
	cin>>n>>k;
	za=(n-k+1)/2;
	zb=(n-k)/2;
	op=(n-k)%2;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&t);
		if(t%2==1)
			a++;
		else b++;
	}
	if(n==k)
	{
		if(a%2==1)
			printf("Stannis\n");
		else printf("Daenerys\n");
		return 0;
	}
	if(k%2==0)
	{
		if(zb>=a||zb>=b)
			printf("Daenerys\n");
		else if(op==1)
			printf("Stannis\n");
		else printf("Daenerys\n");
	}
	else
	{
		if(za>=b)
			printf("Stannis\n");
		else if(zb>=a)
			printf("Daenerys\n");
		else if(op==1)
			printf("Stannis\n");
		else printf("Daenerys\n");
	}
	return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);