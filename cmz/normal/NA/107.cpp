#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1ll<<60;
ll n,k;
map<pair<ll,ll>,ll> ma;
vector<int> l,c;
ll gcd(ll a,ll b){
	while(b != 0){
		ll c = b;
		b = a % b;
		a = c;
	}
	return a;
}
ll rec(int t,ll diff){
	pair<ll,ll> w = make_pair(t,diff);
	if(ma.count(w) != 0) return ma[w];
	if(t == n){
		if(diff == 1) return 0;
		else return INF;
	}
	ll& res = ma[w];
	res = c[t] + rec(t+1,gcd(diff,l[t]));
	res = min(res,rec(t+1,diff));
	return res;
}
int main(){
	cin>>n;
	l.resize(n);
	c.resize(n);
	for (int i = 0; i < n; ++i) cin>>l[i];
	for (int i = 0; i < n; ++i) cin>>c[i];
	ll res = rec(0,0);
	if(res >= INF) puts("-1");
	else cout<<res<<endl;
 
	return 0;
}