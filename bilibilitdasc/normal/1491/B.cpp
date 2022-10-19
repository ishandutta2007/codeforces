#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);i++)
#define per(i,n) for(int i=(n)-1;i>=0;i--)
#define prt(n) cout<<(n)<<endl
#define elif else if
#define str string
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);cin
const int N=100002;
const int M=105;
int a[M];
void solve()
{
	int n,u,v;
	bool istype1=1,istype2=1;
	scanf("%d%d%d",&n,&u,&v);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(i>1)
		{
			if(abs(a[i]-a[i-1])>1) istype1=0;
			if(a[i]!=a[i-1]) istype2=0;
		}
	}
	if(istype2) printf("%d\n",min(u,v)+v);
	else if(istype1) printf("%d\n",min(u,v));
	else printf("%d\n",0);
}
int t;
int main()
{
	
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}