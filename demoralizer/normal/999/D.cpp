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

int c[N], a[N];
vector<int> v[N];

void solve(){
	int n,m;
	cin>>n>>m;
	rep(i,0,n){
		int x;
		cin>>x;
		a[i] = x;
		v[x%m].pb(i);
		c[x%m]++;
	}
	rep(i,0,m){
		c[i] -= n/m;
	}
	int ans = 0;
	int carry = 0;
	bool flag = 1;
	vector<int> bag;
	
	while(flag){
		flag = 0;
		rep(i,0,m){
			ans += carry;
			if(c[i] < 0){
				int tmp = min(carry,-c[i]);
				carry -= tmp;
				c[i] += tmp;
				rep(j,0,tmp){
					v[i].pb(bag.back());
					bag.ppb();
				}
			}
			else if(c[i] > 0){
				carry += c[i];
				rep(j,0,c[i]){
					bag.pb(v[i].back());
					v[i].ppb();
				}
				c[i] = 0;
			}
		}
		rep(i,0,m){
			if(c[i]) flag = 1;
		}
	}
	cout << ans << "\n";
	rep(i,0,m){
		for(int j:v[i]){
			// rem = a[j] % m; req = i;
			a[j] += (i - a[j] % m + m) % m;
		}
	}
	rep(i,0,n){
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