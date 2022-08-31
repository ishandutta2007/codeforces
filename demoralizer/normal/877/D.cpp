#include <bits/stdc++.h>
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

const int N=1005;

int n,m,k;
string s[N];

bool get(int x,int y){
	if(x<0 || y<0 || x>=n || y>=m || s[x][y] == '#'){
		return 0;
	}
	return 1;
}

bool vis[N][N];
int tim[N][N];
int rem[N][N][4];

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

void solve(){
	cin>>n>>m>>k;
	rep(i,0,n){
		 cin>>s[i];
	}
	int x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	x1--;
	x2--;
	y1--;
	y2--;
	rep(i,0,n){
		rep(j,0,m){
			tim[i][j]=INF;
		}
	}
	
	set<pair<int, pii>> s;
	tim[x1][y1]=0;
	s.insert({0,{x1,y1}});
	while(sz(s)){
		auto cur = *s.begin();
		s.erase(s.begin());
		int t=cur.fr,x=cur.sc.fr,y=cur.sc.sc;
		if(vis[x][y]){
			continue;
		}
		vis[x][y]=1;
		rep(i,0,4){
			int a=x+dx[i],b=y+dy[i];
			// cout<<x<<" "<<y<<" --- "<<a<<" "<<b<<"\n";
			if(get(a,b)){
				int nt = t + !rem[x][y][i];
				if(tim[a][b] < nt){
					continue;
				}
				if(tim[a][b] == nt){
					amax(rem[a][b][i],(rem[x][y][i]-1+k)%k);
				}
				else{
					rep(z,0,4) rem[a][b][z] = 0;
					rem[a][b][i] = rem[x][y][i]-1;
					if(rem[a][b][i] < 0) rem[a][b][i] += k;
					tim[a][b] = nt;
					s.insert({nt,{a,b}});
				}
			}
		}
	}
	int ans = tim[x2][y2];
	if(ans == INF) ans=-1;
	cout<<ans;
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