#include <bits/stdc++.h>
using namespace std;
// #define int               long long
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

const int N=4e5+5;

long long dp[1<<20],c[20][20];
int a[N];

void solve(){
	int n;
	cin>>n;
	rep(i,0,n){
		cin>>a[i];
		a[i]--;
	}
	rep(i,0,20){
		rep(j,0,20){
			if(i==j)continue;
			int x=0;
			rep(k,0,n){
				if(a[k]==j)x++;
				if(a[k]==i)c[i][j]+=x;
			}
		}
	}
	
	rep(mask,1,1<<20){
		dp[mask]=INF;
		rep(j,0,20){
			long long x=0;
			if(mask>>j&1){
				rep(k,0,20){
					if(j==k)continue;
					if(mask>>k&1){
						x+=c[j][k];
					}
				}
				amin(dp[mask],x+dp[mask^(1<<j)]);
			}
		}
	}
	cout<<dp[(1<<20)-1];
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