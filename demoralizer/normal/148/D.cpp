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

const int N=1005;

double dp[N][N][2];
bool vis[N][N][2];

double calc(int w,int b,int t){
	if(w==0)return 0;
	double &ans=dp[w][b][t];
	if(vis[w][b][t]){
		return ans;
	}
	vis[w][b][t]=1;
	if(t==0){
		ans+=1.0*w/(w+b);
		if(b>0)ans+=calc(w,b-1,!t)*b/(w+b);
	}
	else{
		if(w>0 && b>0)ans+=1.0*b/(w+b)*(1.0*w/(w+b-1)*calc(w-1,b-1,!t));
		if(b>1)ans+=1.0*b/(w+b)*(1.0*(b-1)/(w+b-1)*calc(w,b-2,!t));
	}
	return ans;
}

void solve(){
	int w,b;
	cin>>w>>b;
	cout<<setprecision(10);
	cout<<fixed;
	cout<<calc(w,b,0);
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