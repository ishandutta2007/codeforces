#include "bits/stdc++.h"
using namespace std;
// #define int               long long
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

const int N=6010;

int l[N];
int r[N];

vector<int> v[N];
int dp[N+2][N+2];

void solve(){
	int n;
	cin>>n;
	
	rep(i,0,N) v[i].clear();
	
	set<int> coor;
	map<int, int> cocom;
	
	rep(i,0,n){
		cin>>l[i]>>r[i];
		coor.insert(l[i]);
		coor.insert(r[i]);
	}
	int cnt = 1;
	for(int x:coor){
		cocom[x] = cnt++;
	}
	rep(i,0,n){
		v[cocom[r[i]]].pb(cocom[l[i]]);
	}
	
	rep(i,0,N){
		sort(all(v[i]),greater<int>());
	}
	

	rep(w,0,cnt+5){
		rep(i,0,cnt+5-w){
			int j = i + w;
			dp[i][j] = max(dp[i][j-1],dp[i+1][j]);
			for(int x:v[j]){
				if(x > i){
					amax(dp[i][j], dp[i][x-1] + dp[x][j]);
				}
				
				if(x == i){
					dp[i][j]++;
				}
			}
		}
	}
	
	cout<<dp[0][cnt+5-1]<<"\n";
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