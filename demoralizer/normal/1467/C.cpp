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

const int N=0;



void solve(){
	int n1,n2,n3;
	cin >> n1 >> n2 >> n3;
	vector<int> a(n1),b(n2),c(n3);
	
	vector<int> v;
	
	rep(i,0,n1){
		cin >> a[i];
		v.pb(a[i]);
	}
	rep(i,0,n2){
		cin >> b[i];
		v.pb(b[i]);
	}
	rep(i,0,n3){
		cin >> c[i];
		v.pb(c[i]);
	}
	
	int sum = 0;
	for(int x:v){
		sum += x;
	}
	
	int buck[3] = {0};
	for(int x:a){
		buck[0]+=x;
	}
	for(int x:b){
		buck[1]+=x;
	}
	for(int x:c){
		buck[2]+=x;
	}
	
	sort(all(a));
	sort(all(b));
	sort(all(c));
	
	int ans = 0;
	rep(i,0,3)
		amax(ans, sum - 2*buck[i]);
	
	amax(ans,sum - 2 * (a[0] + b[0]));
	amax(ans,sum - 2 * (c[0] + b[0]));
	amax(ans,sum - 2 * (a[0] + c[0]));
	cout << ans;
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
	//cin>>t;
	while(t--) solve();
	return 0;
}