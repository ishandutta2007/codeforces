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

const int N=0;

int d,s;
int vis[5005][501];
pii par[5005][501];

void solve(){
	cin >> d >> s;
	
	queue<pii> z;
	z.push({0,0});
	vis[0][0] = 1;
	
	vector<int> ans;
	
	while(sz(z)){
		auto tmp = z.front();
		z.pop();
		int sum = tmp.fr;
		int rem = tmp.sc;
		if(sum == s && rem == 0){
			while(sum){
				int ps = par[sum][rem].fr;
				int pr = par[sum][rem].sc;
				int dig = sum - ps;
				ans.pb(dig);
				sum = ps;
				rem = pr;
			}
			reverse(all(ans));
			for(int x:ans){
				cout << x;
			}
			return;
		}
		rep(i,0,10){
			if(sum + i > s) continue;
			int ns = sum + i;
			int nr = (10 * rem + i) % d;
			if(vis[ns][nr]) continue;
			vis[ns][nr] = 1;
			z.push({ns,nr});
			par[ns][nr] = {sum,rem};
		}
	}
	
	cout << -1;
	
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