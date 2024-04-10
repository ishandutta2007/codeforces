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

const int N=1e5+5;

vector<int> v[N];
int vis[N];
int col[N];

int cnt[2];

void dfs(int z,int p,int c){
	vis[z]=1;
	col[z] = c;
	cnt[c]++;
	for(int x:v[z]){
		if(vis[x]){
			if(col[x] == c){
				cout<<"0 1";
				exit(0);
			}
			continue;
		}
		dfs(x,z,!c);
	}
}

void solve(){
	int n,m;
	cin>>n>>m;
	rep(i,0,m){
		int x,y;
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}
	int ans = 0;
	rep(i,1,n+1){
		cnt[0] = cnt[1] = 0;
		if(!vis[i]){
			dfs(i,i,0);
			ans += cnt[0] * (cnt[0] - 1) / 2 + cnt[1] * (cnt[1] - 1) / 2;
		}
	}
	if(m==0){
		cout<<"3 "<<n*(n-1)*(n-2)/6;
		return;
	}
	int mx=0;
	rep(i,1,n+1){
		amax(mx,sz(v[i]));
	}
	if(mx == 1){
		cout<<"2 "<<m*(n-2);
		return;
	}
	cout<<"1 "<<ans;
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