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
int n;
int dbn;
int ans;
void op1(vector<int>& p)
{
	for(int i=0;i<n;i++)
	{
		swap(p[i<<1],p[(i<<1)+1]);
	}
}
void op2(vector<int>& p)
{
	for(int i=0;i<n;i++)
	{
		swap(p[i],p[i+n]);
	}
}
void op(vector<int>& p,bool a)
{
	if(a) op2(p);
	else op1(p);
}
bool chk(vector<int> p)
{
	for(int i=0;i<dbn;i++)
	{
		if(i+1!=p[i]) return 0;
	}
	return 1;
}
int solve(vector<int> p)
{
	vector<int> I=p;
	for(int i=0;;i++)
	{
		if(chk(p)) return i;
		op(p,i&1);
		if(p==I) return -1;
	}
}
int main()
{
	cin>>n;
	vector<int> p;
	p.clear();
	dbn=n<<1;
	rep(i,dbn)
	{
		int x;
		cin>>x;
		p.pb(x);
	}
	ans=solve(p);
	op2(p);
	cout<<min(solve(p)+1,ans);
	return 0;
}