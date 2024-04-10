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

const int N=1005;

vector<int> id[8];
int a[N];

int dp[N][8];
int ub(int cur,int x){
	assert(cur+1 >= 0 && cur+1 < N);
	// if(dp[cur+1][x] != -1){
	// 	return dp[cur+1][x];
	// }
	return dp[cur+1][x] = (upper_bound(all(id[x]),cur) - id[x].begin());
}

void solve(){
	mem1(dp);
	int n;
	cin >> n;
	rep(i,0,n){
		cin >> a[i];
		a[i]--;
		id[a[i]].pb(i);
	}
	
	int ans = 0;
	vector<int> v;
	rep(i,0,8){
		v.pb(i);
		if(sz(id[i])){
			ans++;
		}
	}
	
	do{
		int k = 0;
		while(1){
			int cur = -1;
			for(int x:v){
				int tmp = ub(cur,x);
				tmp += k;
				if(sz(id[x]) <= tmp){
					cur = n + 10;
					break;
				}
				cur = id[x][tmp];
			}
			if(cur < n){
				k++;
			}
			else{
				break;
			}
		}
		amax(ans, 8 * k);
		if(!k) continue;
		
		rep(mask,1,(1<<8)){
			int cur = -1;
			for(int x:v){
				int tmp = ub(cur,x);
				tmp += k - 1 + (mask >> x & 1);
				if(sz(id[x]) <= tmp){
					cur = n + 10;
					break;
				}
				cur = id[x][tmp];
			}
			if(cur < n){
				amax(ans, 8*k + ppc(mask));
			}
		}
	}while(next_permutation(all(v)));
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