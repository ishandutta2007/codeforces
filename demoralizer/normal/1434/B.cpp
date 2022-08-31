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

const int N=2e5+5;

string s[N];
int p[N];
int m[N]; // pos
int mch[N]; // match

void solve(){
	set<int,greater<int> > ids;
	int n;
	cin >> n;
	rep(i,0,2*n){
		cin >> s[i];
		if(s[i] == "-"){
			cin >> p[i];
			m[p[i]] = i;
		}
		else{
			ids.insert(i);
			// cout << i << "  ";
		}
	}
	
	
	// for(int x:ids) cout << x << " ";
	
	rep(i,1,n+1){
		// m[i]
		if(ids.upper_bound(m[i]) == ids.end()){
			cout << "NO\n";
			return;
		}
		int tmp = *ids.upper_bound(m[i]);
		mch[i] = tmp;
		ids.erase(tmp);
		p[tmp] = i;
	}
	
	// rep(i,0,2*n){
	// 	cout << s[i] << " " << p[i] << "\n";
	// }
	
	set<int> vals;
	
	rep(i,0,2*n){
		if(s[i] == "+"){
			vals.insert(p[i]);
		}
		else{
			int tmp = *vals.begin();
			vals.erase(tmp);
			if(p[i] != tmp){
				cout << "NO\n";
				return;
			}
		}
	}
	
	cout << "YES\n";
	rep(i,0,2*n){
		if(s[i] == "+"){
			cout << p[i] << " ";
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