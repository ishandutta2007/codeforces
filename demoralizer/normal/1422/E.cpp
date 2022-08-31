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
	string s;
	cin >> s;
	int n = sz(s);
	vector<pair<int, string>> ans;
	
	string tmp,sec="a";
	sec[0]--;
	sec.pb(s.back());
	tmp.pb(s.back());
	s.ppb();
	
	ans.pb({1,tmp});
	bool flag = 1;
	while(sz(s)){
		if(tmp.back() != s.back()) sec.pb(s.back());
		tmp.pb(s.back());
		s.ppb();
		
		int l = sz(tmp);
		if(flag && l > 1 && tmp[l-1] == tmp[l-2] && tmp.back() > sec[sz(sec)-2]){
			tmp.ppb();
			tmp.ppb();
			if(!sz(tmp) || tmp.back() != sec.back()){
				sec.ppb();
			}
			flag = 0;
		}
		else{
			flag = 1;
		}
		
		string z;
		if(sz(tmp) <= 10){
			z = tmp;
			reverse(all(z));
		}
		else{
			l = sz(tmp);
			rep(i,1,6){
				z.pb(tmp[l-i]);
			}
			z.pb('.');
			z.pb('.');
			z.pb('.');
			z.pb(tmp[1]);
			z.pb(tmp[0]);
		}
		ans.pb({sz(tmp),z});
	}
	
	
	reverse(all(ans));
	for(auto x:ans){
		cout << x << "\n";
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