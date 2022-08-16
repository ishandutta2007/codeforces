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

void sanitize(vector<int> &v){
	sort(all(v), greater<int>());
	while(sz(v) && v.back() == 0){
		v.ppb();
	}
}

void solve(){
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	string s;
	cin >> s;
	
	map<char, int> cnt;
	for(char c:s){ 
		cnt[c]++;
	}
	
	if(cnt['A'] != a + c + d || cnt['B'] != b + c + d){
		cout << "NO\n";
		return;
	}
	
	
	vector<int> af,bf,nu;
	
	s.pb(s.back());
	string tmp = "";
	for(char c:s){
		if(tmp.empty() || tmp.back() != c){
			tmp += c;
		}
		else{
			if(sz(tmp) % 2){
				nu.pb(sz(tmp) / 2);
			}
			else{
				if(tmp[0] == 'A'){
					af.pb(sz(tmp) / 2);
				}
				else{
					bf.pb(sz(tmp) / 2);
				}
			}
			// split
			// cout << tmp << "\n";
			tmp = "";
			tmp += c;
		}
	}
	
	sanitize(af);
	sanitize(bf);
	sanitize(nu);
	
	sort(all(bf));
	
	while(sz(af) && c){
		int x = af.back();
		af.ppb();
		int tmp = min(x,c);
		x -= tmp;
		c -= tmp;
		if(x){
			d -= x - 1;
		}
	}
	while(sz(nu) && c){
		int x = nu.back();
		nu.ppb();
		int tmp = min(x,c);
		x -= tmp;
		c -= tmp;
		if(x){
			d -= x;
		}
	}
	while(sz(bf) && c){
		int x = bf.back() - 1;
		bf.ppb();
		int tmp = min(x,c);
		x -= tmp;
		c -= tmp;
		if(x){
			d -= x;
		}
	}
		
	if(c){
		cout << "NO\n";
		return;
	}
	
	for(int x:af){
		d -= x - 1;
	}
	for(int x:nu){
		d -= x;
	}
	for(int x:bf){
		d -= x;
	}
	
	if(d > 0){
		cout << "NO\n";
		return;
	}
	
	cout << "YES\n";
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