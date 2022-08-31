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

int query(int x,int y,int z){
	cout << "? " << x << " " << y << " " << z << endl;
	int a;
	cin >> a;
	return a;
}

void answer(int x, int y){
	cout << "! " << x << " " << y << endl;
}

void solve(){
	int n;
	cin >> n;
	vector<int> candidates = {1,2};
	int curmax = 0;
	int val = 0;
	rep(i,3,n+1){
		int x = query(candidates[0],candidates[1],i);
		if(x >= curmax){
			curmax = x;
			val = i;
		}
	}
	candidates.pb(val);
	int use_later = curmax;
	
	curmax = 0;
	val = 0;
	rep(i,3,n+1){
		if(i == candidates.back()) continue;
		int x = query(candidates[0],candidates[2],i);
		if(x >= curmax){
			curmax = x;
			val = i;
		}
	}
	candidates.pb(val);
	
	vector<pii> v;
	rep(i,0,3){
		// skip candidates[i]
		vector<int> tmp;
		rep(j,0,4){
			if(j == i) continue;
			tmp.pb(candidates[j]);
		}
		int x = query(tmp[0], tmp[1], tmp[2]);
		v.pb({x,candidates[i]});
	}
	v.pb({use_later, candidates.back()});
	
	sort(all(v));
	answer(v[0].sc, v[1].sc);
	
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