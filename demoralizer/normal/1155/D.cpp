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

const int N=3e5+5;

int a[N],p[N];
int dp[N][3];

void solve(){
	int n,x;
	cin>>n>>x;
	rep(i,1,n+1){
		cin>>a[i];
		p[i]=p[i-1]+a[i];
	}
	if(x>0){
		int m=0,ans=0;
		rep(i,1,n+1){
			amin(m,p[i]);
			amax(ans,p[i]-m);
		}
		cout<<ans*x;
		return;
	}
	int mn=0,mx=0,ans=0;
	rep(i,1,n+1){
		amin(mn,p[i]);
		amax(mx,(1-x)*p[i]-mn);
		dp[i][1]=x*p[i]+mx;
		dp[i][2]=a[i]+max(dp[i-1][1],dp[i-1][2]);
		amax(ans,max(dp[i][1],dp[i][2]));
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