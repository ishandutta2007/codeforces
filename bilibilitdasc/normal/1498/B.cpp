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
const int N=100005;
int n,w,a[N];
multiset<int> s;
void solve()
{
	cin>>n>>w;
	rep(i,n) cin>>a[i];
	sort(a,a+n);
	reverse(a,a+n);
	s.clear();
	rep(i,n)
	{
		if(s.empty()||*s.rbegin()<a[i]) s.insert(w-a[i]);
		else 
		{
			multiset<int>::iterator z=s.end();
			s.erase(--z);
			s.insert((*z)-a[i]);
		}
	}
	cout<<s.size()<<endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}