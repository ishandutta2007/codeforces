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

const int N=5e5+5;

vector<int> w[N];
int cc[2*N];

void solve(){
	int n,c;
	cin >> n >> c;
	
	vector<pii> r;
	
	rep(i,0,n){
		int l;
		cin >> l;
		w[i].resize(l);
		for(int &x:w[i]){
			cin >> x;
		}
		if(i){
			int k = min(sz(w[i]),sz(w[i-1]));
			int j = 0;
			while(j < k && w[i][j] == w[i-1][j]){
				j++;
			}
			if(j < k){
				// w[i][j] > w[i-1][j]
				r.pb({w[i][j],w[i-1][j]});
			}
			else{
				if(sz(w[i]) < sz(w[i-1])){
					cout << -1;
					return;
				}
			}
		}
	}
	
	pii rng = {0,c-1};
	for(pii x:r){
		if(x.fr < x.sc){
			amax(rng.fr,x.fr);
			amin(rng.sc,x.sc-1);
		}
		else{
			amax(cc[x.sc],x.fr);
		}
	}
	
	rep(i,1,c+1){
		amax(cc[i],cc[i-1]);
	}
	
	rep(i,rng.fr,rng.sc+1){
		if(cc[i] > i) continue;
		cout << (c - i) % c;
		return;
	}
	cout << -1;
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