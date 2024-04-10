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

const int N=55;

int n,m;
string s[N];

bool check(int x,int y){
	if(x<0 || x>=n || y<0 || y>=m || s[x][y] == '#')return 0;
	return 1;
}
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

int vis[N][N];

int dfs(int x,int y){
	if(vis[x][y])return 0;
	vis[x][y] = 1;
	int ans = (s[x][y]=='G');
	rep(i,0,4){
		if(check(x+dx[i],y+dy[i]))
			ans += dfs(x+dx[i],y+dy[i]);
	}
	return ans;
}

void solve(){
	cin>>n>>m;
	rep(i,0,n){
		cin>>s[i];
	}
	mem0(vis);
	int cnt = 0;
	
	rep(i,0,n){
		rep(j,0,m){
			if(s[i][j] == 'B')
			rep(k,0,4){
				int x = i + dx[k] , y = j + dy[k];
				if(!check(x,y))continue;
				if(s[x][y] == '.') s[x][y] = '#';
				if(s[x][y] == 'G'){
					cout<<"No\n";
					return;
				}
			}
			if(s[i][j] == 'G'){
				cnt++;
			}
		}
	}
	
	
	if(cnt == 0 || (check(n-1,m-1) && cnt == dfs(n-1,m-1))){
		cout<<"Yes\n";
	}
	else{
		cout<<"No\n";
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