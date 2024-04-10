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

const int N=0;

int dp[205][6005]; // we have taken i elements and 5^j and got 2^dp[i][j]

int p2[205];
int p5[205];

void solve(){
	mem1(dp);
	int n,k;
	cin>>n>>k;
	rep(i,0,n){
		int x;
		cin>>x;
		while(x%2==0){
			p2[i]++;
			x/=2;
		}
		while(x%5==0){
			p5[i]++;
			x/=5;
		}
	}
	
	dp[0][0]=0;
	
	rep(i,0,n){
		for(int j=k-1;j>=0;j--){
			for(int z=5700;z>=0;z--){
				if(dp[j][z] >= 0) amax(dp[j+1][z+p5[i]],dp[j][z] + p2[i]);
			}
		}
	}
	int ans=0;
	rep(z,0,5701){
		amax(ans,min(z,dp[k][z]));
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