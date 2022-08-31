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
	string s;
	cin >> n >> s;
	vector<int> segs;
	
	char cur = '?';
	int val = 0;
	for(char c:s){
		if(cur != c){
			if(val){
				segs.pb(val);
			}
			val = 1;
			cur = c;
		}
		else{
			val++;
		}
	}
	if(val) segs.pb(val);
	int tot = 0, debt = 0;
	for(int x:segs){
		tot += x - 1;
	}
	
	int ans = 0;
	bool kill_next = 0;
	bool cnt_next = 0;
	
	for(int &x:segs){
		if(kill_next){
			// max debt
			if(cnt_next) ans++;
			cnt_next ^= 1;
			continue;
		}
		ans++;
		x--;
		if(debt < tot){
			debt++;
		}
		else{
			kill_next = 1;
		}
		debt -= min(debt,x);
		tot -= x;
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
	int t=1;
	cin>>t;
	while(t--) solve();
	return 0;
}