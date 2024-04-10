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
#define MAXN 200100

ll N,E,T,Q,a,b,c,d,e,f;
ll A[MAXN], B[MAXN];
ll G[3][MAXN];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N>>Q;
	int t = N-1;
	for (int i=1;i<=N;++i)G[1][i] = G[2][i] = 1;
	for (int i=1;i<N;++i)A[i] = 2;

	while (Q--){
		cin>>a>>b;
		if (G[a][b] == 1){
			if (b > 1 && G[a][b-1] == 1){
				--A[b-1];
				if (A[b-1] == 0)--t;
			}
			if (b < N && G[a][b+1] == 1){
				--A[b];
				if (A[b] == 0)--t;
			}
		}else{
			if (b > 1 && G[a][b-1] == 1){
				++A[b-1];
				if (A[b-1] == 1)++t;
			}
			if (b < N && G[a][b+1] == 1){
				++A[b];
				if (A[b] == 1)++t;
			}
		}
		G[a][b] = 1-G[a][b];
		// for (int i=1;i<N;++i)cout<<A[i]<<' ';cout<<'\n';
		// cout<<t<<'\n';
		if (t == N-1)cout<<"Yes\n";
		else cout<<"No\n";
	}
}