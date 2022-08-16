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

const int N=505;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int vis[N][N];
bool check(int x,int y,int k){
	if(x < 0 || y < 0 || x > k || y > k || vis[x][y]){
		return false;
	}
	return true;
}

map<array<int,4>,int> e;
int get(int x,int y,int X,int Y){
	if(x > X) swap(x,X);
	if(y > Y) swap(y,Y);
	if(e.count({x,y,X,Y})){
		return e[{x,y,X,Y}];
	}
	return 0;
}

void solve(){
	int n,k;
	cin >> n >> k;
	e.clear();
	
	rep(i,0,k+1){
		rep(j,0,k+1){
			vis[i][j] = 0;
		}
	}
	
	rep(i,0,n){
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		
		rep(zzz,0,2){
			// logic
			int x,y,X,Y;
			x = X = min(a,c);
			y = Y = min(b,d);
			if(a == c){
				x--;
			}
			else{
				y--;
			}
			e[{x,y,X,Y}]++;
			// rotation
			a = k + 1 - a;
			b = k + 1 - b;
			c = k + 1 - c;
			d = k + 1 - d;
		}
		
	}
	
	set<pair<int, pii>> s;
	s.insert({0,{k/2,k/2}});
	
	while(sz(s)){
		auto p = *s.begin();
		s.erase(s.begin());
		
		int w = p.fr;
		int x = p.sc.fr;
		int y = p.sc.sc;
		
		if(vis[x][y]) continue;
		vis[x][y] = 1;
		
		if(x == 0 || y == 0 || x == k || y == k){
			cout << n - w << "\n";
			return;
		}
		
		rep(i,0,4){
			int X = x + dx[i];
			int Y = y + dy[i];
			if(!check(X,Y,k)){
				continue;
			}
			
			int wt = get(x,y,X,Y);
			s.insert({w+wt,{X,Y}});
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
	cin>>t;
	while(t--) solve();
	return 0;
}