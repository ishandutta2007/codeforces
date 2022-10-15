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
#define MAXN 18
#define MAXB 262144

ld A[MAXN][MAXN];
ld memo[MAXB];

int N;

int main(){
	cin>>N;
	for (int i=0;i<N;++i)for (int j=0;j<N;++j)cin>>A[i][j];
	ll T = (1<<N)-1;
	memo[T] = 1;
	for (int x=T;x>0;--x){
		int bm = x;
		vi V;
		for (int i=0;i<N;++i)if((1<<i) & bm)V.pb(i);
		if (SZ(V) == 1)continue;
		ld p = (ld)1 / (SZ(V)*(SZ(V)-1));
		for (auto i : V){
			for (auto j : V){
				if (i==j)continue;
				// If i wins
				memo[bm ^ (1<<j)] +=(p * memo[bm] * A[i][j]);
				// If j wins
				memo[bm ^ (1<<i)] += (p * memo[bm] * A[j][i]);
			}
		}
	}
	for (int i=0;i<N;++i)printf("%.7lf ",(double)memo[(1<<i)]);
}