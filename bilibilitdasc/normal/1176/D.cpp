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
bool _prime[2750135];
int ans[2750135];
int cnt;
multiset<int> m;
multiset<int>::iterator itr;
int flag;
int n,a;
int main()
{
	ios_base::sync_with_stdio(false);
	for(int i=2;i<=2750131;i++)
	{
		if(!_prime[i])
		{
			ans[i]=++cnt;
			for(int j=2,res;(res=i*j)<=2750131;j++)
			{
				_prime[res]=1;
				if(!ans[res]) ans[res]=j;
			}
		}
	}
	cin>>n;
	rep(i,(n<<1))
	{
		cin>>a;
		m.insert(a);
	}
	while(!m.empty())
	{
		if(flag++) cout<<' ';
		itr=m.end();itr--;
		if(_prime[*itr])
		{
			m.erase(m.find(ans[*itr]));
			cout<<(*itr);
		}
		else
		{
			m.erase(m.find(ans[*itr]));
			cout<<ans[*itr];
		}
		m.erase(itr);
	}
	cout<<endl;
	return 0;
}