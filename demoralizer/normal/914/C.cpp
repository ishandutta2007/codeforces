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

const int N=1005;

string n;
int dp[N][N][2],l;

int calc(int one,int id = 0,int small = 0){
	if(id == l){
		return (one == 0);
	}
	int &ans = dp[id][one][small];
	if(ans != -1) return ans;
	ans = 0;
	if(one){
		if(small || n[id] == '1') ans = (ans + calc(one-1,id+1,small)) % M;
	}
	if(n[id] == '0') ans = (ans + calc(one,id+1,small)) % M;
	else ans = (ans + calc(one,id+1,1)) % M;
	return ans;
}

void solve(){
	mem1(dp);
	int k;
	cin>>n>>k;
	l = sz(n);
	if(k == 0){
		cout << 1;
		return;
	}
	if(k == 1){
		cout << l - 1;
		return;
	}
	int ans = 0;
	int dp[1005];
	dp[1] = 0;
	rep(i,2,1001){
		dp[i] = dp[ppc(i)] + 1;
		if(dp[i] + 1 == k){
			ans = (ans + calc(i)) % M;
		}
	}
	cout << ans;
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