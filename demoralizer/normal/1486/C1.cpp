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

map<pii, int> qans;

int query(int l,int r){
	if(qans.count({l,r})){
		return qans[{l,r}];
	}
	if(l == r){
		return -1;
	}
	cout << "? " << l << " " << r << endl;
	int ans;
	cin >> ans;
	return qans[{l,r}] = ans;
}
void answer(int x){
	cout << "! " << x << endl;
	exit(0);
}

void solve(){
	int n;
	cin >> n;
	
	int smx = query(1,n);
	int ans;
	if(smx == query(1,smx)){
		// [1 to smx]
		int L = 1, U = smx - 1;
		while(L <= U){
			int m = (L + U) / 2;
			if(query(m,smx) == smx){
				ans = m;
				L = m + 1;
			}
			else{
				U = m - 1;
			}
		}
	}
	else{
		// [smx to r]
		int L = smx + 1, U = n;
		while(L <= U){
			int m = (L + U) / 2;
			if(query(smx,m) == smx){
				ans = m;
				U = m - 1;
			}
			else{
				L = m + 1;
			}
		}
	}
	answer(ans);
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