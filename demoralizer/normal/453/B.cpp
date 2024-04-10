#include "bits/stdc++.h"
using namespace std;
// #define int               long long
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

const int N=61;

#define SIEVE
int primes[N];
vector<int> pr;
void sieve(){
	for(int i=2;i<N;i++){
		if(primes[i]==0){
			pr.pb(i);
			for(int j=i*i;j<N;j+=i){
				primes[j]=1;
			}
		}
		primes[i]^=1;
	}
}

int dp[105][1<<17];
int choice[105][1<<17];
int a[105];

int prc[60];

int n;
int calc(int id,int mask){ // 10^5 * 100 = 10 ^ 7 * 60 = 6 * 10 ^ 8
	if(id == n){
		return 0;
	}
	int &ans = dp[id][mask];
	if(ans != -1){
		return ans;
	}
	
	ans = abs(a[id] - 1) + calc(id+1,mask);
	choice[id][mask] = 1;
	
	rep(i,2,60){
		if(prc[i] & mask){
			continue;
		}
		int tmp = abs(a[id] - i) + calc(id+1,mask|prc[i]);
		if(tmp < ans){
			choice[id][mask] = i;
		}
		amin(ans,tmp);
	}
	return ans;
}


void solve(){
	cin >> n;
	rep(i,0,n){
		cin >> a[i];
	}
	
	rep(i,2,60){
		int mask = 0;
		rep(j,0,17){
			if(i % pr[j] == 0){
				mask |= (1 << j);
			}
		}
		prc[i] = mask;
	}
	
	mem1(dp);
	
	calc(0,0);
	
	int id = 0, mask = 0;
	while(id < n){
		cout << choice[id][mask] << " ";
		mask |= prc[choice[id][mask]];
		id++;
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