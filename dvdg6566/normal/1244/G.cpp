#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)x.size()
#define MAXN 210000
#define MAXL 20

ll N,M;
vpi res;
ll off;

int main(){
	cin>>N>>M;

	ll mval = 0;
	for (ll i=1;i<=N;++i)mval += max(N+1-i,i);
	if (mval < M)M = mval;

	ll m = N*(N+1)/2;
	M -= m;
	if (M<0){
		cout<<-1;
		return 0;
	}
	cout<<M+m<<'\n';

	while(1){
		ll ms = N-1;
		if (M <= ms){
			// Resolve yourself
			int dif = M;
			for (int i=1;i<=N;++i){
				if (i == 1 || i == M+1)continue;
				res.pb(i+off,i+off);
			}
			res.pb(M+1+off,1+off);
			if(M!=0)res.pb(1+off,M+1+off);
			sort(ALL(res));
			for (auto i:res)cout<<i.f<<' ';cout<<'\n';
			for (auto i:res)cout<<i.s<<' ';
			return 0;
		}else{
			res.pb(1+off,N+off);
			res.pb(N+off,1+off);
			++off;
			N -= 2;
			M -= ms;
		}
		// cout<<N<<' '<<M<<'\n';
	}
}