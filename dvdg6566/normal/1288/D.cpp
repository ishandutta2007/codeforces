#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
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
#define MAXN 301000

ll N,M,a,b;
ll MOD = 1e9+7;
ll A[MAXN][10];
ll mem[300];

pi ask(ll X){
	memset(mem,0,sizeof(mem));
	for (int i=1;i<=N;++i){
		ll t = 0;
		for (int j=1;j<=M;++j)if (A[i][j] >= X){
			t ^= (1<<(j-1));
		}
		// cout<<i<<' '<<t<<'\n';
		if (mem[t] == 0){mem[t] = i;}
	}
	// for (int i=0;i<64;++i)cout<<mem[i]<<' ';cout<<'\n';
	for (int i=0;i<256;++i){
		for (int j=0;j<256;++j){
			bool ok = 1;
			for (int k=0;k<8;++k){
				if ((j & (1<<k)) > (i & (1<<k)))ok = 0;
			}
			if(!ok)continue;
			// cout<<i<<' '<<j<<'\n';
			if (mem[j] == 0 && mem[i] != 0)mem[j] = mem[i];
		}
	}
	
	for (int i=1;i<=N;++i){
		ll t = 0;
		for (int j=1;j<=M;++j)if (A[i][j] >= X){
			t ^= (1<<(j-1));
		}
		// cout<<i<<' '<<t<<' '<<63-t<<' '<<mem[63-t]<<'\n';
		if (mem[(1<<M)-1-t]!=0)return mp(i,mem[(1<<M)-1-t]);
	}
	return mp(-1,-1);
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N>>M;
	for (int i=1;i<=N;++i)for (int j=1;j<=M;++j)cin>>A[i][j];
	
	ll lb = 0;
	ll ub = 1000000001;
	while (ub > lb){
		ll mid = (lb+ub+1)/2;
		if (ask(mid).f == -1)ub = mid-1;
		else lb = mid;
	}
	pi c = ask(lb);
	cout<<c.f<<' '<<c.s<<'\n';
}