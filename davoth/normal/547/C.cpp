#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=5e5+10,LN=22;
const int MOD=1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int> >, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    if(y==0) return 1;
    if(y==1) return x%mod;
    ll a=y/2,b=1;
    if(y%2) b=x;
    return pow(x*x%mod,a,mod)*b%mod;
}
vector<int> g[N];
bool mark[N],be[N];
int cnt[N],a[N],n,q;
long long ans;
int main()
{
	fast_io;
	for (int i=2;i<N;i++)
		if (!mark[i])	
			for (int j=i;j<N;j+=i)
				mark[j]=1,g[j].push_back(i);
	cin>>n>>q;
	for (int i=0;i<n;i++) cin>>a[i];
	while (q--)
	{
		long long ind,x,tmp=0;
		cin>>ind,ind--,x=a[ind];
		for (int i=0;i<(1<<(g[x].size()));i++)
		{
			int t=0,l=1;
			for (int j=0;j<g[x].size();j++) if (i&(1<<j)) t++,l*=g[x][j];
			if (be[ind]) cnt[l]--;
			if (t&1) tmp-=cnt[l];
			else tmp+=cnt[l];
			if (!be[ind]) cnt[l]++;
		}
		if (be[ind]) ans-=tmp;
		else ans+=tmp;
		cout<<ans<<'\n';
		be[ind]^=1;
	}
}