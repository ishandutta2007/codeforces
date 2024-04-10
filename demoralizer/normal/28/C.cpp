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

int a[55];
double fact[55],pw[55];

double c(int n,int r){
	return fact[n]/fact[r]/fact[n-r];
}

int n,m;
bool vis[55][55][55];
double dp[55][55][55];

double calc(int id,int rem,int mx){
	if(id == m){
		if(rem == 0)
			return mx;
		else
			return 0;
	}
	
	if(vis[id][rem][mx]){
		return dp[id][rem][mx];
	}
	vis[id][rem][mx] = 1;
	double ans = 0;
	rep(i,0,rem+1){
		ans += c(rem,i) / pw[i] * calc(id+1,rem-i,max(mx,(i+a[id]-1)/a[id]));
	}
	return dp[id][rem][mx] = ans;
}

void solve(){
	cin>>n>>m;
	fact[0] = 1;
	pw[0] = 1;
	rep(i,1,55){
		fact[i] = i * fact[i-1];
		pw[i] = m * pw[i-1];
	}
	rep(i,0,m){
		cin>>a[i];
	}
	cout<<setprecision(10);
	cout<<fixed;
	cout << calc(0,n,0);
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