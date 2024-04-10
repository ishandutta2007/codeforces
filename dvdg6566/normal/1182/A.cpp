#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,ll> pi;
typedef pair<int,pi> pii;
typedef vector<pi> vpi;
typedef set<int> si;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll INF = 1e9;
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
#define MAXN 1000100
#define MAXL 19

int main(){
	int N;
	// freopen("in.txt","r",stdin);
	cin >> N;
	ll ans = 1;
	if (N % 2 == 1){
		cout<<0;
	}else{
		for (int i=0;i<N/2;++i)ans*=2;
		cout<<ans;
	}
}