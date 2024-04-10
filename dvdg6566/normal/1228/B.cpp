#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define MAXN 310000
#define MAXL 18
ll MOD = 1e9+7;

int V[1010][1010];
int R,C;
int A[1010], B[1010];

int main(){
	cin>>R>>C;
	for (int i=0;i<R;++i)cin>>A[i];
	for (int i=0;i<C;++i)cin>>B[i];
	memset(V,-1,sizeof(V));
	for (int i=0;i<R;++i){
		for (int j=0;j<A[i];++j){
			V[i][j] = 1;
		}
		V[i][A[i]] = 0;
	}
	for (int i=0;i<C;++i){
		for (int j=0;j<B[i];++j){
			if(V[j][i] == 0){
				cout<<0;
				return 0;
			}
			V[j][i] = 1;
		}
		if(V[B[i]][i] == 1){
			cout<<0;
			return 0;
		}
		V[B[i]][i] = 0;
	}
	ll ans = 1;
	for (int i=0;i<R;++i){
		for (int j=0;j<C;++j){
			if(V[i][j] == -1)ans = (ans*2)%MOD;
		}
	}
	cout<<ans;
}