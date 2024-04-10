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

int n;
string s,t;
vector<int> operations;

void oper(int x){
	operations.pb(x);
	string tmp;
	// abcd....mnop
	rep(i,0,x){
		tmp.pb(s.back());
		s.ppb();
	}
	for(char c:s){
		tmp.pb(c);
	}
	s = tmp;
}

void rev(){
	oper(n);
}

void solve(){
	cin >> n >> s >> t;
	
	vector<int> cnt(26);
	for(char c:s) cnt[c-'a']++;
	for(char c:t) cnt[c-'a']--;
	rep(i,0,26){
		if(cnt[i] != 0){
			cout << -1;
			return;
		}
	}
	
	int R = n / 2;
	int L = R - 1;
	int cur = 0;
	int width = 0;
	
	while(L >= 0 || R < n){
		char c;
		if(cur == 1){
			c = t[L--];
		}
		else{
			c = t[R++];
		}
		
		// find, merge, pull, reverse
		int j = n - 1;
		while(s[j] != c) j--; // find
		oper(n - j); // merge
		oper(n - width - (n - j));
		rev(); // reverse
		cur ^= 1;
		width++;
	}
	
	if(n % 2 == 0){
		rev();
	}
	
	assert(s == t);
	
	cout << sz(operations) << "\n";
	for(int o:operations){
		cout << o << " ";
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
	//cin>>t;
	while(t--) solve();
	return 0;
}