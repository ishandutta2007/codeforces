#include <bits/stdc++.h>
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

int sc[26],tc[26];

int req[26];

void solve(){
	string s,t;
	cin>>s>>t;
	int q=0;
	for(char c:s){
		if(c=='?')q++;
		else sc[c-'a']++;
	}
	for(char c:t){
		tc[c-'a']++;
	}
	int L=0,U=1e6+5;
	while(U-L>1){
		int m=(L+U)/2;
		int r=0;
		rep(i,0,26){
			r += max(0ll,m*tc[i] - sc[i]);
		}
		if(r <= q){
			L=m;
		}
		else{
			U=m;
		}
	}
	vector<char> p;
	rep(i,0,sz(s))p.pb('a');
	rep(i,0,26){
		req[i] = max(L*tc[i]-sc[i],0ll);
		rep(j,0,req[i]){
			p.pb('a'+i);
		}
	}
	rep(i,0,sz(s)){
		if(s[i]=='?'){
			cout<<p.back();
			p.ppb();
		}
		else{
			cout<<s[i];
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
	//cin>>t;
	while(t--) solve();
	return 0;
}