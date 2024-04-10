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

int f[N][35];

int mn[N][35];
int s[N][35];

void solve(){
	int n,k;
	cin>>n>>k;
	rep(i,0,n){
		cin>>f[i][0];
	}
	rep(i,0,n){
		cin>>mn[i][0];
		s[i][0] = mn[i][0];
	}
	
	rep(p,1,35){
		rep(i,0,n){
			mn[i][p] = min(mn[i][p-1] , mn[f[i][p-1]][p-1]);
			s[i][p] = s[i][p-1] + s[f[i][p-1]][p-1];
			f[i][p] = f[f[i][p-1]][p-1];
		}
	}
	
	rep(i,0,n){
		int a=0,b=INF;
		int x = i;
		rep(p,0,35){
			if(k>>p&1){
				a += s[x][p];
				amin(b,mn[x][p]);
				x = f[x][p];
			}
		}
		cout<<a<<" "<<b<<"\n";
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