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
const ll MOD = 998244353;
const ll INF = 2e9;
const ll MAXN = 3010;
ll T,a,b,c,d,e,f,N,M,E,ans,L;
string A,B;
ll dp[MAXN][MAXN*2];
ll p2[MAXN];

ll ask(ll x, ll y){
	if (x<-1)return 0;
	if (dp[x+1][y+1]!=-1)return dp[x+1][y+1];
	int length_used = (y-x-1);
	if (x == -1 && y >= L){
		// cout<<"Return "<<x<<' '<<y<<' '<<SZ(A) - length_used<<'\n';
		if (x == -1)return SZ(A) - length_used+1;
		return 0;
	}
	if (length_used == SZ(A))return 0;
	// cout<<"Ask "<<x<<' '<<y<<'\n';
	char t = A[length_used];
	char rgt = B[y];
	// cout<<B<<'\n';
	// cout<<y<<' '<<rgt<<'\n';
	ll ans = 0;
	if (x!=-1){
		char lft = B[x];
		if(lft=='!'||lft == t)ans = (ans + ask(x-1,y))%MOD;
	}
	if (rgt == '!' || rgt == t)ans = (ans + ask(x,y+1))%MOD;
	return dp[x+1][y+1] = ans;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>A>>B;
	L = SZ(B);
	while (SZ(B) < 6002)B += '!';
	memset(dp,-1,sizeof(dp));
	ll ans = 0;
	for (int dlk=-1;dlk<=SZ(A);++dlk){
		// if (dlk!=0)continue;
		ll t = ask(dlk,dlk+1);
		// cout<<t<<'\n';
		ans += t;
		ans %= MOD;
		// break;
	}
	cout<<ans;	
}