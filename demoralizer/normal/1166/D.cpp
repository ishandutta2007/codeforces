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



void solve(){
	int a,b,m;
	cin >> a >> b >> m;
	
	int k = 1;
	while(k <= 50){
		int low = (1ll << max(k - 2,0ll)) * a;
		if(k > 1) low += (1ll << max(k - 2, 0ll));
		int high = (1ll << max(k - 2,0ll)) * a;
		if(k > 1) high += (1ll << max(k - 2, 0ll)) * m;
		if(b < low){
			cout << -1 << "\n";
			return;
		}
		if(b >= low && b <= high){
			break;
		}
		k++;
	}
	if(k == 1){
		cout << 1 << " " << a << "\n";
		return;
	}
	
	cout << k;
	int tmp = b - (1ll << (k-2)) * a;
	int x = tmp / (1ll << (k-2));
	tmp -= (1ll << (k-2)) * x;
	
	int r[k];
	rep(i,0,k) r[i] = x;
	r[0] = a;
	rep(i,0,k-2){
		if(tmp >> i & 1) r[k-2-i]++;
	}
	x = 0;
	rep(i,0,k){
		cout << " " << x + r[i];
		x = 2 * x + r[i];
	}
	cout << "\n";
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