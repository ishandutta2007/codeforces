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

const int N=1e5+5;

void solve(){
	int n,k;
	string s;
	cin >> n >> k >> s;
	
	if(n % k != 0){
		cout << "-1\n";
		return;
	}
	
	int ans;
	int L = 0, U = n;
	while(L <= U){
		int m = (L + U) / 2;
		vector<int> put(200);
		string t;
		rep(i,0,m){
			t.pb(s[i]);
			put[s[i]] = (put[s[i]] + k - 1) % k;
		}
		int rem = 0;
		rep(i,'a','z'+1){
			rem += put[i];
		}
		bool found = 0;
		
		if(rem + m <= n){
			int d = n - m - rem;
			rep(i,0,d){
				t.pb('z');
			}
			for(int i = 'z'; i >= 'a'; i--){
				while(put[i]){
					t.pb(i);
					put[i]--;
				}
			}
			if(t >= s){
				found = 1;
			}
		}
		
		if(found){
			ans = m;
			L = m + 1;
		}
		else{
			U = m - 1;
		}
	}
	
	string t;
	vector<int> put(200);
	rep(i,0,ans){
		t.pb(s[i]);
		put[s[i]] = (put[s[i]] + k - 1) % k;
	}
	
	if(ans == n){
		cout << t << "\n";
		return;
	}
	
	rep(i,s[ans] + 1,'z' + 1){
		put[i] = (put[i] + k - 1) % k;
		t.pb(i);
		
		int rem = 0;
		rep(i,'a','z'+1){
			rem += put[i];
		}
		bool found = 0;
		
		if(rem + ans + 1 <= n){
			int d = n - ans - 1 - rem;
			rep(i,0,d){
				t.pb('a');
			}
			for(int i = 'a'; i <= 'z'; i++){
				while(put[i]){
					t.pb(i);
					put[i]--;
				}
			}
			if(t >= s){
				found = 1;
			}
		}
		
		if(found){
			break;
		}
		else{
			while(sz(t) > ans){
				char c = t.back();
				t.ppb();
				put[c] = (put[c] + 1) % k;
			}
		}
	}
	
	cout << t << "\n";
	
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