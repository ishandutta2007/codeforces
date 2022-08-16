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

const int N=405;

int f[N][26];
int dp[N][N];

void solve(){
	string s,t;
	cin>>s>>t;
	int n=sz(s);
	rep(i,0,26){
		f[n][i]=n+1;
		f[n+1][i]=n+1;
	}
	for(int i=n-1;i>=0;i--){
		rep(j,0,26){
			f[i][j]=f[i+1][j];
			if(s[i]=='a'+j)f[i][j]=i;
		}
	}
	int m=sz(t);
	rep(p,0,m){
		rep(i,0,m+1){
			rep(j,0,m+1){
				dp[i][j]=n+1;
			}
		}
		dp[0][0]=0;
		int X=p,Y=m-p;
		rep(sum,0,X+Y+1){
			rep(x,max(0LL,sum-Y),min(sum,X)+1){
				int y=sum-x;
				if(x>0)amin(dp[x][y],f[dp[x-1][y]][t[x-1]-'a']+1);
				if(y>0)amin(dp[x][y],f[dp[x][y-1]][t[p+y-1]-'a']+1);
				// cout<<x<<" "<<y<<" "<<dp[x][y]
			}
		}
		if(dp[X][Y]<n+1){
			cout<<"YES";
			return;
		}
	}
	cout<<"NO";
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
	cin>>t;
	while(t--) solve(),cout<<"\n";
	return 0;
}