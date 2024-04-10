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

const int N=2005;

pii a[N];

#define NCR
#define PRIME	M
int pw(int a,int p=M-2,int MOD=M){
	int result = 1;
	while (p > 0) {
		if (p & 1)
			result = a * result % MOD;
		a = a * a %MOD;
		p >>= 1;
	}
	return result;
}
int fact[200005],invfact[200005];
void init(){
	int p=PRIME;
	fact[0]=1;
	int i;
	for(i=1;i<200005;i++){
		fact[i]=(i*fact[i-1])%p;
	}
	i--;
	invfact[i]=pw(fact[i],p-2,p);
	for(i--;i>=0;i--){
		invfact[i]=(invfact[i+1]*(i+1))%p;
	}
}
int ncr(int n,int r){
	return (((fact[n]*invfact[r])%PRIME)*invfact[n-r])%PRIME;
}

int dp[N];

void solve(){
	int h,w,n;
	cin>>h>>w>>n;
	rep(i,0,n)cin>>a[i],a[i].fr--,a[i].sc--;
	a[n]={h-1,w-1};
	sort(a,a+n+1);
	
	rep(i,0,n+1){
		dp[i]=ncr(a[i].fr+a[i].sc,a[i].fr);
		rep(j,0,i){
			if(a[i].sc>=a[j].sc && a[i].fr>=a[j].fr){
				dp[i]-=dp[j]*ncr(a[i].sc-a[j].sc+a[i].fr-a[j].fr,a[i].fr-a[j].fr)%M;
				dp[i]%=M;
				if(dp[i]<0)dp[i]+=M;
			}
		}
	}
	cout<<dp[n];
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