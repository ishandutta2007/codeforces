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
	int a,b;
	string s;
	cin >> a >> b >> s;
	s.pb('X');
	
	vector<int> v;
	int cnt = 0;
	for(char c:s){
		if(c == 'X'){
			if(cnt) v.pb(cnt);
			cnt = 0;
		}
		else{
			cnt++;
		}
	}
	sort(all(v));
	reverse(all(v));
	
	while(sz(v) && v.back() < b) v.ppb();
	if(v.empty() || v.back() < a){
		cout << "NO\n";
		return;
	}
	
	if(v[0] >= 2 * b){
		if(sz(v) > 1 && v[1] >= 2 * b){
			cout << "NO\n";
			return;
		}
		
		int x = v[0] - a;
		if(sz(v) % 2){
			// split v[0] -> both [0,b-1], (no parity change)
			// both [a,2b-1] (no parity change)
			if(x <= 2 * b - 2 || (x >= 2 * a && x <= 4 * b - 2)){
				cout << "YES\n";
			}
			else{
				cout << "NO\n";
			}
		}
		else{
			// one [0,b-1] and other [a,2b-1], (parity change)
			if(x >= a && x <= 3*b-2){
				cout << "YES\n";
			}
			else{
				cout << "NO\n";
			}
		}
	}
	else{
		// both can do only 1 move
		if(sz(v) % 2){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
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