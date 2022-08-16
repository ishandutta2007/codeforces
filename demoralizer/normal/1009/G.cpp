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

const int N=1e5;

int a[N];

int left_set[6];
int right_set[1 << 6];

bool check(){
	rep(i,0,1 << 6){
		int cnt = 0;
		rep(j,0,6){
			if(i >> j & 1){
				cnt += left_set[j];
			}
		}
		if(cnt > right_set[i]){
			return false;
		}
	}
	return true;
}

void solve(){
	string s;
	cin >> s;
	for(char c:s){
		left_set[c - 'a']++;
	}
	int m;
	cin >> m;
	rep(i,0,m){
		int x;
		string t;
		cin >> x >> t;
		x--;
		for(char c:t){
			a[x] |= (1 << (c - 'a'));
		}
		rep(j,0,1 << 6){
			if(j & a[x]){
				right_set[j]++;
			}
		}
	}
	int n = sz(s);
	rep(i,0,n){
		if(a[i] == 0){
			a[i] = (1 << 6) - 1;
			rep(j,0,1 << 6){
				if(j & a[i]){
					right_set[j]++;
				}
			}
		}
	}
	
	if(!check()){
		cout << "Impossible";
		return;
	}
	
	string ans;
	rep(i,0,n){
		rep(j,0,1 << 6){
			if(a[i] & j){
				right_set[j]--;
			}
		}
		rep(j,0,6){
			if(a[i] >> j & 1){
				left_set[j]--;
				if(check()){
					ans.pb('a' + j);
					break;
				}
				left_set[j]++;
			}
		}
	}
	
	cout << ans;
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