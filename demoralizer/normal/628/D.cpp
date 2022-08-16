#include "bits/stdc++.h"
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

const int N=2005;

int n,m,d;
string p,q; // a < b
int a[N],b[N];
int dp[N][N][2][2]; // id,rem,aflag,bflag

int calc(int id,int rem,int aflag,int bflag){
	if(id == n){
		return (rem == 0);
	}
	// cout << id << " " << a[id] << " " << b[id] << "\n";
	int &ans = dp[id][rem][aflag][bflag];
	if(ans != -1){
		return ans;
	}
	ans = 0;
	
	if(aflag && bflag){
		rep(x,0,10){
			if((id % 2 && x != d) || (id % 2 == 0 && x == d)){
				continue;
			}
			ans = (ans + calc(id+1,(10*rem+x)%m,1,1)) % M;
		}
	}
	else if(aflag && bflag == 0){
		rep(x,0,b[id]+1){
			if((id % 2 && x != d) || (id % 2 == 0 && x == d)){
				continue;
			}
			ans = (ans + calc(id+1,(10*rem+x)%m,1,x!=b[id])) % M;
		}
	}
	else if(aflag == 0 && bflag){
		rep(x,a[id],10){
			if((id % 2 && x != d) || (id % 2 == 0 && x == d)){
				continue;
			}
			ans = (ans + calc(id+1,(10*rem+x)%m,x!=a[id],1)) % M;
		}
	}
	else{
		rep(x,a[id],b[id]+1){
			if((id % 2 && x != d) || (id % 2 == 0 && x == d)){
				continue;
			}
			ans = (ans + calc(id+1,(10*rem+x)%m,x!=a[id],x!=b[id])) % M;
		}
	}
	
	return ans;
}

void solve(){
	mem1(dp);
	cin >> m >> d >> p >> q;
	n = sz(p);
	
	rep(i,0,n){
		a[i] = p[i] - '0';
		b[i] = q[i] - '0';
	}
	
	cout << calc(0,0,0,0);
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