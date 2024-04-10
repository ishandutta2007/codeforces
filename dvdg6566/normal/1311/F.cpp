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

vi des;
ll N;
pi A[MAXN];

struct fenwick{
	ll fw[MAXN];
	fenwick(){}
	void update(ll x, ll v){
		for (;x<=N;x+=x&(-x))fw[x] += v;
	}
	ll query(ll x){
		ll res=0;
		for (;x;x-=x&(-x))res += fw[x];
		return res;
	}
}*val, *one;

ll ans;

int main(){
	cin>>N;
	for (ll i=1;i<=N;++i)cin>>A[i].f;
	for (ll i=1;i<=N;++i)cin>>A[i].s;
	sort(A+1,A+N+1);
	for (ll i=1;i<=N;++i)des.pb(A[i].s);
	sort(ALL(des));
	des.resize(unique(ALL(des)) - des.begin());
	val = new fenwick();
	one = new fenwick();

	for (ll i=1;i<=N;++i){
		ll ord = lb(ALL(des), A[i].s) - des.begin()+1;
		ll rep = one->query(ord);
		ll run = val->query(ord);
		ans += rep*A[i].f - run;
		// cout<<A[i].f<<' '<<A[i].s<<' '<<rep*A[i].f - run<<'\n';
		val->update(ord,A[i].f);
		one->update(ord,1);
	}
	cout<<ans;
}