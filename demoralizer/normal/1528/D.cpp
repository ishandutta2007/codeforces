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

const int N=605;

int wt[N][N]; // wt[x][y] go from city x to city y in this time

void solve(){
	int n,m;
	cin >> n >> m;
	rep(i,0,n){
		rep(j,0,n){
			wt[i][j] = INF;
		}
		// wt[i][i] = 0;
	}
	rep(_,0,m){
		int a,b,c;
		cin >> a >> b >> c;
		rep(i,0,n){
			amin(wt[a][(b+i)%n],c+i);
		}
	}
	
	// rep(i,0,n){
	// 	rep(j,0,n){
	// 		cout << wt[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
	
	rep(root,0,n){
		vector<int> dis(n,INF);
		vector<int> vis(n,0);
		dis[root] = 0;
		int cnt_vis = 0;
		while(cnt_vis < n){
			int best = 0;
			while(vis[best]) best++;
			rep(i,best+1,n){
				if(vis[i]) continue;
				if(dis[i] < dis[best]){
					best = i;
				}
			}
			// visit best
			// cout << " DEBUG : " << best << "\n";
			// for(int x:dis){
			// 	cout << x << " ";
			// }
			// cout << "\n";
			vis[best] = 1;
			cnt_vis++;
			int mod = dis[best] % n;
			rep(adj,0,n){
				amin(dis[adj],dis[best] + wt[best][(adj-mod+n)%n]);
			}
		}
		
		for(int x:dis){
			cout << x << " ";
		}
		cout << "\n";
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