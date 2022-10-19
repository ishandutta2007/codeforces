#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define per(i,n) for(int i=(n)-1;i>=0;i--)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define per1(i,n) for(int i=(n);i>=1;i--)
#define repk(i,a,b) for(int i=(a);i<=(b);i++)
#define perk(i,a,b) for(int i=(a);i>=(b);i--)
#define rep0(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define g(x) cout<<#x<<'='<<x<<endl
#define nextp next_permutation
#define pq priority_queue
#define fi first
#define se second
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//long long , 
//ios_base::sync_with_stdio(false);cin
int t;
int n,mx,mn;
int mxid,mnid;
int a[105];
void solve()
{
	cin>>n;
	mx=0,mn=0x3f3f3f3f;
	for(int i=0;i<n;++i)
	{
		cin>>a[i];
		if(a[i]>mx)
		{
			mx=a[i];mxid=i;
		}
		if(a[i]<mn)
		{
			mn=a[i];mnid=i;
		}
	}
	if(mxid<mnid)
	{
		a[0]=mxid;
		mxid=mnid;
		mnid=a[0];
	}
	cout<<min(mxid+1,min(n-mnid,mnid+1+n-mxid))<<endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>t;
	while(t--)
	solve();
	return 0;
 }