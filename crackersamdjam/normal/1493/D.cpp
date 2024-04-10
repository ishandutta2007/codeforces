#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifndef ONLINE_JUDGE
template<typename T>
void pr(T a){std::cerr<<a<<std::endl;}
template<typename T,typename... Args>
void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args>
void pr(Args... args){}
#endif

using namespace std;
using ll = long long;
const int MM = 2e5+5;
const ll mod = 1e9+7;

template<class T> pair<vector<T>, vector<T>> linear_sieve(T N){
	vector<T> low(N+1, 0);
	vector<T> primes;
	for(T i = 2; i <= N; i++){
		if(!low[i])
			low[i] = i, primes.emplace_back(i);
		for(T j = 0; j < (T)size(primes) and primes[j] <= low[i] and i*primes[j] <= N; j++)
			low[i*primes[j]] = primes[j];
	}
	return {move(low), move(primes)};
}

int n, q;
multiset<int> st[MM];
map<int, int> cnt[MM];
ll ans = 1;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	auto [low, primes] = linear_sieve((int)2e5+5);
	cin>>n>>q;
	for(int i = 1,a; i <= n; i++){
		cin>>a;
		// pr("i", i);
		while(low[a]){
			int u = low[a];
			// pr(u);
			int pre = (size(st[u]) == n ? *st[u].begin() : 0);
			if(cnt[i][u])
				st[u].erase(st[u].lower_bound(cnt[i][u]));
			cnt[i][u]++;
			st[u].insert(cnt[i][u]);

			int cur = (size(st[u]) == n ? *st[u].begin() : 0);

			while(pre < cur){
				pre++;
				ans = ans*u%mod;
			}

			a /= u;
		}
	}
	while(q--){
		int i, a; cin>>i>>a;
		// pr("i", i);
		while(low[a]){
			int u = low[a];
			// pr(u);
			int pre = (size(st[u]) == n ? *st[u].begin() : 0);
			if(cnt[i][u])
				st[u].erase(st[u].lower_bound(cnt[i][u]));
			cnt[i][u]++;
			st[u].insert(cnt[i][u]);

			int cur = (size(st[u]) == n ? *st[u].begin() : 0);

			while(pre < cur){
				pre++;
				ans = ans*u%mod;
			}
			a /= u;
		}
		cout<<ans<<'\n';
	}
}