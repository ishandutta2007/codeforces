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
//ios_base::sync_with_stdio(false);cin
map<string,int> cnt;
vector<int> p;
vector<int> c;
int n,m;
int t,mn,mx;
string s;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	rep(i,n)
	{
		cin>>t;
		p.pb(t);
	}
	rep(i,m)
	{
		cin>>s;
		cnt[s]++;
	}
	for(map<string,int>::iterator i=cnt.begin();i!=cnt.end();i++)
	{
		c.pb(i->second);
	}
	sort(c.begin(),c.end());
	reverse(c.begin(),c.end());
	sort(p.begin(),p.end());
	rep(i,c.size())
	{
		mn+=c[i]*p[i];
	}
	reverse(p.begin(),p.end());
	rep(i,c.size())
	{
		mx+=c[i]*p[i];
	}
	cout<<mn<<' '<<mx<<endl;
	return 0;
}