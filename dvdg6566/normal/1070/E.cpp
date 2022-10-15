#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define f first
#define s second
const ll MAXN = 200100;

vi V;
ll T,N,M,B,a;

ll ask(ll cutoff, ll flag){
	// cout<<"Ask "<<cutoff<<' '<<flag<<'\n';
	ll tot_time = 0;
	ll tot_used = 0;
	ll cur_time = 0;
	ll cur_cnt = 0;
	for (auto i : V)if (i<=cutoff){
		// cout<<i<<' ';
		tot_time += i;
		cur_time += i;
		cur_cnt ++;
		if (tot_time <= B)tot_used++;
		if (cur_cnt == M){
			cur_cnt = 0;
			tot_time += cur_time;
			cur_time = 0;
		}
		// cout<<tot_time<<'\n';
		if (flag == 1 && tot_time > B){
			// cout<<"Total "<<tot_used-1<<'\n';
			return tot_used;
		}
	}
	if (flag == 1)return tot_used;
	return tot_time;
}

vi des;

int main(){
	cin>>T;
	while (T--){
		cin>>N>>M>>B;
		V.clear();
		des.clear();
		for (ll i=1;i<=N;++i){
			cin>>a;
			if (a>B)continue;
			V.pb(a);
			des.pb(a);
		}
		N = SZ(des);
		sort(ALL(des));
		des.resize(unique(ALL(des)) - des.begin());
		ll l = 0;
		ll u = SZ(des)-1; 
		if(l>u){
			cout<<"0 1\n";continue;
		}
		// Searching for the LAST one that can fit
		// for (ll i=0;i<=7;++i){
		// 	cout<<"Res "<<i<<' '<<ask(i,0)<<'\n';
		// }
		while (u > l){
			ll m=(l+u+1)/2;
			ll a = ask(des[m], 0); //0 means ask for time
			if (a > B)u = m-1;
			else l = m;
		}
		// cutoff is either des[l] or des[l+1]
		if (l+1 < SZ(des)){
			// cout<<des[l+1]<<' '<<ask(des[l+1],1)<<'\n';
			// cout<<des[l]<<' '<<ask(des[l],1)<<'\n';
			if (ask(des[l+1],1) > ask(des[l],1))l++;
		}
		cout<<ask(des[l],1)<<' '<<des[l]<<'\n';
	}
}