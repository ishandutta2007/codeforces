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
const int32_t M=998244353;

const int N=0;

int pw(int a,int p=M-2,int MOD=M){
	int result = 1;
	while (p > 0) {
		if (p & 1)
			result = a * result % MOD;
		a = a * a % MOD;
		p >>= 1;
	}
	return result;
}

vector<int> der(vector<int> f){
	int n = sz(f);
	rep(i,0,n-1){
		f[i] = (i + 1) * f[i + 1] % M;
	}
	f.resize(n-1);
	return move(f);
}
vector<int> mulc(int c,vector<int> f){
	int n = sz(f);
	rep(i,0,n){
		f[i] = c * f[i] % M;
	}
	return move(f);
}
vector<int> mulx(vector<int> f){
	int n = sz(f);
	f.resize(n+1);
	for(int i = n; i > 0; i--){
		f[i] = f[i-1];
	}
	f[0] = 0;
	return move(f);
}
vector<int> add(vector<int> f,const vector<int> &g){
	int n = max(sz(f),sz(g));
	f.resize(n);
	rep(i,0,min(n,sz(g))){
		f[i] += g[i];
	}
	return move(f);
}

int a,p,q;

void solve(){
	int n,m,k;
	cin >> n >> m >> k;
	p = pw(m);
	q = (m - 1) * p % M;
	
	a = n;
	vector<int> f = {1};
	
	// (px + q)^a * f
	
	rep(i,0,k){
		if(a == 0){
			f = mulx(der(f));
			continue;
		}
		vector<int> fd = der(f);
		int ap = a * p % M;
		f = mulx(add(add(mulc(ap,f),mulc(q,fd)),mulx(mulc(p,fd))));
		a--;
	}
	
	int ans = 0;
	for(int x:f){
		ans = (ans + x) % M;
	}
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