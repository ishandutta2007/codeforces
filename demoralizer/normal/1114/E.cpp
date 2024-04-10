#include "bits/stdc++.h"
using namespace std;
#define int               long long
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

const int N=0;

int query(int x){
	cout << "? " << x << endl;
	int ans;
	cin >> ans;
	return ans;
}

void solve(){
	int n;
	cin >> n;
	
	if(n < 50){
		vector<int> v;
		rep(i,1,n+1){
			v.pb(query(i));
		}
		sort(all(v));
		cout << "! " << v[0] << " " << v[1] - v[0] << endl;
		return;
	}
	
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	auto dist=uniform_int_distribution<int>(1,n);
	
	set<int> s;
	while(sz(s) < 30){
		s.insert(dist(rng));
	}
	vector<int> v;
	for(int x:s){
		v.pb(query(x));
	}
	sort(all(v));
	
	int gcd = 0;
	for(int x:v){
		for(int y:v){
			int tmp = abs(x - y);
			gcd = __gcd(gcd,tmp);
		}
	}
	
	int diff = gcd;
	
	int L = 0, U = n;
	int ans;
	while(L <= U){
		int m = (L + U) / 2;
		int z = m * diff + v[0];
		if(z > 1e9){
			U = m - 1;
			continue;
		}
		cout << "> " << z << endl;
		int tmp;
		cin >> tmp;
		if(tmp){
			ans = m;
			L = m + 1;
		}
		else{
			U = m - 1;
		}
	}
	
	int big = v[0] + ans * diff + diff;
	int small = big - (n - 1) * diff;
	cout << "! " << small << " " << diff << endl;
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
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}