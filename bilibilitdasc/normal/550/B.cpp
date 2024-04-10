#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define per(i,n) for(int i=(n)-1;i>=0;i--)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define per1(i,n) for(int i=(n);i>=1;i--)
#define repk(i,a,b) for(int i=(a);i<=(b);i++)
#define perk(i,a,b) for(int i=(a);i>=(b);i--)
#define rep0(i,a,b) for(int i=(a);i<(b);i++)
#define prt(n) cout<<(n)<<endl
#define elif else if
#define str string
#define pb push_back
#define mp make_pair
#define g(x) cout<<#x<<'='<<x<<endl
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);cin
#define inf 0x3f3f3f3f
ll n,l,r,x;
ll sc[16];
int mx(vector<ll> a)
{
	int l=-inf;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]>l) l=a[i];
	}
	return l;
}
int mn(vector<ll> a)
{
	int l=inf;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]<l) l=a[i];
	}
	return l;
}
ll sumof(vector<ll> a)
{
	ll s=0;
	for(int i=0;i<a.size();i++)
	{
		s+=a[i];
	}
	return s;
}
bool isok(vector<ll> a)
{
	if(a.size()<2) return 0;
	int s=sumof(a);
	if(s<l||s>r) return 0;
	if(mx(a)-mn(a)<x) return 0;
	return 1;
}
bool chk(int a)
{
	vector<ll> l;
	for(int i=0;i<n;i++) if((1<<i)&a) l.push_back(sc[i]);
	return isok(l);
}
int cnt;
int main()
{
	scanf("%d%d%d%d",&n,&l,&r,&x);
	for(int i=0;i<n;i++)
	{
		scanf("%d",sc+i);
	}
	for(int i=0,_=1<<n;i<_;i++)
	{
		if(chk(i)) cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}