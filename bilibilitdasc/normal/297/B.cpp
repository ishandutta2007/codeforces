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
multiset<int> a,b;
multiset<int>::iterator itr,jtr;
int a_,b_,n,m,k;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>m>>k;
	rep(i,n)
	{
		cin>>a_;
		a.insert(-a_);
	}
	rep(i,m)
	{
		cin>>b_;
		b.insert(-b_);
	}
	itr=a.end();jtr=b.begin();--itr;
	while(!a.empty()&&(*itr)>=(*jtr))
	{
		//cout<<"+1"<<endl;
		a.erase(a.lower_bound(*jtr));
		//cout<<"+4"<<endl;
		b.erase(jtr);
		//cout<<"+5"<<endl;
		if(a.empty()) break;
		itr=a.end();jtr=b.begin();--itr;
		//cout<<"+3"<<endl;
	}
	//cout<<"+2"<<endl;
	if(a.empty())
	{
		cout<<"NO"<<endl;
	}
	else
	{
		cout<<"YES"<<endl;
	}
	return 0;
}