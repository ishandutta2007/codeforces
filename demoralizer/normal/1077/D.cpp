#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define sz(x)             (int)((x).size())
#define int               long long
#define M                 1000000007
#define MM                998244353
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount

template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}
template<typename T1,typename T2>std::istream& operator>>(std::istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>std::ostream& operator<<(std::ostream& out,pair<T1,T2> &a){out<<a.fr<<" "<<a.sc;return out;}

const int N=2e5+5;
int n,k;
int s[N];
int c[N];
vector<pii> v;

void solve(){
	cin>>n>>k;
	rep(i,0,n)cin>>s[i],c[s[i]]++;
	rep(i,0,N){
		if(c[i])v.pb({c[i],i});
	}
	sort(all(v));
	int L=1,U=n,ans=-1;
	while(L<=U){
		int m=(L+U)/2;
		int r=0;
		for(pii x:v){
			r+=x.fr/m;
		}
		if(r>=k){
			L=m+1;
			amax(ans,m);
		}
		else{
			U=m-1;
		}
	}
	vector<int> w;
	for(pii x:v){
		int r=x.fr/ans;
		rep(i,0,r)w.pb(x.sc);
	}
	rep(i,0,k)cout<<w[i]<<" ";
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
	#ifdef DSU
		cleardsu(MAXDSUSIZE);
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}