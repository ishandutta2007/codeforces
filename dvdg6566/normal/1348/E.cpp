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
const int MAXN=510;
const int MAXK=18;
const ll INF = 1e9;
const ll MOD = 1e9+7;

ll N,M,K,R,C,a,b,c,OX;
vpi V;
ll A[MAXN][2];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N>>K;
	for(int i=0;i<N;++i){
		cin>>a>>b;
		V.pb(a,b);
		R+=a;C+=b;
	}
	ll h=R/K+C/K;
	R%=K;C%=K;
	if(R+C<K){
		cout<<h;
		return 0;
	}
	// want to find if can use remaining
	A[0][1]=1;
	for(int i=0;i<SZ(V);++i){
		a=V[i].f;b=V[i].s;
		for(int w=0;w<K;++w){
			if(a<w||w+b<K)continue;
			// Can cross like this
			for(int j=0;j<K;++j)if(A[(K+j-w)%K][1-i%2]){
				A[j][i%2]=1;
			}
		}
		for(int j=0;j<K;++j)if(A[j][1-i%2])A[j][i%2]=1;
		// for(int j=0;j<K;++j)cout<<A[j][i%2]<<' ';cout<<'\n';
	}
	for(int i=0;i<K;++i)if(A[i][1-SZ(V)%2]){
		if(R<i||i+C<K)continue;
		cout<<h+1;
		return 0;
	}
	cout<<h;
}