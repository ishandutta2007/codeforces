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

const int N=85;

vector<pii> v[N];
int dp[N][N][N];

int g(int a,int b,int d);

int f(int l,int v,int r,int d){
	return min(g(l,v,d),g(r,v,d));
}

int g(int a,int b,int d){
	if(d == 1)return 0;
	if(a == b){
		return M;
	}
	int &ans = dp[a][b][d];
	if(ans != -1)return ans;
	ans = M;
	if(a<b){
		int l = a, z = b;
		for(pii x:v[z]){
			if(l<=x.fr && x.fr<z){
				amin(ans,x.sc + f(l,x.fr,z-1,d-1));
			}
		}
	}
	else{
		int r = a, z = b;
		for(pii x:v[z]){
			if(z<x.fr && x.fr<=r){
				amin(ans,x.sc + f(z+1,x.fr,r,d-1));
			}
		}
	}
	// cout<<a<<" "<<b<<" "<<d<<" -> "<<ans<<"\n";
	return ans;
}

void solve(){
	mem1(dp);
	int n,k,m;
	cin>>n>>k>>m;
	rep(i,0,m){
		int x,y,c;
		cin>>x>>y>>c;
		v[x].pb({y,c});
	}
	
	int ans = M;
	rep(i,1,n+1){
		amin(ans,f(1,i,n,k));
	}
	if(ans == M) ans = -1;
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