#include<iostream>
#include<map>
#define ll long long
using namespace std;
map<ll,ll> mp;
int ans;
ll cal(ll x)
{
	if(mp[x])return mp[x];
	return mp[x]=cal(x>>1)+cal(x&1)+cal(x>>1);
}
void work(ll x,ll l,ll r)
{
	if(x<2){if(x)++ans;return;}
	ll mid=mp[x>>1];
	if(r<=mid)work(x>>1,l,r);
	else if(l<=mid)work(x>>1,l,mid);
	if(l<=mid+1&&r>=mid+1)work(x&1,1,1);
	if(l>mid+1)work(x>>1,l-mid-1,r-mid-1);
	else if(r>mid+1)work(x>>1,1,r-mid-1);
}
int main()
{
	ll n,l,r;
	cin>>n>>l>>r;
	mp[0]=mp[1]=1;cal(n);
	work(n,l,r);
	cout<<ans;
}