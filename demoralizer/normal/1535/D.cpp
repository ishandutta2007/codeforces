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



void solve(){
	int k;
	cin >> k;
	vector<int> ans(1 << (k + 1));
	rep(i,(1<<k),(1<<(k+1))){
		ans[i] = 1;
	}
	
	
	string s;
	cin >> s;
	
	s.pb('&');
	reverse(all(s));
	
	for(int i = (1 << k) - 1; i > 0; i--){
		if(s[i] == '0'){
			ans[i] = ans[2 * i + 1];
		}
		else if(s[i] == '1'){
			ans[i] = ans[2 * i];
		}
		else{
			ans[i] = ans[2 * i] + ans[2 * i + 1];
		}
	}
	
	int q;
	cin >> q;
	
	while(q--){
		int p;
		char c;
		cin >> p >> c;
		p = (1 << (k)) - p;
		
		s[p] = c;
		
		while(p){
			if(s[p] == '0'){
				ans[p] = ans[2 * p + 1];
			}
			else if(s[p] == '1'){
				ans[p] = ans[2 * p];
			}
			else{
				ans[p] = ans[2 * p] + ans[2 * p + 1];
			}
			p /= 2;
		}
		
		cout << ans[1] << "\n";
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