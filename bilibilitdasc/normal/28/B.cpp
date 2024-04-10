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
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);cin
int p[105];
int d[105];
int a[105];
int n;
int getp(int a)
{
	if(p[a]==a) return a;
	return p[a]=getp(p[a]);
}
bool same(int a,int b)
{
	return getp(a)==getp(b);
}
void con(int a,int b)
{
	p[getp(a)]=getp(b);
}
bool valid(int a)
{
	return 0<a&&a<=n;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>d[i];
	for(int i=1;i<=n;i++) p[i]=i;
	for(int i=1;i<=n;i++)
	{
		if(valid(i-d[i])) con(i,i-d[i]);
		if(valid(i+d[i])) con(i,i+d[i]);
	}
	for(int i=1;i<=n;i++)
	if(!same(i,a[i]))
	{
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	return 0;
}