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

#define tset set<char>

void solve(){
	string s;
	cin >> s;
	int x = sz(s) - 1;
	while(s[x] == '0'){
		s[x] = '9';
		x--;
	}
	s[x]--;
	if(s[0] == '0'){
		reverse(all(s));
		s.ppb();
		reverse(all(s));
	}
	int cnt = 0, lst;
	for(char c:s){
		if(c != '0') cnt++, lst = c;
	}
	if(cnt == 1 && lst == '1' && sz(s) % 2 == 0){
		s.ppb();
	}
	if(sz(s) % 2){
		rep(i,1,sz(s)){
			cout << 9;
		}
		cout << "\n";
		return;
	}
	int L = 1, U = sz(s), ans = 0;
	while(L <= U){
		int m = (L + U) / 2;
		tset z;
		rep(i,0,m){
			if(z.count(s[i]))z.erase(s[i]);
			else z.insert(s[i]);
		}
		bool found = (sz(z) == 0);
		if(sz(z) + m <= sz(s)){
			int cnt = sz(s) - m - sz(z);
			rep(i,m,m+cnt){
				if(s[i] != '0') found = 1;
			}
			rep(i,m+cnt,sz(s)){
				int tmp = *z.begin();
				if(tmp > s[i]) break;
				if(tmp < s[i] || i+1 == sz(s)) found = 1;
				z.erase(z.begin());
			}
		}
		if(found){
			ans = m;
			L = m+1;
		}
		else{
			U = m-1;
		}
	}
	tset z;
	rep(i,0,ans) {
		cout << s[i];
		if(z.count(s[i]))z.erase(s[i]);
		else z.insert(s[i]);
	}
	if(ans < sz(s)){
		if(sz(z) + ans == sz(s)){
			auto it = z.lower_bound(s[ans]);
			it--;
			cout << *it;
			char tmp = *it;
			if(z.count(tmp))z.erase(tmp);
			else z.insert(tmp);
			while(sz(z)){
				cout << *z.rbegin();
				tmp = *z.rbegin();
				if(z.count(tmp))z.erase(tmp);
				else z.insert(tmp);
			}
			cout<<"\n";
			return;
		}
		char tmp = s[ans] - 1;
		cout << tmp;
		if(z.count(tmp))z.erase(tmp);
		else z.insert(tmp);
		int cnt = sz(s) - ans - 1 - sz(z);
		rep(i,0,cnt) cout<<9;
		while(sz(z)){
			cout << *z.rbegin();
			tmp = *z.rbegin();
			if(z.count(tmp))z.erase(tmp);
			else z.insert(tmp);
		}
	}
	cout<<"\n";
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