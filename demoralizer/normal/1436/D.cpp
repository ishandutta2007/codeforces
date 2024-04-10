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

const int N=2e5+5;

int a[N];
vector<int> v[N];

array<int,3> dfs(int z){
	array<int,3> tmp = {0,0,0}; // {nL,extra,max}
	int mx = 0;
	int extra = 0;
	
	vector<array<int,3> > vec;
	
	for(int x:v[z]){
		auto tmp2 = dfs(x);
		mx = max(mx, tmp2[2]);
		tmp[0] += tmp2[0];
		vec.pb(tmp2);
	}
	for(auto tmp2:vec){
		extra += tmp2[1] + tmp2[0] * (mx - tmp2[2]);
	}
	
	if(v[z].empty()) tmp[0]++;
	tmp[2] = mx;
	// a[z] people can travel down
	int people = min(a[z],extra);
	extra -= people;
	
	int rem = a[z] - people;
	
	if(rem == 0){
		tmp[1] = extra;
	}
	else{
		int new_max = tmp[2] + (rem + tmp[0] - 1) / tmp[0];
		tmp[1] = tmp[0] - rem % tmp[0];
		if(tmp[1] == tmp[0]) tmp[1] = 0;
		tmp[2] = new_max;
	}
	
	return tmp;
}

void solve(){
	int n;
	cin >> n;
	for(int i = 2; i <= n; i++){
		int p;
		cin >> p;
		v[p].pb(i);
	}
	rep(i,1,n+1){
		cin >> a[i];
	}
	
	cout << dfs(1)[2];
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