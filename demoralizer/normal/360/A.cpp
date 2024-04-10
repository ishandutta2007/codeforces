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

const int N=5005;

int a[N];
int val[N];

void solve(){
	int n,m;
	cin >> n >> m;
	
	rep(i,1,n+1){
		a[i] = M - 7;
	}
	
	vector<vector<int>> v(m,vector<int>(4));
	
	rep(_,0,m){
		int t,l,r,d;
		cin >> t >> l >> r >> d;
		v[_] = {t,l,r,d};
		if(t == 1){
			rep(i,l,r+1){
				val[i] += d;
			}
		}
		else{
			int mx = -1e9;
			rep(i,l,r+1){
				amax(mx,val[i] + a[i]);
			}
			if(mx < d){
				cout << "NO";
				return;
			}
			rep(i,l,r+1){
				amin(a[i],d - val[i]);
			}
		}
	}
	
	rep(i,1,n+1){
		val[i] = 0;
	}
	rep(_,0,m){
		int t = v[_][0];
		int l = v[_][1];
		int r = v[_][2];
		int d = v[_][3];
		if(t == 1){
			rep(i,l,r+1){
				val[i] += d;
			}
		}
		else{
			int mx = -1e9;
			rep(i,l,r+1){
				amax(mx,a[i]+val[i]);
			}
			if(mx < d){
				cout << "NO";
				return;
			}
			assert(!(mx > d));
		}
	}
	
	cout << "YES\n";
	rep(i,1,n+1){
		cout << a[i] << " ";
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