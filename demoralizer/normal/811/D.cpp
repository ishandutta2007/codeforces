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

const int N=105;

int n,m;

string s="DLUR" , inp[N];

int dx[]={1,0,-1,0};
int dy[]={0,-1,0,1};

pii query(int q){
	pii ans;
	cout<<s[q]<<endl;
	cin>>ans;
	return ans;
}

bool vis[N][N];
vector<int> moves;

int dfs(int x,int y){
	if(x<0 || y<0 || x>=n || y>=m || inp[x][y] == '*' || vis[x][y]) return 0;
	vis[x][y] = 1;
	if(inp[x][y] == 'F') return 1;
	rep(i,0,4){
		moves.pb(i);
		if(dfs(x+dx[i],y+dy[i])){
			return 1;
		}
		moves.ppb();
	}
	return 0;
}

void solve(){
	cin>>n>>m;
	rep(i,0,n){
		cin>>inp[i];
	}
	dfs(0,0);
	pii pos = {1,1};
	for(int m:moves){
		pii tmp = query(m);
		if(tmp == pos){
			swap(s[m],s[(m+2)%4]);
			// cout<<s<<endl;
			tmp = query(m);
		}
		pos = tmp;
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