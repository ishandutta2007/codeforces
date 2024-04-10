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

#define NCR
#define PRIME	M
int pw(int a,int p=M-2,int MOD=M){
	int result = 1;
	while (p > 0) {
		if (p & 1)
			result = a * result % MOD;
		a = a * a %M;
		p >>= 1;
	}
	return result;
}
int fact[100005],invfact[100005];
void init(){
	int p=PRIME;
	fact[0]=1;
	int i;
	for(i=1;i<100005;i++){
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

vector<int> pr={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};

int masks[75];
int cnt[75];
int dp[1<<19];
int newdp[1<<19];

void solve(){
	rep(i,1,71){
		int x=i;
		rep(j,0,19){
			int cnt=0;
			while(x%pr[j]==0)cnt^=1,x/=pr[j];
			masks[i]|=cnt<<j;
		}
	}
	int n;
	cin>>n;
	rep(i,0,n){
		int x;
		cin>>x;
		cnt[x]++;
	}
	dp[0]=1;
	rep(i,1,71){
		mem0(newdp);
		int a=0,b=0;
		rep(j,0,cnt[i]+1){
			if(j&1)b=(b+ncr(cnt[i],j))%M;
			else a=(a+ncr(cnt[i],j))%M;
		}
		// cout<<i<<" "<<a<<" "<<b<<"\n";
		rep(j,0,1<<19){
			newdp[j]+=dp[j]*a;
			newdp[j]%=M;
			newdp[j]+=dp[j^masks[i]]*b;
			newdp[j]%=M;
			// newdp[j^masks[i]]%=M;
		}
		
		rep(j,0,1<<19){
			dp[j]=newdp[j];
		}
	}
	cout<<(dp[0]-1+M)%M;
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