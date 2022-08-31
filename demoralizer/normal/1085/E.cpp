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
int k;
string s,a,b;

bool bigger(map<char, char> m,set<char> ss,int pos){
	bool biga = 0;
	bool smallb = 0;
	rep(i,pos,n){
		if(m.count(s[i])){
			char c = m[s[i]];
			if((c < a[i] && !biga) || (c > b[i] && !smallb)){
				return 0;
			}
			if(c > a[i]) biga = 1;
			if(c < b[i]) smallb = 1;
		}
		else{
			// assign something here
			auto it = ss.begin();
			if(!biga){
				it = ss.upper_bound(a[i]);
			}
			if(it == ss.end()){
				return 0;
			}
			char c = *it;
			if(c <= b[i] || smallb){
				// put c here
				m[s[i]] = c;
				ss.erase(c);
				if(c < b[i]) smallb = 1;
				biga = 1;
			}
			else{
				return 0;
			}
		}
	}
	// found solution - print it
	cout << "YES\n";
	string ans;
	rep(i,0,k){
		char c = 'a' + i;
		if(m.count(c) == 0){
			m[c] = *ss.begin();
			ss.erase(ss.begin());
		}
		ans.pb(m[c]);
	}
	cout << ans << "\n";
	return 1;
}

bool smaller(map<char, char> m,set<char> ss,int pos){
	bool biga = 0;
	bool smallb = 0;
	rep(i,pos,n){
		if(m.count(s[i])){
			char c = m[s[i]];
			if((c < a[i] && !biga) || (c > b[i] && !smallb)){
				return 0;
			}
			if(c > a[i]) biga = 1;
			if(c < b[i]) smallb = 1;
		}
		else{
			// assign something here
			auto it = ss.end();
			if(!smallb){
				it = ss.lower_bound(b[i]);
			}
			if(it == ss.begin()){
				return 0;
			}
			it--;
			char c = *it;
			if(c >= a[i] || biga){
				// put c here
				m[s[i]] = c;
				ss.erase(c);
				if(c > a[i]) biga = 1;
				smallb = 1;
			}
			else{
				return 0;
			}
		}
	}
	// found solution - print it
	cout << "YES\n";
	string ans;
	rep(i,0,k){
		char c = 'a' + i;
		if(m.count(c) == 0){
			m[c] = *ss.begin();
			ss.erase(ss.begin());
		}
		ans.pb(m[c]);
	}
	cout << ans << "\n";
	return 1;
}

void solve(){
	cin >> k >> s >> a >> b;
	if(b < a){
		cout << "NO\n";
		return;
	}
	map<char, char> m;
	set<char> ss;
	rep(i,0,k){
		ss.insert(i + 'a');
	}
	int pos = n;
	n = sz(a);
	rep(i,0,n){
		if(a[i] == b[i]){
			char c = s[i];
			if(m.count(c) && m[c] != a[i]){
				cout << "NO\n";
				return;
			}
			if(m.count(c) == 0 && ss.count(a[i]) == 0){
				cout << "NO\n";
				return;
			}
			m[c] = a[i];
			ss.erase(a[i]);
		}
		else{
			pos = i;
			break;
		}
	}
	
	// try putting something bigger than a[pos]
	if(bigger(m,ss,pos)){
		return;
	}
	// try putting something smaller than b[pos]
	if(smaller(m,ss,pos)){
		return;
	}
	cout << "NO\n";
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