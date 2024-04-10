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

const int N=705;

int n;
int dp[N][N][2];

// dp[i][j][0] = [i...j] can be left child

int g[N][N];
int a[N];

int calc(int l,int r,int f){
	if(f==0 && r==n-1)return 0;
	if(f==1 && l==0)return 0;
	if(l==r){
		if(!f){
			return (g[r][r+1]!=1);
		}
		else{
			return (g[l][l-1]!=1);
		}
	}
	int &ans=dp[l][r][f];
	if(ans!=-1)return ans;
	
	int par;
	
	if(!f) par=r+1;
	else   par=l-1;

	ans=calc(l+1,r,1) && (g[l][par]!=1);
	ans|=calc(l,r-1,0) && (g[r][par]!=1);
	rep(i,l+1,r){
		ans|=calc(l,i-1,0) && calc(i+1,r,1) && (g[i][par]!=1);
	}
	return ans;
}

void solve(){
	mem1(dp);
	cin>>n;
	rep(i,0,n){
		cin>>a[i];
	}
	rep(i,0,n){
		rep(j,0,n){
			g[i][j]=__gcd(a[i],a[j]);
			// cout<<i << " "<<j<<" "<<g[i][j]<<"\n";
		}
	}
	
	int ans=calc(1,n,1) | calc(0,n-1,0);
	
	rep(i,1,n-1){
		ans|=calc(0,i-1,0) && calc(i+1,n,1);
	}
	
	cout<<(ans?"Yes":"No");
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