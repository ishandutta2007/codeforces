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

const int N=4e6+5;
int present[N];

void solve(){
	int n,k;
	string s;
	cin >> n >> k >> s;
	vector<int> v(n+1);
	
	rep(i,1,n+1){
		v[i] = v[i-1] + (s[i-1] == '0');
	}
	
	rep(i,1,k+1){ // binary search if this TLEs
		// i will never be > 20
		assert(i < 21);
		for(int l = 0, r = k - 1; r < n; l++, r++){
			// substring [l...r]
			int tmp = 0; 
			for(int j = r - i + 1; j <= r; j++){
				tmp = 2 * tmp + (s[j] - '0');
			}
			if(v[r - i + 1] - v[l] == 0)
				present[tmp] = 1;
		}
		
		int ans = -1;
		for(int j = (1<<i) - 1; j >= 0; j--){
			// cout << j << " " << present[j] << "\n";
			if(!present[j]){
				ans = j;
				break;
			}
		}
		
		for(int l = 0, r = k - 1; r < n; l++, r++){
			// substring [l...r]
			int tmp = 0; 
			for(int j = r - i + 1; j <= r; j++){
				tmp = 2 * tmp + (s[j] - '0');
			}
			present[tmp] = 0;
		}
		
		
		if(ans == -1){
			continue;
		}
		ans = (1<<i) - 1 - ans;
		cout << "YES\n";
		string t;
		while(ans){
			t.pb((ans % 2) + '0');
			ans /= 2;
		}
		while(sz(t) < k){
			t.pb('0');
		}
		reverse(all(t));
		cout << t;
		cout << "\n";
		return;
	}
	
	cout << "NO\n";
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