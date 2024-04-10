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

const int N=2e5+5;

int a[N];
map<int, int> m;

void solve(){
	int n,k;
	cin>>n>>k;
	int sum=0;
	rep(i,0,n){
		cin>>a[i];
		sum+=a[i];
		m[a[i]]++;
	}
	int ans=sum,ps=0,pf=0;
	for(pii x:m){
		if(x.sc>=k){
			cout<<0;
			return;
		}
		int mv=(x.fr-1)*pf - ps;
		if(pf+x.sc>=k){
			amin(ans,mv+k-x.sc);
		}
		
		int mv2=(sum-ps-x.fr*x.sc)-(x.fr+1)*(n-pf-x.sc);
		if(n-pf>=k){
			amin(ans,mv2+k-x.sc);
		}
		
		amin(ans,mv+mv2+k-x.sc);
		ps+=x.fr*x.sc;
		pf+=x.sc;
	}
	cout<<ans;
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