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
#define MAXN 200100
ll MOD = 1e9+7;

ll N,E,Q,a,b,c,d,t,ans,cnt;
ll A[MAXN];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>E;
	while(E--){
		cin>>N;
		ll x=0;
		ll sum=0;
		for (int i=1;i<=N;++i){
			cin>>a;
			x^=a;
			sum+=a;
		}
		cout<<"2\n";
		cout<<x<<' '<<(x+sum)<<'\n';
	}
}