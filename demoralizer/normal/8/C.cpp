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

const int N=(1<<24);

int n;
int x[25];
int y[25];
int dp[N];
int best[N];
int ver[N];

int calc(int mask){
	int &ans=dp[mask];
	if(ans!=-1)return ans;
	int b;
	rep(j,0,n){
		if(!(mask>>j&1)){
			b=j;
			break;
		}
	}
	
	ver[mask]=b;
	int &opt=best[mask];
	opt=-1;
	mask|=(1<<b);
	ans=calc(mask);
	
	rep(j,0,n){
		if(mask>>j&1)continue;
		int val=x[b]*x[j]+y[b]*y[j]+calc(mask|(1<<j));
		if(val>ans){
			ans=val;
			opt=j;
		}
	}
	
	return ans;
}

void solve(){
	mem1(dp);
	int a,b,ans=0;
	cin>>a>>b>>n;
	dp[(1<<n)-1]=0;
	rep(i,0,n){
		cin>>x[i]>>y[i];
		x[i]-=a;
		y[i]-=b;
		ans+=x[i]*x[i];
		ans+=y[i]*y[i];
	}
	cout<<2*(ans-calc(0))<<"\n";
	int mask=0;
	while(mask+1 != (1<<n)){
		cout<<"0 "<<ver[mask]+1<<" ";
		if(best[mask]!=-1)cout<<best[mask]+1<<" ",mask|=((1<<ver[mask])|(1<<best[mask]));
		else mask|=1<<ver[mask];
	}
	cout<<0;
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