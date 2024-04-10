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

int n,k;
int a[30];

pii dp[20][1<<11][2];

pii calc(int pos,int mask,int small){
	if(pos == n){
		// initial condition
		if(ppc(mask) <= k){
			return {0,1};
		}
		else{
			return {0,0};
		}
	}
	pii &ans = dp[pos][mask][small];
	if(ans.fr != -1){
		return ans;
	}
	ans.fr = 0;
	rep(i,0,10){
		if(!small && i > a[pos]) continue;
		int ns = small || (i < a[pos]);
		int nm = mask | (1 << i);
		if(mask == 0 && i == 0){
			nm = 0;
		}
		int np = pos + 1;
		pii tmp = calc(np,nm,ns);
		ans.fr += tmp.fr + tmp.sc * i % M * pw(10,n - pos - 1) % M;
		ans.fr %= M;
		ans.sc = (ans.sc + tmp.sc) % M;
	}
	return ans;
}

void clear_dp(){
	rep(i,0,20){
		rep(j,0,1<<11){
			rep(k,0,2){
				dp[i][j][k] = {-1,0};
			}
		}
	}
}

void solve(){
	int l;
	string r;
	cin >> l >> r >> k;
	
	int ans = 0;
	n = sz(r);
	rep(i,0,n){
		a[i] = r[i] - '0';
	}
	clear_dp();
	ans = calc(0,0,0).fr;
	
	r = to_string(l - 1);
	n = sz(r);
	rep(i,0,n){
		a[i] = r[i] - '0';
	}
	clear_dp();
	ans = ans - calc(0,0,0).fr;
	ans %= M;
	ans += M;
	ans %= M;
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