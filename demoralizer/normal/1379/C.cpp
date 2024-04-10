#include "bits/stdc++.h"
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

const int N=1e5+5;

int a[N],b[N],c[N],d[N];

void solve(){
	int n,m;
	cin>>n>>m;
	rep(i,0,m){
		cin>>a[i]>>b[i];
		c[i] = a[i];
	}
	sort(c,c+m,greater<int>());
	
	d[0] = c[0];
	rep(i,1,m){
		d[i] = d[i-1] + c[i];
	}
	
	int ans = 0;
	
	rep(i,0,m){
		int tmp = a[i] + (n-1)*b[i];
		int id = lower_bound(c,c+m,b[i],greater<int>()) - c;
		amin(id, n-1);
		tmp -= id*b[i];
		if(id){
			tmp += d[id-1];
			// cout<<i<<" "<<tmp<<"\n";
			if(a[i] >= c[id-1] && (id == m || a[i] != c[id])) tmp += b[i] , tmp -= a[i];
		}
		amax(ans,tmp);
	}
	cout<<ans<<"\n";
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SIEVE
		sieve();
	#endif
	#ifdef NCR
		init();
	#endif
	int t=1;
	cin>>t;
	while(t--) solve();
	return 0;
}