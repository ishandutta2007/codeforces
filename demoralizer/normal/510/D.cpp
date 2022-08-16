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

const long long INF=1e9;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=0;

int l[305];
int c[305];
map<int, int> dp[305];

void solve(){
	int n;
	cin>>n;
	rep(i,0,n){
		int x;
		cin>>x;
		int y=x;
		l[i]=y;
	}
	rep(i,0,n){
		cin>>c[i];
	}
	dp[0][0]=0;
	dp[0][l[0]]=c[0];
	rep(i,1,n){
		for(auto x:dp[i-1]){
			auto it=dp[i].find(x.fr);
			if(it==dp[i].end() || it->sc > x.sc){
				dp[i][x.fr]=x.sc;
			}
			int k = __gcd(x.fr,l[i]);
			it=dp[i].find(k);
			if(it==dp[i].end() || it->sc > x.sc+c[i]){
				dp[i][k]=x.sc+c[i];
			}
		}
	}
	if(!dp[n-1][1])cout<<-1;
	else cout<<dp[n-1][1];
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