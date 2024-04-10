#include<bits/stdc++.h>
#define	MIN(a,b,c)	min(min(a,b),c)
#define	MAX(a,b,c)	max(max(a,b),c)
#define ll          long long
#define itr         vector<ll int>::iterator
#define pb          push_back
#define mp          make_pair
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
using namespace std;
string st;
ll b=0,s=0,c=0,nb,ns,nc,pb,ps,pc,r;
bool check(ll k)
{
	ll ans=0;
	ans+=max(0LL,pb*(k*b-nb));
	ans+=max(0LL,pc*(k*c-nc));
	ans+=max(0LL,ps*(k*s-ns));
	return ans<=r;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int TESTS=1;
	while(TESTS--)
	{
		cin>>st>>nb>>ns>>nc>>pb>>ps>>pc>>r;
		rep(i,0,sz(st))
		{
			if(st[i]=='B')b++;
			else if(st[i]=='C')c++;
			else s++;
		}
		ll lo=0,hi=1e13,mid=(lo+hi)/2;
		while(hi-lo>1)
		{
			if(check(mid))lo=mid;
			else hi=mid;
			mid=(lo+hi)/2;
		}
		if(check(mid+1))cout<<mid+1;
		else cout<<mid;
	}
	return 0;
}