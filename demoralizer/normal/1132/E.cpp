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

int cnt[9];

void solve(){
	int w;
	cin >> w;
	rep(i,1,9){
		cin >> cnt[i];
	}
	rep(i,1,5){
		int tmp = cnt[i] / 2;
		tmp = max(tmp - 1, 0LL);
		cnt[2 * i] += tmp;
		cnt[i] -= tmp * 2;
	}
	int cnt840 = 0;
	rep(i,5,9){
		int tmp = cnt[i] * i / 840;
		tmp = max(tmp - 1, 0LL);
		cnt840 += tmp;
		cnt[i] -= tmp * (840 / i); 
	}
	
	const int K = 840 * 8 + 200;
	
	vector<int> possible(K + 1);
	possible[0] = 1;
	
	rep(i,1,9){
		int c = cnt[i];
		while(c--){
			for(int j = K; j >= i; j--){
				possible[j] |= possible[j - i];
			}
		}
	}
	
	int ans = 0;
	
	rep(i,0,K){
		if(!possible[i] || i > w) continue;
		int z = w - i;
		// take as many 840 as possible
		int take = min(cnt840,z/840);
		amax(ans,take*840 + i);
	}
	
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