#include "bits/stdc++.h"
using namespace std;
#define int long long
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

pii operator+ (const pii& a, const pii& b){
	return {a.fr + b.fr, a.sc + b.sc};
}

int man(pii a, pii b){
	return abs(a.fr - b.fr) + abs(a.sc - b.sc);
}

pii d[N][2];

// 0 - top, 1 - right
int dis[N][18][2][2];

void solve(){
	int n;
	cin >> n;
	rep(i,1,n){
		rep(j,0,2){
			cin >> d[i][j];
		}
	}
	
	rep(i,1,n-1){
		// d[i] to d[i+1]
		dis[i][0][0][0] = man(d[i][0] + pii{1,0}, d[i+1][0]) + 1;
		dis[i][0][0][1] = man(d[i][0] + pii{1,0}, d[i+1][1]) + 1;
		dis[i][0][1][0] = man(d[i][1] + pii{0,1}, d[i+1][0]) + 1;
		dis[i][0][1][1] = man(d[i][1] + pii{0,1}, d[i+1][1]) + 1;
	}
	
	rep(k,1,18){
		// exit(x) to exit(x + (1 << k))
		// dis[i][k]
		rep(i,1,n-(1<<k)){
			rep(x,0,2){
				rep(y,0,2){
					// i,k,x,y
					int ans = INF;
					rep(z,0,2){
						amin(ans, dis[i][k-1][x][z] + dis[i+(1<<(k-1))][k-1][z][y]);
					}
					dis[i][k][x][y] = ans;
				}
			}
		}
	}
	
	int m;
	cin >> m;
	while(m--){
		pii a,b;
		cin >> a >> b;
		int la = max(a.fr,a.sc), lb = max(b.fr,b.sc);
		if(la == lb){
			cout << man(a,b) << "\n";
			continue;
		}
		if(la > lb){
			swap(a,b);
			swap(la,lb);
		}
		int D[2][2] = {0};
		D[1][0] = D[0][1] = INF;
		int tmp[2][2];
		for(int k = 17; k >= 0; k--){
			if(la + (1 << k) < lb){
				rep(x,0,2){
					rep(y,0,2){
						int ans = INF;
						rep(z,0,2){
							amin(ans,D[x][z] + dis[la][k][z][y]);
						}
						tmp[x][y] = ans;
					}
				}
				la += (1 << k);
				rep(x,0,2){
					rep(y,0,2){
						D[x][y] = tmp[x][y];
					}
				}
			}
		}
		la = max(a.fr,a.sc);
		// cout << la << " " << lb << "\n";
		int ans = INF;
		rep(x,0,2){
			rep(y,0,2){
				// cout << D[x][y] << " ";
				amin(ans, man(a,d[la][x]) + D[x][y] + man(d[lb-1][y] + pii{!y,y},b) + 1);
			}
			// cout << "\n";
		}
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