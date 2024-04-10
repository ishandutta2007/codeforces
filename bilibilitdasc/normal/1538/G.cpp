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
long long t,x,y,a,b,l,r,m,j;//[l,r)
bool valid(long long i)
{
	if(i*a>x) return 0;
	j=(x-a*i)/(b-a);j=min(i,j);
	return a*j+b*(i-j)<=y;
}
void solve()
{
	cin>>x>>y>>a>>b;
	if(a==b)
	{
		cout<<min(x,y)/a<<endl;
		return;
	}
	if(a>b)
	{
		j=a;a=b;b=j;
	}
	l=0;r=1000000005;
	while(r-l>1)
	{
		m=(l+r)>>1;
		if(valid(m)) l=m;
		else r=m;
	}
	cout<<l<<endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>t;
	while(t--)
	solve();
	return 0;
}