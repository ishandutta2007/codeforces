#include "bits/stdc++.h"
using namespace std;
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
string s;
int dp[76][1<<20];

int calc(int id,int mask){
	if(id == n){
		return 0;
	}
	int &ans = dp[id][mask];
	if(ans != -1){
		return ans;
	}
	if(s[id] == '0') ans = calc(id+1,mask);
	else{
		int val = 1;
		int add = 1;
		int nm = mask|1;
		ans = calc(id+1,nm);
		if(ppc(nm + 1) == 1) ans++;
		if(ans >= M) ans -= M;
		while(id + add < n){
			val = 2 * val + (s[id+add] == '1');
			if(val > 20) break;
			add++;
			nm = mask|(1<<(val - 1));
			ans += calc(id+add,nm);
			if(ppc(nm + 1) == 1) ans++;
			if(ans >= M) ans -= M;
		}
	}
	return ans;
}

void solve(){
	mem1(dp);
	cin >> n >> s;
	int ans = 0;
	rep(i,0,n){
		// cout << calc(i,0) << "\n";
		ans += calc(i,0);
		if(ans >= M) ans -= M;
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