#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
ll a,m;
ll nums(ll l,ll r,ll wat){
	return r/wat-(l-1)/wat;
}
ll gcd(ll x,ll y){
	if (y==0) return x;
	return gcd(y,x%y);
}
int main(){
	cin>>T;
	while (T--){
		cin>>a>>m;
		ll dd=gcd(a,m);
		ll ld=a,rd=a+m-1;
		ld/=dd,rd/=dd,m/=dd;
		vector<ll>v;
		for (ll i=2;i*i<=m;i++)if (m%i==0){
			v.push_back(i);
			while (m%i==0) m/=i;
		}
		if (m>1) v.push_back(m);
		ll ans=rd-ld+1;
		for (int i=1;i<(1<<v.size());i++){
			ll tot=1;
			int cnt=0;
			for (int j=0;j<v.size();j++) if ((1<<j)&i)tot*=v[j],cnt++;
			if (cnt%2==0) ans+=nums(ld,rd,tot);
			else ans-=nums(ld,rd,tot);
		}
		cout<<ans<<"\n";
	}
}