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

const int N=105;

pii operator+ (pii a, pii b){
	return {a.fr+b.fr, a.sc+b.sc};
}

pii dp[N][3];

// 0 -> rook, 1 -> bishop, 2 -> knight

pii moves[N][3][3]; // moves[x][a][b] = number of moves from (x,a) to (x+1,b) |||| {moves, replacements}
int a[11][11];
int x[N];
int y[N];

// knight moves
int dx[] = {-2,-1,1 ,2 ,2 ,1 ,-1,-2 };
int dy[] = {1 ,2 ,2 ,1 ,-1,-2,-2,-1};

int n;
int vis[11][11][3];
bool valid(int x,int y,int z){
	if(x < 0 || y < 0 || x >= n || y >= n || vis[x][y][z]){
		return 0;
	}
	return 1;
}

struct cmp
{
	bool operator() (array<int,4> a, array<int,4> b){
		return tie(a[2],a[3]) > tie(b[2],b[3]);
	}
};

// priority_queue<array<int,4>,vector<array<int,4>>,cmp> q; // id, piece, moves, replacements
queue<array<int,4>> q;
void push(int x,int y,int p,int dis,int rp){
	if(!valid(x,y,p)) return;
	vis[x][y][p] = 1;
	q.push({a[x][y],p,dis,rp});
}

void solve(){
	cin >> n;
	rep(i,0,n){
		rep(j,0,n){
			cin >> a[i][j];
			x[a[i][j]] = i;
			y[a[i][j]] = j;
		}
	}
	
	rep(i,1,n*n){
		rep(k,0,3){
			int cnt = 0;
			while(!q.empty()){
				q.pop();
			}
			mem0(vis);
			vis[x[i]][y[i]][k] = 1;
			q.push({i,k,0,0});
			while(1){
				auto cur = q.front();
				if(cur[0] == i+1){
					// if(i == 1 && k == 2){
					// 	cout << cur[1] << " -> " << pii{cur[2],cur[3]} << "\n";
					// }
					moves[i][k][cur[1]] = {cur[2],cur[3]};
					cnt++;
					if(cnt == 3){
						break;
					}
				}
				int X = x[cur[0]];
				int Y = y[cur[0]];
				q.pop();
				if(cur[1] == 0){
					rep(z,0,n){
						push(X,z,0,cur[2]+1,cur[3]);
						push(z,Y,0,cur[2]+1,cur[3]);
					}
				}
				else if(cur[1] == 1){
					rep(z,0,n){
						push(z,X+Y-z,1,cur[2]+1,cur[3]);
						push(z,z+Y-X,1,cur[2]+1,cur[3]);
					}
				}
				else{
					rep(z,0,8){
						push(X+dx[z],Y+dy[z],2,cur[2]+1,cur[3]);
					}
				}
				
				rep(z,0,3){
					push(X,Y,z,cur[2]+1,cur[3]+1);
				}
			}
		}
	}
	dp[1][0] = dp[1][1] = dp[1][2] = {0,0};
	rep(i,2,n*n+1){
		rep(j,0,3){
			// dp[i][j]
			dp[i][j] = min({moves[i-1][0][j] + dp[i-1][0],
						moves[i-1][1][j] + dp[i-1][1],
						moves[i-1][2][j] + dp[i-1][2]});
		}
	}
	
	pii ans = min({dp[n*n][0],dp[n*n][1],dp[n*n][2]});
	cout << ans;
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