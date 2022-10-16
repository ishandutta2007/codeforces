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
const int MM = 1e5+5, LOG = 17;

int n, q, a[MM];
int last[MM];

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

template<class T> struct sparse_table{
	int n; vector<vector<T>> sp;
	T query(int l, int r){
		int k = __lg(r-l+1);
		return min(sp[k][l], sp[k][r-(1<<k)+1]);
	}
	sparse_table(vector<T> v){
		n = size(v);
		sp.resize(__lg(n)+1);
		sp[0] = v;
		for(int i = 1; i <= __lg(n); i++){
			sp[i].resize(n, -1);
			for(int j = 0; j+(1<<i)-1 < n; j++){
				sp[i][j] = min(sp[i-1][j], sp[i-1][j+(1<<(i-1))]);
			}
		}
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	auto [low, primes] = linear_sieve(MM);

	cin>>n>>q;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	
	vector<int> r(n+2);
	r[n+1] = n+1;

	for(int i = n; i; i--){
		vector<int> cur;
		r[i] = n+1;
		while(a[i] > 1){
			int v = low[a[i]];
			a[i] /= v;
			if(last[v]){
				r[i] = min(r[i], last[v]);
			}
			cur.emplace_back(v);
		}
		for(auto v: cur)
			last[v] = i;
	}
	// for(int i = 1; i <= n; i++)
		// cout<<r[i]<<' ';
	// cout<<endl;

	auto go = sparse_table(r);

	//binear lifting
	int sp[LOG][MM];
	memset(sp, -1, sizeof sp);
	for(int i = 1; i <= n; i++){
		//find where
		int l = i, r = n+1;
		while(l <= r){
			int m = (l+r)/2;
			int ret = go.query(i, m);
			// pr("qu", i, m, ret);
			if(ret >= m)
				l = m+1;
			else
				r = m-1;
		}
		sp[0][i] = r;
		// cout<<r<<' ';
	}
	// cout<<endl;

	for(int i = 1; i < LOG; i++){
		for(int j = 1; j <= n; j++){
			int u = sp[i-1][j];
			if(~u) sp[i][j] = sp[i-1][u];
		}
	}

	while(q--){
		int l, r; cin>>l>>r;
		int ans = 0;
		// pr(l, r);
		for(int i = LOG-1; i >= 0; i--){
			if(~sp[i][l] and sp[i][l] <= r){
				l = sp[i][l];
				ans += 1<<i;
			}
		}
		cout<<ans+1<<'\n';
	}
}