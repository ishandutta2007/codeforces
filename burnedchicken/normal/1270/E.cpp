#include <bits/stdc++.h>

#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) for(int i=0; i<(a); i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pow2(x) (1ll<<(x))

using namespace std;

const int Mod=1e9+7;

ll v2(ll n){
	ll x=0;
	while(n%2==0){
		x++;
		n=n/2;
	}
	return x;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	int n;
	cin >> n;
	ll x[n],y[n];
	loop(n) cin >> x[i] >> y[i];
	ll Min=1e18;
	ll dist;
	loop(n){
		loopi(j,n){
			if(i==j) continue;
			dist=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
			Min=min(Min,v2(dist));
		}
	}
	vector<ll> vec;
	vec.push_back(1);
	loop(n){
		if(i==0) continue;
		dist=(x[i]-x[0])*(x[i]-x[0])+(y[i]-y[0])*(y[i]-y[0]);
		if(v2(dist)>Min) vec.push_back(i+1);
	}
	cout << vec.size() << "\n";
	loop(vec.size()) cout << vec[i] << ' ';
	cout << "\n";
	return 0;
}