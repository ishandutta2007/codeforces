#include "bits/stdc++.h"
using namespace std;
// #define int               long long
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

// #ifndef ONLINE_JUDGE
// #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
// template <typename Arg1>
// void __f(const char* name, Arg1&& arg1) {
// 	cout << name << " : " << arg1 << std::endl;
// }
// template <typename Arg1, typename... Args>
// void __f(const char* names, Arg1&& arg1, Args&&... args) {
// 	const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
// }
// #else
// #define trace(...)
// #endif

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

const long long INF=1e18;	
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=105;

int dp[N][N][3][3];
// dp[L][R][blockedup][blockeddown]

int a[N][2];

int chksqr(int x,int y){
	return !(a[x][!y] || a[x-1][!y] || a[x+1][!y] || a[x][y]);
}

int calc(int l,int r,int bu,int bd){
	
	if(l == r){
		return ( (chksqr(l,0) && bu != 1 && bd != 1) || (chksqr(l,1) && bu!=2 && bd != 2));
	}
	if(l > r) return 0;
	
	int &ans = dp[l][r][bu][bd];
	if(ans != -1){
		return ans;
	}
	
	ans = 0;
	
	set<int> mex;
	rep(i,0,5*N){
		mex.insert(i);
	}
	
	
	if(bu != 1 && chksqr(l,0)) mex.erase(calc(l+1,r,2,bd));
	if(bu != 2 && chksqr(l,1)) mex.erase(calc(l+1,r,1,bd));
	
	if(bd != 1 && chksqr(r,0)) mex.erase(calc(l,r-1,bu,2));
	if(bd != 2 && chksqr(r,1)) mex.erase(calc(l,r-1,bu,1));
	
	rep(i,l+1,r){
		if(chksqr(i,0)){
			mex.erase(calc(l,i-1,bu,2)^calc(i+1,r,2,bd));
		}
		if(chksqr(i,1)){
			mex.erase(calc(l,i-1,bu,1)^calc(i+1,r,1,bd));
		}
	}
	
	ans = *mex.begin();
	
	// trace(l,r,bu,bd,ans);
	
	return ans;
	
}

void solve(){
	mem1(dp);
	int r,n;
	cin>>r>>n;
	
	rep(i,0,n){
		int x,y;
		cin>>x>>y;
		a[x][y-1] = 1;
	}
	
	if(calc(1,r,0,0)){
		cout<<"WIN";
	}
	else{
		cout<<"LOSE";
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