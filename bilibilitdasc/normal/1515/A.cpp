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
int n;
int a[105];
int x;
int s;
int s1;
void Q()
{
	s=s1=0;
	cin>>n>>x;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		s+=a[i];
	}
	if(s==x)
	{
		cout<<"NO"<<endl;
	}
	else
	{
		sort(a,a+n);
		for(int i=0;i<n-1;i++)
		{
			s1+=a[i];
			if(s1==x)
			swap(a[i],a[i+1]);
		}
		cout<<"YES"<<endl;
		for(int i=0;i<n;i++)
		{
			cout<<a[i];
			if(i==n-1) cout<<endl;
			else cout<<' ';
		}
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