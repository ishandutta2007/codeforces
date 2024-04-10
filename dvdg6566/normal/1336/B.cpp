#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef pair<ll,pi> pii;
typedef vector<pi> vpi;
typedef set<ll> si;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (ll)x.size()
#define ALL(x) x.begin(),x.end()
const ll MOD = 1e9+7;
const ll INF = 2e9;
const ll MAXN = 200100;
ll T,a,b,c,d,e,f,N,M,E,ans;
set<ll> A[3];

void val(ll a, ll b, ll c){
	if(abs(c)>1e9)return;
	// cerr<<a<<' '<<b<<' '<<c<<'\n';
	// cerr<<ans<<'\n';
	ans = min(ans, (a-b)*(a-b) + (b-c)*(b-c) + (a-c)*(a-c));
}

void ask(ll x, ll y){
	if (abs(y)>1e9)return;
	// cerr<<x<<' '<<y<<'\n';
	ll tar = (x+y)/2;
	ll lower = *A[E].lb(tar);
	ll upper = *(--A[E].ub(tar));
	val(x,y,lower);
	val(x,y,upper);
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>T;
	while (T--){
		ans = LONG_LONG_MAX;
		for (int i=0;i<3;++i){
			A[i].clear();
			A[i].insert(-INF);
			A[i].insert(INF);
		}
		cin>>a>>b>>c;
		for (int i=0;i<a;++i){cin>>d;A[0].insert(d);}
		for (int i=0;i<b;++i){cin>>d;A[1].insert(d);}
		for (int i=0;i<c;++i){cin>>d;A[2].insert(d);}
		for (int i=0;i<3;++i)for (int j=i+1;j<3;++j){
			for (auto rt : A[i]){
				if (abs(rt)>1e9)continue;
				// cerr<<rt<<'\n';
				ll upper = *A[j].lb(rt);
				ll lower = *(--A[j].ub(rt));
				// cerr<<lower<<' '<<upper<<'\n';
				E = 3-i-j;
				ask(rt,lower);
				ask(rt,upper);
			}
		}
		cout<<ans<<'\n';
	}
}