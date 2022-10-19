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
int n,m,x,t;
struct tower{
	int id;
	int h;
};
bool operator<(const tower&a,const tower&b)
{
	return a.h>b.h;
}
pq<tower> q;
tower a,k;
void Q()
{
	while(!q.empty()) q.pop();
	cin>>n>>m>>x;
	for(int i=1;i<=m;i++)
	{
		a.id=i;
		a.h=0;
		q.push(a);
	}
	cout<<"YES"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>t;
		k=q.top();
		q.pop();
		k.h+=t;
		cout<<k.id<<(i==n-1?'\n':' ');
		q.push(k);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--) Q();
	return 0;
}