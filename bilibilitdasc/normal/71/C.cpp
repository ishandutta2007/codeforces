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
#define f(x) x
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);cin
bool a[100005];
bool ok[100005];
int n;
void chk(int k)
{
	int d=n/k;
	for(int i=0;i<d;i++) ok[i]=1;
	for(int i=0;i<n;i++) ok[i%d]&=a[i];
	for(int i=0;i<d;i++)
	{
		if(ok[i])
		{
			cout<<"YES"<<endl;
			exit(0);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n;
	rep(i,n) cin>>a[i];
	for(int i=1,_s=sqrt(n);i<=_s;i++)
	{
		if(n%i) continue;
		if(i>2) chk(i);
		if(n/i>2) chk(n/i);
	}
	cout<<"NO"<<endl;
	return 0;
}