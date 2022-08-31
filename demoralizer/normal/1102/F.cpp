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
int pc[16][16];
int pclf[16][16];
int a[16][10005];

int dp[16][16][1<<16];

int calc(int F,int L,int mask){
	if(mask+1==(1<<n)){
		return pclf[L][F];
	}
	int &ans=dp[F][L][mask];
	if(ans!=-1)return ans;
	ans=0;
	rep(i,0,n){
		if(mask>>i&1)continue;
		amax(ans,min(pc[L][i],calc(F,i,mask|(1<<i))));
	}
	return ans;
}

void solve(){
	mem1(dp);
	cin>>n>>m;
	rep(i,0,n){
		rep(j,0,m){
			cin>>a[i][j];
		}
	}
	rep(i,0,n){
		rep(j,0,n){
			// if(i==j)continue;
			int ans=abs(a[j][0]-a[i][0]);
			pclf[i][j]=INF;
			rep(k,1,m){
				amin(ans,abs(a[j][k]-a[i][k]));
				amin(pclf[i][j],abs(a[j][k]-a[i][k-1]));
			}
			pc[i][j]=ans;
			// cout<<i<<" "<<j<<" "<<pc[i][j]<<" "<<pclf[i][j]<<"\n";
		}
	}
	int ans=0;
	rep(i,0,n){
		amax(ans,calc(i,i,1<<i));
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