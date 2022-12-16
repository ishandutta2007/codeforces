#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

struct mpq : std::priority_queue<pii> {
    auto begin() const { return c.begin(); }
    auto end() const { return c.end(); }
};

/*
 * Solution based on editorial for 1103D.
 */

const int NMAX = 1000100;
const int PMAX = 11;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int P;
vector<ll> primes;

ll N;
ll K;
ll a[NMAX];
int e[NMAX];
ll dp[PMAX+1][(1<<PMAX)+1];
ll psing[NMAX][PMAX];
ll pprod[NMAX];
char good[NMAX];
mpq bb[1<<PMAX];
vector<int> best[NMAX];

void fac() {
	ll g = a[0];
	for(int i=1;i<N;++i) g = __gcd(g, a[i]);
	for(ll i=2;i*i<=g;++i) {
		if(g%i == 0) {
			primes.push_back(i);
			++P;
			while(g%i == 0) g/=i;
		}
	}
	if(g != 1) {
		primes.push_back(g);
		++P;
	}
	for(int i=0;i<N;++i) {
		ll X = a[i];
		for(int p=0;p<P;++p) {
			psing[i][p] = 1;
			while(X%primes[p] == 0) {
				psing[i][p]*=primes[p];
				X/=primes[p];
			}
		}
		pprod[i] = a[i]/X;
	}
}

/*
 * Set "good" to 1 or 0 based on whether it is one of the best m which has the
 * specific product of primes.
 */
void compress() {
	unordered_map<ll, mpq> mp;
	for(int i=0;i<N;++i) {
		auto& pq = mp[pprod[i]];
		pq.push(pii(e[i], i));
		if(pq.size() > P) pq.pop();
	}
	for(auto& p : mp) {
		for(auto& x : p.second) {
			good[x.second] = 1;
		}
	}
}

void getBests() {
	for(int i=0;i<N;++i) {
		if(!good[i]) continue; 
		for(int m=0;m<(1<<P);++m) {
			ll prod = 1;
			for(int j=0;j<P;++j) {
				if(m&(1<<j)) {
					prod *= psing[i][j];
				}
			}
			if(prod <= K) {
				////cerr << " add " << i << " as a best for " << bitset<11>(m) << endl;
				bb[m].emplace(e[i], i);
				if(bb[m].size() > P) bb[m].pop();
			}
		}
	}
	for(int m=1;m<(1<<P);++m) {
		for(auto& x : bb[m]) {
			best[x.second].push_back(m);
		}
	}
}

inline char get() {
	static char buf[1000000], *S=buf, *T=buf;
	if(S ==T) {
		//cerr << "!! get " << (int) (T-S) << endl;
		T = (S=buf) + fread(buf, 1, 1000000, stdin);
		//cerr << "!! get " << (int) (T-S) << endl;
		if(S==T) return EOF;
	}
	return *S++;
}

inline void read(ll& x) {
	static char c; x = 0;
	for(c=get();c<'0' || c>'9';c=get());
	for(;c>='0' && c<='9';c=get()) x=x*10+c-'0';
	//cerr << "!! " << x << endl;
}

inline void read(int& x) {
	static char c; x = 0;
	for(c=get();c<'0' || c>'9';c=get());
	for(;c>='0' && c<='9';c=get()) x=x*10+c-'0';
}

ll calc() {
	memset(dp, INF, sizeof dp);
	dp[0][0] = 0;
	for(int i=0;i<N;++i) {
		if(best[i].size() == 0) continue;
		for(int p=P-1;p>=0;--p) {
			for(const int b : best[i]) {
				int look = (~b)&((1<<P)-1);
				dp[p+1][b] = min(dp[p+1][b], dp[p][0]+e[i]);
				////cerr << "dp[" << p+1 << "][" << b << "] = " << dp[p+1][b] << endl;
				for(int m=look;m!=0;m=(m-1)&look) {
					dp[p+1][m|b] = min(dp[p+1][m|b], dp[p][m]+e[i]);
					////cerr << "dp[" << p+1 << "][" << (m|b) << "] = " << (dp[p+1][b]) << endl;
				}
			}
		}
	}
	ll ans = INF;
	for(int i=0;i<=P;++i) {
		if(dp[i][(1<<P)-1] != INF) {
			ans = min(ans, dp[i][(1<<P)-1]*i);
		}
	}
	if(ans == INF) ans = -1;
	return ans;
}


//vector<vector<int>> getMasks(

int main () {
	ios_base::sync_with_stdio(0), cin.tie(0);
	read(N);
	read(K);
	for(int i=0;i<N;++i) read(a[i]);
	for(int i=0;i<N;++i) read(e[i]);
	fac();
	compress();
	getBests();
	cout << calc() << endl;
	return 0;
}