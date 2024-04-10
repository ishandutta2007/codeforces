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
int p[3456],cnt;
bool notprime[31629];
void getp()
{
	for(int i=2;i<=31622;++i)
	{
		if(!notprime[i])
		{
			p[cnt++]=i;
			for(int j=2,res;(res=i*j)<=31622;++j)
			{
				notprime[res]=1;
			}
		}
	}
}
int a,b,k,l,r;
int getdiv(int div3)
{
	int ans=0;
	for(int i=0;i<cnt;++i)
	{
		if(div3<p[i]) break;
		while(div3%p[i]==0)
		{
			++ans;
			div3/=p[i];
		}
	}
	if(div3!=1) return ++ans;
	return ans;
}
void solve()
{
	cin>>a>>b>>k;
	if(a==b) l=0;
	else if(a%b==0||b%a==0) l=1;
	else l=2;
	r=getdiv(a)+getdiv(b);
	if(a==b)
	{
		if(k==1)
		{
			cout<<"NO"<<endl;
			return ;	
		}
	}
	if(l<=k&&k<=r)
	{
		cout<<"YES"<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	getp();
	cin>>t;
	while(t--)
	solve();
	return 0;
}