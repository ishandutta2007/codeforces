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
const int32_t MM=998244353;

const int N=2e5+5;
const int32_t M=5e5+5;

int best[M][20];

void solve(){
	int n,m;
	cin >> n >> m;
	rep(i,0,n){
		int l,r;
		cin >> l >> r;
		amax(best[l][0],r);
	}
	rep(i,1,M){
		amax(best[i][0],best[i-1][0]);
	}
	
	rep(j,1,20){
		rep(i,0,M){
			amax(best[i][j],best[best[i][j-1]][j-1]);
		}
	}
	
	rep(i,0,m){
		int x,y;
		cin >> x >> y;
		if(best[x][19] < y){
			cout << -1 << "\n";
			continue;
		}
		int ans = 0;
		for(int j = 19; j >= 0; j--){
			if(best[x][j] < y){
				ans += (1 << j);
				x = best[x][j];
			}
		}
		if(x < y) ans++;
		cout << ans << "\n";
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