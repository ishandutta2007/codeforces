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

int mn[200];
string p[N];

int calc(int i,char c){
	if(i < 0){
		return 0;
	}
	bool ok = 1;
	for(char d:p[i]){
		if(c != d) ok = 0;
	}
	
	if(!ok){
		int ans = 0;
		bool avail = (mn[c] < i);
		
		if(avail){
			int a = 0;
			while(p[i][a] == c) a++;
			int z = sz(p[i]);
			int b = 0;
			while(p[i][z-b-1] == c) b++;
			amax(ans,a + b + 1);
		}
		
		int tmp = 0;
		rep(j,0,sz(p[i])){
			if(p[i][j] == c){
				tmp++;
				amax(ans,tmp);
			}
			else{
				tmp = 0;
			}
		}
		// cout << i << " " << ans << " not ok\n";
		return ans;
	}
	int z = sz(p[i]);
	int ans = (calc(i-1,c) + 1) * (z + 1) - 1;
	// cout << i << " " << ans << " ok\n";
	return ans;
}

void solve(){
	int n;
	cin >> n;
	
	rep(i,0,200){
		mn[i] = n;
	}
	
	rep(i,0,n){
		cin >> p[i];
		for(char c:p[i]){
			amin(mn[c],i);
		}
	}
	char c = p[n - 1][0];
	bool ok = 1;
	for(char d:p[n-1]){
		if(c != d){
			ok = 0;
		}
	}
	
	if(!ok){
		int ans = 0;
		rep(_,0,2){
			bool avail = (mn[c] < n - 1);
			if(avail){
				int a = 0;
				while(p[n-1][a] == c) a++;
				int b = 0;
				int z = sz(p[n-1]);
				while(p[n-1][z - b - 1] == c) b++;
				amax(ans,a + b + 1);
			}
			c = p[n-1].back();
		}
		
		int tmp = 1;
		rep(i,1,sz(p[n-1])){
			if(p[n-1][i] == p[n-1][i-1]){
				tmp++;
			}
			else{
				amax(ans,tmp);
				tmp = 1;
			}
		}
		amax(ans,tmp);
		
		cout << ans;
		return;
	}
	
	int z = sz(p[n-1]);
	
	cout << (calc(n-2,c) + 1) * (z + 1) - 1;
	
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