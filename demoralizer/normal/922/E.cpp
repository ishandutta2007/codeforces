#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define sz(x)             (int)((x).size())
#define int               long long
#define M                 10000000000000007LL
#define MM                998244353
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T>pair<T,T> operator+=(pair<T,T> &a,pair<T,T> b){a.fr+=b.fr;a.sc+=b.sc;return a;}
template<typename T>pair<T,T> operator-=(pair<T,T> &a,pair<T,T> b){a.fr-=b.fr;a.sc-=b.sc;return a;}
template<typename T>pair<T,T> operator+(pair<T,T> a,pair<T,T> b){a.fr+=b.fr;a.sc+=b.sc;return a;}
template<typename T>pair<T,T> operator-(pair<T,T> a,pair<T,T> b){a.fr-=b.fr;a.sc-=b.sc;return a;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

const int N=0;

int dp[1005][10005];
int c[1005];
int cost[1005];

void solve(){
	rep(i,0,1005){
		rep(j,0,10005){
			dp[i][j]=-M;
		}
	}
	int n,b,w,x;
	cin>>n>>w>>b>>x;
	dp[0][0]=w-x;
	rep(i,1,n+1){
		cin>>c[i];
	}
	rep(i,1,n+1){
		cin>>cost[i];
	}
	rep(i,1,n+1){
		deque<int> d;
		rep(j,0,10001){
			int k=(min(x+dp[i-1][j],w+b*j)+j*cost[i]);
			while(!d.empty() && k>d.back()){
				d.ppb();
			}
			d.pb(k);
			dp[i][j]=d.front()-j*cost[i];
			amin(dp[i][j],w+b*j);
			if(dp[i][j]<0){
				dp[i][j]=-M;
			}
			if(j>=c[i]){
				int k=(j-c[i]);
				int l=(min(x+dp[i-1][k],w+b*k)+k*cost[i]);
				if(d.front()==l)d.ppf();
			}
		}
	}
	for(int j=10000;j>=0;j--){
		if(dp[n][j]>=0){
			cout<<j;
			return;
		}
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
	//cin>>t;
	while(t--) solve();
	return 0;
}