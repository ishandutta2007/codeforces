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

struct str
{
	int haha_count = 0;
	string pre, suf;
};

int count_haha(string s){
	string t = "haha";
	int n = sz(s);
	int cnt = 0;
	rep(i,0,n-3){
		if(s.substr(i,4) == t) cnt++;
	}
	return cnt;
}

string get_pre(string s){
	string t;
	int n = sz(s);
	rep(i,0,min(3ll,n)){
		t.pb(s[i]);
	}
	return t;
}

string get_suf(string s){
	reverse(all(s));
	string t = get_pre(s);
	reverse(all(t));
	return t;
}

void solve(){
	map<string, str> m;
	int n;
	cin >> n;
	
	string last;
	
	rep(i,0,n){
		string var, opr;
		cin >> var >> opr;
		
		last = var;
		
		if(opr == ":="){
			string val;
			cin >> val;
			m[var] = {count_haha(val), get_pre(val), get_suf(val)};
		}
		else{
			string a,plus,b;
			cin >> a >> plus >> b;
			string mid = m[a].suf + m[b].pre;
			string t = m[a].pre + m[b].suf;
			m[var] = {m[a].haha_count + m[b].haha_count + count_haha(mid),
				get_pre(t),
				get_suf(t)};
		}
	}
	cout << m[last].haha_count << "\n";
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