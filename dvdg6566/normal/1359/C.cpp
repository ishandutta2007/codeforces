#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define emp emplace
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define f first
#define s second
const ll MAXN = 100100;
const ll MAXK = 17;
const ll INF = 1e18;
const ll MOD = 1e9+7;

ll N,K,W,T,a,b,c,d,e;
ll H,C;

ld ask(ll A, ll B){
	// cerr<<(ld)(A*H+B*C)/(A+B)<<'\n';
	return abs((ld)(A*H+B*C)/(A+B)-K);
}
pi ans;
void aaa(ll a){
	if(ask(a,a-1)<ask(ans.f,ans.s))ans=mp(a,a-1);
}

void askhot(){
	ll low=1;
	ll upp=100010000;
	while(upp>low+1){
		ll mid=(upp+low)/2;
		ll H1 = mid*H+(mid-1)*C;
		ll H2 = (2*mid-1)*K;
		if(H1==H2){
			aaa(mid);
			return;
		}
		else if (H1>H2)low=mid+1;
		else upp=mid;
	}
	for (ll w=-20;w<=20;++w)aaa(low+w);
}

int main(){
	cin>>T;
	while(T--){
		cin>>H>>C>>K;
		if (K<=(H+C)/2){
			cout<<2<<'\n';
			continue;
		}
		ans=mp(1,1);
		askhot();
		cout<<ans.f+ans.s<<'\n';
	}
}