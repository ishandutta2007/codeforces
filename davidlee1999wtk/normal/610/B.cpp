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
int a[N];
int main()
{
	int n,i,mn=INF+1,mi,fr,la,flag=0,ans;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]<mn)
		{
			mn=a[i],flag=0,fr=i,mi=i;
			ans=-1;
		}
		else if(a[i]==mn)
		{
			flag=1;
			ans=max(ans,i-mi-1);
			mi=la=i;
		}
	}
	if(flag)
	{
		ans=max(ans,fr-1+n-la);
		cout<<(LL)mn*n+ans<<endl;
	}
	else
	{
		ans=n-1;
		cout<<(LL)mn*n+ans<<endl;
	}
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")
//#define O2 __attribute__((optimize("-O2")))