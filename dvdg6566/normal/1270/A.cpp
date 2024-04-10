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
#define MAXN 100100
ll MOD = 1e9+7;

ll N,E,Q,a,b,c,d,t,ans,cnt;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>Q;
	while(Q--){
		cin>>N>>a>>b;
		c=0;d=0;
		for (int i=0;i<a;++i){cin>>t;c=max(c,t);}
		for (int i=0;i<b;++i){cin>>t;d=max(d,t);}
		if (c>d)cout<<"YES\n";
		else cout <<"NO\n";
	}
}