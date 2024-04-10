#include <bits/stdc++.h>
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
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

int r[N];
int x[N],y[N];
int ans = 0;

int sq(int x){
	return x*x;
}

void solve(){
	int n;
	cin>>n;
	rep(i,1,n+1){
		cin>>x[i]>>y[i]>>r[i];
	}
	rep(i,1,n+1){
		int lvl=1;
		rep(j,1,n+1){
			if(i==j)continue;
			if(r[i]<r[j] && sq(x[i]-x[j]) + sq(y[i]-y[j]) <= sq(r[j])){
				lvl++;
			}
		}
		if(lvl == 1 || lvl%2==0)ans+=sq(r[i]);
		else ans-=sq(r[i]);
	}
	cout<<setprecision(15);
	cout<<fixed;
	cout<<3.14159265359*ans;
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