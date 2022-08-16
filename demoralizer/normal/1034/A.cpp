#include <bits/stdc++.h>
using namespace std;
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

const int N=3e5+5;
const int K=2e7+5;

int a[N];
int cnt[K];

#define N K
int lp[N+1];
vector<int> pr;
#define SIEVE
void sieve(){
	for (int i=2; i<=N; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.push_back (i);
		}
		for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
			lp[i * pr[j]] = pr[j];
	}
}

void solve(){
	int n;
	cin>>n;
	int g = 0;
	rep(i,0,n){
		cin>>a[i];
		g = __gcd(g,a[i]);
	}
	
	bool f = 1;
	rep(i,0,n){
		a[i] /= g;
		if(a[i]!=1){
			f = 0;
		}
	}
	
	if(f){
		cout<<-1;
		return;
	}
	
	rep(i,0,n){
		int x = a[i];
		set<int> pf;
		while(lp[x]){
			pf.insert(lp[x]);
			x/=lp[x];
		}
		for(int y:pf){
			cnt[y]++;
		}
	}
	
	int ans = 0;
	rep(i,2,K){
		amax(ans,cnt[i]);
	}
	
	cout<<n-ans;
	
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