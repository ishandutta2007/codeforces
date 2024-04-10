#include <bits/stdc++.h>
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
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

vector<int> v[N];
int vis[N][2];
int col[N];
int ans;

vector<int> stk;
void dfs(int z,int t){
	vis[z][t]=1;
	col[z]=1;
	stk.pb(z);
	if(sz(v[z])==0 && t==1){
		cout<<"Win\n";
		for(int x:stk){
			cout<<x<<" ";
		}
		exit(0);
	}
	for(int x:v[z]){
		if(col[x]==1){
			ans=1;
		}
		if(vis[x][!t]){
			continue;
		}
		dfs(x,!t);
	}
	stk.ppb();
	col[z]=2;
}

void solve(){
	int n,m;
	cin>>n>>m;
	rep(i,1,1+n){
		int c;
		cin>>c;
		rep(j,0,c){
			int y;
			cin>>y;
			v[i].pb(y);
		}
	}
	int s;
	cin>>s;
	dfs(s,0);
	if(ans){
		cout<<"Draw";
	}
	else{
		cout<<"Lose";
	}
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SEIVE
		seive();
	#endif
	#ifdef NCR
		init();
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}