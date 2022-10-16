#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T,typename... Args> void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
using ll = long long;
using tt = bitset<60>;
const int MM = 2e5+5;

//mt19937_64 g(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 g((uint64_t) new char);
mt19937_64 g(31);
int randint(int l, int r){return uniform_int_distribution<int>(l, r)(g);}
long long randl(long long l, long long r){return uniform_int_distribution<long long>(l, r)(g);}
double randf(double l, double r){return uniform_real_distribution<double>(l, r)(g);}

int n, m, p;
bool bs[MM][60];
string s;
int dp[1<<15];
ll ans;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>n>>m>>p;
	for(int i = 0; i < n; i++){
		cin>>s;
		for(int j = 0; j < m; j++){
			bs[i][j] = s[j] == '1';
		}
	}
		
	int z = 50;
	while(z--){
		int st = randint(0, n-1);
		vector<int> v;
		for(int i = 0; i < m; i++){
			if(bs[st][i])
				v.emplace_back(i);
		}
		int sz = size(v);
		int full = (1<<sz)-1;

		memset(dp, 0, sizeof dp);

		for(int j = 0; j < n; j++){
			int mask = 0;
			for(int i = 0; i < sz; i++){
				if(bs[j][v[i]])
					mask |= 1<<i;
			}
			dp[full^mask]++;
		}

		for(int i = 0; i < sz; i++){
			for(int mask = 0; mask < (1<<sz); mask++){
				if(mask&(1<<i)){
					dp[mask] += dp[mask^(1<<i)];
				}
			}
		}
		for(int i = 0; i < (1<<sz); i++){
			if(dp[i]*2 >= n){
				int mask = full^i;
				if(__builtin_popcount(mask) > __builtin_popcountll(ans)){
					ans = 0;
					for(int i = 0; i < sz; i++){
						if(mask&(1<<i)){
							ans |= 1LL<<v[i];
						}
					}
				}
			}
		}
	}
	for(int i = 0; i < m; i++)
		cout<<((ans>>i)&1);
	cout<<'\n';
}