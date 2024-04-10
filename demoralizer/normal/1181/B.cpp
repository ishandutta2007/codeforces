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

string add(string s,string t){
	reverse(all(s));
	reverse(all(t));
	if(sz(s) > sz(t)){
		swap(s,t);
	}
	while(sz(s) < sz(t)){
		s.pb('0');
	}
	string res;
	int n = sz(s);
	int c = 0;
	rep(i,0,n){
		int d = s[i] + t[i] + c - '0' - '0';
		c = d / 10;
		d %= 10;
		res.pb(d + '0');
	}
	if(c){
		res.pb(c + '0');
	}
	reverse(all(res));
	return res;
}
string s;
string best;

void split(int x){
	if(s[x] == '0') return;
	string a = s.substr(0,x);
	string b = s.substr(x);
	string ans = add(a,b);
	if(sz(ans) < sz(best) || (sz(ans) == sz(best) && ans < best)){
		best = ans;
	}
}

void solve(){
	int n;
	cin >> n;
	cin >> s;
	
	rep(i,0,n){
		best.pb('9');
	}
	
	int mid = n / 2;
	int tmp = max(1LL,mid);
	rep(i,0,3){
		split(tmp++);
		while(tmp < n && s[tmp] == '0') tmp++;
		if(tmp == n) break;
	}
	
	tmp = max(1LL,mid);
	rep(i,0,3){
		split(tmp--);
		while(tmp > 0 && s[tmp] == '0') tmp--;
		if(tmp == 0) break;
	}
	cout << best;
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