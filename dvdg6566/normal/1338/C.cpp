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
const ll MAXN = 500100;
const ll INF = 1e18;
const ll MOD = 1e9+7;

ll N,a,b,c,d,T,A[MAXN];
ll sum,ans;
ll B[MAXN];
vi V[MAXN];
ll deg[MAXN];
int fail;

set<int> S;

ll ask(ll x){
	//cerr<<x<<'\n';
	ll t = (x+2)/3;
	ll p = x%3;
	ll st = 1;
	ll jp = 1;
	//cout<<"Start "<<t<<'\n';
	while(1){
		t -= st;
		st *= 4;
		if(t<=0){
			st/=4;
			t+=st;
			break;
		}
	}
	//cout<<"Left "<<t<<'\n';
	//cout<<st<<'\n';
	ll a = st;
	ll b = st*2;
	ll jumps = st/4;
	--t;
	while (t>0){
		//cerr<<t<<' '<<jumps<<'\n';
		if (t>=3*jumps){
			t -= 3*jumps;
			a+=3*jumps;
			b+=jumps;
		}else if (t >=2*jumps){
			t -= 2*jumps;
			a += 2*jumps;
			b+=3*jumps;
		}else if (t>=jumps){
			t-=jumps;
			a+=jumps;
			b+=2*jumps;
		}
		jumps/=4;
	}
	if (p==0)return a^b;
	if (p==1)return a;
	if (p==2)return b;
	return 0;
}

int main(){

	cin>>T;
	while (T--){
		cin>>a;
		cout<<ask(a)<<'\n';
		
	}
}