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

const int N=1e6+5;

#define SIEVE
vector<int> f[N];
void sieve(){
	for(int i=2;i<N;i++){
		if(f[i].empty()){
			for(int j=i;j<N;j+=i){
				f[j].pb(i);
			}
		}
	}
}

int bktrk(int x,int p,int id = 0,int cnt = 0,int val = 1){
	if(id == sz(f[p])){
		if(cnt) return -x/val;
		else return x/val;
	}
	return bktrk(x,p,id+1,cnt,val) + bktrk(x,p,id+1,!cnt,val*f[p][id]);
}

void solve(){
	int x,p,k;
	cin>>x>>p>>k;
	k += bktrk(x,p);
	int L = 1, U = 1e8, ans = 0;
	while(L <= U){
		int m = (L+U)/2;
		if(bktrk(m,p) >= k){
			ans = m;
			U = m - 1;
		}
		else{
			L = m + 1;
		}
	}
	cout << ans << "\n";
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