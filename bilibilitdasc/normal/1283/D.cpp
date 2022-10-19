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
//cin
map<long long,long long> d;
queue<long long> q;
long long ans;
int n,m;
long long t,t0,t1;
vector<long long> r;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	rep(i,n)
	{
		cin>>t;
		d[t]=0;
		q.push(t);
	}
	while(r.size()<m)
	{
		t0=q.front();
		q.pop();
		t1=1+t0;
		if(!d.count(t1))
		{
			d[t1]=d[t0]+1;
			q.push(t1);
			r.pb(t1);
			ans+=d[t1];
		}
		t1=t0-1;
		if(r.size()==m) continue;
		if(!d.count(t1))
		{
			d[t1]=d[t0]+1;
			q.push(t1);
			r.pb(t1);
			ans+=d[t1];
		}
	}
	cout<<ans<<endl;
	for(int i=0;i<r.size();i++)
	{
		cout<<r[i];
		if(i==r.size()-1) cout<<endl;
		else cout<<' ';
	}
	return 0;
 } 
 /*
 108 100
 1 4 7 10
 */