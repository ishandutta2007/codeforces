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

const int N=3005;

int h[N][N];
int g[N*N];

int u[N][N];

void solve(){
	int n,m,a,b,x,y,z;
	cin>>n>>m>>a>>b>>g[0]>>x>>y>>z;
	rep(i,1,n*m+1){
		g[i]=(g[i-1]*x+y)%z;
	}
	rep(i,0,n){
		rep(j,0,m){
			h[i][j]=g[m*i+j];
		}
	}
	
	deque<int> d;
	rep(i,0,n){
		rep(j,0,b){
			while(!d.empty() && h[i][j] < d.back()){
				d.ppb();
			}
			d.pb(h[i][j]);
		}
		rep(j,0,m-b+1){
			u[i][j]=d.front();
			if(d.front() == h[i][j])d.ppf();
			while(!d.empty() && h[i][j+b] < d.back()){
				d.ppb();
			}
			d.pb(h[i][j+b]);
		}
		d.clear();
	}
	int ans=0;
	rep(j,0,m-b+1){
		rep(i,0,a){
			while(!d.empty() && u[i][j] < d.back()){
				d.ppb();
			}
			d.pb(u[i][j]);
		}
		rep(i,0,n-a+1){
			ans+=d.front();
			if(d.front() == u[i][j])d.ppf();
			while(!d.empty() && u[i+a][j] < d.back()){
				d.ppb();
			}
			d.pb(u[i+a][j]);
		}
		d.clear();
	}
	cout<<ans;
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