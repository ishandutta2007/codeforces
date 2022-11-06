#include<bits/stdc++.h>
#define Loop(i,a,b) for(int i=a;i<b;++i)
#define NLoop(i,a,b) for(int i=a;i>=b;--i)
#define print(arr,n,m) for(int i=0;i<n;++i) { for(int j=0;j<m;++j) cout<<arr[i][j]<<" "; cout<<endl; }
#define print2(arr,n) for(int i=0;i<n;++i) { cout<<arr[i]<<" "; } cout<<endl;
#define mp(a,b) make_pair(a,b)
#define MOD 1000000007
#define float double
using namespace std;
typedef long long int ll;
ll gcd(ll a,ll b) { if (b == 0) return a; return gcd(b, a % b);  }

ll power(ll x,ll y, ll p) { ll res = 1; x = x % p; while (y > 0) { if (y & 1) res = (res*x) % p; y = y>>1; x = (x*x) % p;   } return res; } 
 

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll n;
	cin>>n;
	vector< pair<ll, ll> > arr(n);
	for(ll i=0;i<n;++i) 
	{
		ll x,y;
		cin>>x>>y;
		arr[i].first = x;
		arr[i].second = y;
	}
	set< pair<float,float> > li;
	ll INF = 3e+9;
	map<float,ll> mp;
	for(ll i=0;i<n;++i)
	{
		for(ll j=i+1;j<n;++j)
		{
			ll x1 = arr[i].first;
			ll y1 = arr[i].second;
			ll x2 = arr[j].first;
			ll y2 = arr[j].second;
			if(x1==x2)
			{
				if(li.find(mp(INF,x1))==li.end())
				{
				
					li.insert(mp(INF,x1));
					mp[INF]++;
				}
				
				continue;
			}
			float m = (1.0*y2-y1)/(x2-x1);
			float c = y1-m*x1;
			if(li.find(mp(m,c))==li.end())
			{
				li.insert(mp(m,c));
				mp[m]++;
			}
		}
	}
	ll ans = (li.size()*(li.size()-1))/2;
	//cout<<li.size()<<endl;
	//ans -= (li.size()-m.size());
	map<float,ll>::iterator it;
	for(it=mp.begin();it!=mp.end();++it)
	{
		ll co = it->second;
	//	cout<<it->first<<"--->"<<co<<endl;
		ans -= ((co*(co-1))/2);
	}
	cout<<ans<<endl;
}