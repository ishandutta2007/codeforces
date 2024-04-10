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

int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};

void solve(){
	int n,m;
	cin >> n >> m;
	vector<vector<int>> a(n,vector<int>(m));
	vector<vector<int>> locked(n,vector<int>(m));
	
	rep(i,0,n){
		rep(j,0,m){
			cin >> a[i][j];
		}
	}
	
	auto check = [&](int x, int y){
		if(a[x][y] == 1) return false;
		rep(i,0,4){
			int X = x + dx[i];
			int Y = y + dy[i];
			if(X >= 0 && X < n && Y >= 0 && Y < m && a[X][Y] < a[x][y]){
				return false;
			}
		}
		return true;
	};
	
	
	int tot = 0;
	int x,y;
	rep(i,0,n){
		rep(j,0,m){
			tot += (locked[i][j] = check(i,j));
			if(locked[i][j]){
				x = i;
				y = j;
			}
			// cout << locked[i][j];
		}
		// cout << "\n";
	}
	
	if(!tot){
		cout << 0;
		return;
	}
	
	vector<pii> z;
	auto put = [&](vector<pii> &z, int x, int y){
		z.pb({x,y});
		rep(i,0,4){
			int X = x + dx[i];
			int Y = y + dy[i];
			if(X >= 0 && X < n && Y >= 0 && Y < m){
				z.pb({X,Y});
			}
		}
	};
	put(z,x,y);
	
	set<array<pii,2>> ans;
	rep(i,0,n){
		rep(j,0,m){
			for(auto p:z){
				int x = p.fr;
				int y = p.sc;
				if(x == i && y == j){
					continue;
				}
				swap(a[i][j],a[x][y]);
				vector<pii> pts;
				put(pts,i,j);
				put(pts,x,y);
				sort(all(pts)); uniq(pts);
				
				int tmp = 0;
				for(auto pt: pts){
					tmp += locked[pt.fr][pt.sc];
					tmp -= check(pt.fr,pt.sc);
				}
				if(tmp == tot){
					array<pii,2> ins = {pii{i,j},p};
					sort(all(ins));
					ans.insert(ins);
				}
				
				swap(a[i][j],a[x][y]);
			}
		}
	}
	
	if(sz(ans)){
		cout << 1 << " " << sz(ans);
		return;
	}
	
	cout << 2;
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