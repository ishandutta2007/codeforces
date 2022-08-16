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

int last[N][2];

void solve(){
	int n;
	cin >> n;
	
	int u = -1, v = INF;
	int prev;
	rep(i,0,n){
		int x;
		cin >> x;
		if(i){
			// prev,v or u,prev
			
			//inc
			int v2 = -1;
			if(x > prev){
				// v
				v2 = v;
				last[i][0] = 0;
			}
			if(x > u){
				if(prev > v2){
					v2 = prev;
					last[i][0] = 1;
				}
			}
			
			// dec
			int u2 = INF;
			if(x < prev){
				u2 = u;
				last[i][1] = 1;
			}
			if(x < v){
				if(prev < u2){
					u2 = prev;
					last[i][1] = 0;
				}
			}
			
			v = v2;
			u = u2;
		}
		prev = x;
	}
	
	if(u != INF || v != -1){
		cout << "YES\n";
		int z = 0;
		if(u != INF){
			z = 1;
		}
		
		vector<int> ans;
		for(int i = n - 1; i >= 0; i--){
			ans.pb(z);
			z = last[i][z];
		}
		reverse(all(ans));
		for(int x:ans){
			cout << x << " ";
		}
	}
	else{
		cout << "NO";
	}
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