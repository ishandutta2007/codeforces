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

const int N=2005;

int n;
int a[N];
int b[N];

map<int, int> dp[N][9];

int p5[9];

int calc(int id,int floor,int mask){
	if(id == n && mask == 0){
		return 0;
	}
	if(dp[id][floor].count(mask)){
		return dp[id][floor][mask];
	}
	int ans = INF;
	
	int cnt = 0;
	int tmp = mask;
	rep(i,0,9){
		int d = tmp%5;
		cnt += d;
		int newmask = mask - d * p5[i];
		if(d){
			amin(ans,abs(floor - i) + calc(id,i,newmask));
		}
		tmp /= 5;
	}
	
	if(cnt != 4 && id < n){
		int newmask = mask + p5[b[id]];
		amin(ans,abs(floor - a[id]) + calc(id+1,a[id],newmask));
	}
	
	return dp[id][floor][mask] = ans;
}

void solve(){
	
	p5[0] = 1;
	rep(i,1,9){
		p5[i] = 5 * p5[i - 1];
	}
	
	cin >> n;
	int ans = 2 * n;
	rep(i,0,n){
		cin >> a[i] >> b[i];
		a[i]--;
		b[i]--;
	}
	
	ans += calc(0,0,0);
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