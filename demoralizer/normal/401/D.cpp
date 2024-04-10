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

const int N=0;

int n,m;
vector<int> d;

int dp[1<<18][101];

int cnt[10],K;


int calc(int mask,int rem){
	if(mask==K)return (rem==0);
	int &ans=dp[mask][rem];
	if(ans!=-1)return ans;
	ans=0;
	rep(i,0,sz(d)){
		if((mask>>i)&1)continue;
		if(!mask && !d[i])continue;
		ans+=calc(mask|(1<<i),(10*rem+d[i])%m);
	}
	return ans;
}

int fact(int n){
	if(n==0)return 1;
	return n*fact(n-1);
}

void solve(){
	// mem1(dp);
	cin>>n>>m;
	while(n){
		d.pb(n%10);
		cnt[n%10]++;
		n/=10;
	}
	K=(1<<sz(d))-1;
	dp[K][0]=1;
	for(int mask=K-1;mask>=0;mask--){
		rep(i,0,sz(d)){
			if((mask>>i)&1)continue;
			if(!mask && !d[i])continue;
			rep(rem,0,m){
				dp[mask][rem]+=dp[mask|(1<<i)][(10*rem+d[i])%m];
			}
		}
	}
	int ans=dp[0][0];
	rep(i,0,10){
		ans/=fact(cnt[i]);
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