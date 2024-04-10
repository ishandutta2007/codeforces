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

bitset<MAXN> bs;
int fact[MAXN];
int N,K;
int V[MAXN];

int main(){
	cin>>N>>K;
	bs.set();
	bs[0] = bs[1] = 0;
	for (int i=1;i<MAXN;++i)V[i]=i;
	for (int i=2;i<MAXN;++i)fact[i]=1;
	for (int i=2;i*i<MAXN;++i)if(bs[i]){
		for (int j=i*i;j<MAXN;j+=i){
			bs[j] = 0;
			int c = 0;
			while (V[j]%i==0)c++,V[j]/=i;
			fact[j] *= (c+1);
		}
	}
	for (int i=2;i<MAXN;++i){
		if(V[i] != 1)fact[i] *= 2;
	}
	for (int i=2;i<MAXN;++i)fact[i]--;
	int end = N;
	while(1){
		int half = (end+1)/2;
		int tot = 0;
		for (int i=1;i<=end;++i)tot += fact[i];
		// cout<<end<<' '<<tot<<'\n';
		if(tot < K){
			cout<<"No";
			return 0;
		}
		int lhalf = 0;
		for (int i=1;i<=half;++i)lhalf+=fact[i];
		if (lhalf >= K){
			end = half;
			continue; // Only need to consider first half
		}
		// Needs second half
		K -= lhalf;
		vpi V;
		vi out;
		for (int i=1;i<=half;++i)out.pb(i);
		for (int i=half+1;i<=end;++i){
			V.pb(fact[i],i);
		}
		sort(ALL(V));
		reverse(ALL(V));
		
		for (auto i : V){
			// cout<<"Index "<<i.s<<" value "<<i.f<<'\n';
			if (i.f > K){
				continue;
			}else {
				K -= i.f;
				out.pb(i.s);
				continue;
			}
		}
		assert(K==0);
		
		cout<<"Yes\n";
		cout<<SZ(out)<<'\n';
		for (auto i : out)cout<<i<<' ';
		return 0;
	}
}