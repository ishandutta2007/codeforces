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

int n;
int a[105];
int b[105];
int dp[105][10005];

int calc(int id,int ra,int rb){
	if(id == n){
		return 0;
	}
	int &ans = dp[id][ra];
	if(ans != -1){
		return ans;
	}
	
	ans = ra * a[id] + rb * b[id] + calc(id + 1, ra + a[id], rb + b[id]);
	if(id > 0)
	amin(ans, ra * b[id] + rb * a[id] + calc(id + 1, ra + b[id], rb + a[id]));
	
	// cout << id << " " << ra << " " << rb << " " << ans << "\n";
	
	return ans;
}

void solve(){
	mem1(dp);
	cin >> n;
	int ans = 0;
	rep(i,0,n){
		cin >> a[i];
		ans += a[i] * a[i];
	}
	rep(i,0,n){
		cin >> b[i];
		ans += b[i] * b[i];
	}
	
	ans *= n - 1;
	
	ans += calc(0,0,0) * 2;
	cout << ans << "\n";
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