#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);i++)
#define per(i,n) for(int i=(n)-1;i>=0;i--)
#define prt(n) cout<<(n)<<endl
#define elif else if
#define str string
#define pb push_back
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);cin
int t,c,h,m;
void solve()
{
	cin>>h>>c>>m;
	c*=2;h*=2;m*=2;
	int mid=(c+h)/2;
	if(m<=mid)
	{
		cout<<2<<endl;
		return;
	}
	ll l=0,r=1e10,mi;//[l,r]*
	while(r-l>1)
	{
		mi=(l+r+1)/2;
		double hasm=mid+(h-mid)/(2.0*mi+1.0);
		if(hasm>m)
		{
			l=mi;
		}
		if(hasm<m)
		{
			r=mi;
		}
		if(hasm==m)
		{
			cout<<2*mi+1<<endl;
			return;
		} 
	}
	if(abs(mid+(h-mid)/((long double)2*r+1)-m)>=abs(mid+(h-mid)/((long double)2*l+1)-m))
	cout<<2*l+1<<endl;
	else
	cout<<2*r+1<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	cin>>t;
	while(t--)
	{
    	solve();
	}
	return 0;
}