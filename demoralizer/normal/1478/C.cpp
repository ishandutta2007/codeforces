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



void solve(){
	int n;
	cin >> n;
	vector<int> d(2*n);
	rep(i,0,2*n){
		cin >> d[i];
	}
	sort(all(d));
	vector<int> c;
	for(int i = 0; i < 2 * n; i += 2){
		if(d[i] != d[i+1] || d[i] % 2){
			cout << "NO\n";
			return;
		}
		c.pb(d[i] / 2);
	}
	uniq(c);
	if(sz(c) != n){
		cout << "NO\n";
		return;
	}
	int s = 0;
	for(int i = n-1; i > 0; i--){
		c[i] -= c[i-1];
		if(c[i] % i){
			cout << "NO\n";
			return;
		}
		s += c[i] / i * (n - i);
		// cout << c[i] / i * (n - i) << " ";
	}
	// cout << s << " " << c[0] << "\n";
	if(s < c[0] && (c[0] - s) % (n) == 0){
		cout << "YES\n";
	}
	else{
		cout << "NO\n";
	}
	
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
	cin>>t;
	while(t--) solve();
	return 0;
}