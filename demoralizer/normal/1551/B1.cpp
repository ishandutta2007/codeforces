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

void solve(){
	string a;
	cin >> a;
	int n = sz(a);
	int k = 2;
	
	vector<int> f(26+1);
	vector<int> diff(n+2);
	
	vector<vector<int>> occ(26 + 1);
	vector<int> pr(n);
	
	int rem = n;
	rep(i,0,n){
		a[i] -= 'a' - 1;
		f[a[i]]++;
		occ[a[i]].pb(i);
	}
	
	rep(i,1,26+1){
		diff[0]++;
		diff[f[i] + 1]--;
	}
	
	int pf = 0;
	int ans = 0;
	int num;
	rep(i,1,k+1){
		diff[i] += diff[i - 1];
		pf += diff[i];
		int tmp = pf / i * i;
		if(i == k){
			ans = tmp;
			num = i;
		}
	}
	
	int e = ans / num;
	int cnt = 0;
	rep(i,1,26+1){
		rep(j,0,min(num,f[i])){
			int x = occ[i][j];
			pr[x] = ++cnt;
			if(cnt == num){
				cnt = 0;
				e--;
				if(e == 0) break;
			}
		}
		if(e == 0) break;
	}
	
	cout << ans / 2;
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