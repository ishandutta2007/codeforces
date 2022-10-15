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
#define SZ(x) (int)x.size()
#define f first
#define s second
const int MAXN=1010;
const int MAXK=18;
const int INF = 1e9;
const ll MOD = 998244353;

vi V[MAXN];
ll N,a,b,c,d,T,Q,M,x,y,z,u,v,w;

void update(ll w){
	cout<<w<<endl;
	ll h;
	cin>>h;
	if(h==0)exit(0);
	if(h==1)a+=w;
	else if (h==2)b+=w;
	else c+=w;
	// cerr<<"Debug "<<a<<' '<<b<<' '<<c<<'\n';
	if(a==b||b==c||a==c)exit(0);
}

int main(){
	cin>>a>>b>>c;
	cout<<"First"<<endl;
	update(1e10);
	update(1e10+1e9);
	for(int i=0;i<2;++i){
		vi t;
		t.pb(a);t.pb(b);t.pb(c);
		sort(ALL(t));
		ll beta=t[2]-t[1];
		ll alpha=t[1]-t[0];

		if(i==0)update(alpha+beta+beta);	
		else update(alpha);
	}
	// cerr<<"Debug "<<a<<' '<<b<<' '<<c<<'\n';
}