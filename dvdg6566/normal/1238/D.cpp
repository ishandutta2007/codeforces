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
#define MAXN 1010000
#define MAXL 18

ll ind,ans;
string S;
ll N,l;
deque<ll> D[2];

int main(){
	cin>>N>>S;
	for (ll i=0;i<N;++i){
		if(S[i] == 'A')D[0].pb(i);
		else D[1].pb(i);
	}

	ans = N*(N+1)/2;

	D[0].pb(N);
	D[1].pb(N);
	for (ll i=0;i<N;++i){
		if (S[i] == 'A')D[0].pop_front();
		else D[1].pop_front();

		if (S[i] =='A'){
			ans -= (D[0][0] - i);
			if (SZ(D[1]) != 1){
				if (D[1][0] > D[0][0])--ans;
			}
		}else{
			ans -= (D[1][0] - i);
			if (SZ(D[0]) != 1){
				if (D[0][0] > D[1][0])--ans;
			}
		}
	}
	cout<<ans;
}