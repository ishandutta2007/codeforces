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

const int N=505;

int n,k;
int s=0,sa=0,sb=0;
int a[N],b[N];

int dp[N][N];
// dp[i][j] is true if I processed till i elements and I can subtract j from sa mod k

void solve(){
	cin>>n>>k;
	rep(i,1,n+1){
		cin>>a[i]>>b[i];
		sa+=a[i];
		sb+=b[i];
	}
	
	s= sa/k + sb/k;
	if(sa%k + sb%k < k){
		cout<<s;
		return;
	}
	dp[0][0]=1;
		// cout<<a[1]<<" "<<b[1]<<"\n\n\n";
	
	rep(i,1,n+1){
		rep(j,0,k){
			dp[i][j]=dp[i-1][j];
		}
		rep(z,1,k){
			int y=k-z;
			// cout<<z<<" "<<y<<"\n";
			// cout<<a[i]<<" "<<b[i]<<"\n";
			// cout<<"\n";
			if(a[i]>=z && b[i]>=y){
				rep(j,0,k){
					if(dp[i-1][j]){
						dp[i][(j+z)%k]=1;
					}
				}
			}
		}
	}
	
	bool f=0;
	rep(j,0,k){
		if(dp[n][j]){
			if((sa-j)%k + (sb+j)%k < k)f=1;
		}
	}
	
	if(f){
		cout<<s+1;
	}
	else{
		cout<<s;
	}
	
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
	// cin>>t;
	while(t--) solve();
	return 0;
}