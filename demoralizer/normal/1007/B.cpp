#include "bits/stdc++.h"
using namespace std;
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=1e5+5;

int cnt[N];

int tot(int x,int c){
	if(c == 0){
		return 0;
	}
	if(c == 1){
		return x;
	}
	if(c == 2){
		return (x * (x + 1)) / 2;
	}
	return (x * (x - 1) * (x - 2)) / 6 + x * (x - 1) + x;
}

vector<vector<pii>> p;

void solve(){
	int a[3];
	for(int &x:a){
		cin >> x;
	}
	int c[8];
	rep(i,1,8){
		int g = 0;
		rep(j,0,3){
			if(i >> j & 1){
				g = __gcd(g, a[j]);
			}
		}
		c[i] = cnt[g];
	}
	c[6] -= c[7];
	c[5] -= c[7];
	c[4] -= c[5] + c[6] + c[7];
	c[3] -= c[7];
	c[2] -= c[6] + c[3] + c[7];
	c[1] -= c[3] + c[5] + c[7];
	
	int ans = 0;
	for(auto x:p){
		int tmp = 1;
		for(auto y:x){
			int a = y.fr;
			int b = y.sc;
			tmp *= tot(c[a],b);
		}
		ans += tmp;
	}
	
	cout << ans << "\n";
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SIEVE
		sieve();
	#endif
	#ifdef NCR
		init();
	#endif
	
	for(int i = 1; i < N; i++){
		for(int j = i; j < N; j += i){
			cnt[j]++;
		}
	}
	
	
	vector<vector<int>> v = {
		{1,3,5,7},
		{2,3,6,7},
		{4,5,6,7}
	};
	
	vector<vector<int>> z;
	
	rep(i,0,64){
		vector<int> k;
		int tmp = i;
		rep(j,0,3){
			int x = tmp % 4;
			tmp /= 4;
			k.pb(v[j][x]);
		}
		sort(all(k));
		z.pb(k);
	}
	sort(all(z));
	uniq(z);
	
	for(auto k:z){
		vector<pii> tmp;
		map<int, int> m;
		for(int x:k){
			m[x]++;
		}
		for(auto u:m){
			tmp.pb(u);
		}
		p.pb(tmp);
	}
	
	int t=1;
	cin>>t;
	while(t--) solve();
	return 0;
}