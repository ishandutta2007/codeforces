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
	int a[n];
	vector<int> v(n),pf(n);
	rep(i,0,n){
		cin >> a[i];
		v[i] = a[i];
	}
	
	set<int> win_tokens;
	
	sort(all(v));
	pf[0] = v[0];
	rep(i,1,n){
		pf[i] = pf[i - 1] + v[i];
	}
	
	int lowest_win_tokens = v.back();
	win_tokens.insert(lowest_win_tokens);
	for(int i = n - 2; i >=0; i--){
		int x = v[i];
		
		if(pf[upper_bound(all(v),x) - v.begin() - 1] >= lowest_win_tokens){
			// x can win
			lowest_win_tokens = x;
			win_tokens.insert(lowest_win_tokens);
		}
		// else{
		// 	break;
		// }
	}
	
	vector<int> print;
	rep(i,0,n){
		if(win_tokens.count(a[i])){
			print.pb(i+1);
		}
	}
	
	cout << sz(print) << "\n";
	for(int x:print){
		cout << x << " ";
	}
	cout << "\n";
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