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

const int N=1e3+5;

int mx[N];
int a[200];
int cnt[200];
int dp[N];

void solve(){
	int n;
	string s;
	cin>>n>>s;
	rep(i,'a','z'+1){
		cin>>a[i];
	}
	
	
	int ansmx=0;
	
	rep(i,0,n){
		
		rep(k,'a','z'+1){
			cnt[k]=0;
		}
		
		rep(j,i,n){
			cnt[s[j]]++;
			bool f=1;
			rep(k,'a','z'+1){
				if(cnt[k] && j-i+1 > a[k]){
					f=0;
					break;
				}
			}
			if(!f){
				break;
			}
			mx[i]=j;
		}
		amax(ansmx,mx[i]+1-i);
	}
	
	dp[n]=1;
	for(int i=n-1;i>=0;i--){
		rep(j,i,mx[i]+1){
			dp[i]+=dp[j+1];
			dp[i]%=M;
		}
	}
	
	int best=0,i=0;
	while(i<n){
		best++;
		i=mx[i]+1;
	}
	
	cout<<dp[0]<<"\n"<<ansmx<<"\n"<<best<<"\n";
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