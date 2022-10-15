#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
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
const ll MAXN = 1100000;
const ll INF = 1e18;
const ll MOD = 1e9+7;
const ll H = 500;

ll fw[MAXN];
ll N,Q,a;

void up(ll x,ll v){
	for(;x<=N;x+=x&(-x))fw[x]+=v;
}

int find(int val){
	int res=0;
	for(int i=19;i>=0;--i){
		if(res+(1<<i)>N)continue;
		if(fw[res+(1<<i)]>=val){
			// cerr<<"Fail "<<res+(1<<i)<<' '<<val<<'\n';
			continue;
		}else{
			// cerr<<"Ok "<<(1<<i)<<'\n';
			val-=fw[res+(1<<i)];
			res+=(1<<i);
		}
	}
	return res+1;
}

int ask(int x){
	int res=0;for(;x;x-=x&(-x))res+=fw[x];
	return res;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N>>Q;
	for(int i=1;i<=N;++i){cin>>a;up(a,1);}
	int r=N;
	for(int i=1;i<=Q;++i){
		// for(int j=1;j<=N;++j)cerr<<fw[j]<<' ';cout<<'\n';
		cin>>a;
		if(a>0){
			++r;
			up(a,1);
			continue;
		}else{
			--r;
			int x=abs(a);
			int ind=find(x);
			up(ind,-1);
			// cerr<<ind<<'\n';
		}
	}
	if(r==0)cout<<0;
	else cout<<find(1);
}