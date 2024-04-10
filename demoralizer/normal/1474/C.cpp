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

const int N=2e3 + 5;

int a[N];

void solve(){
	int n;
	cin >> n;
	int mx = 0;
	rep(i,0,2*n){
		cin >> a[i];
		if(a[i] > a[mx]){
			mx = i;
		}
	}
	
	
	int ans = -1;
	rep(i,0,2*n){
		if(i == mx){
			continue;
		}
		// remove i
		int x = a[mx];
		multiset<int> tmp;
		rep(j,0,2*n){
			if(j == mx || j == i) continue;
			tmp.insert(a[j]);
		}
		
		bool ok = 1;
		while(sz(tmp)){
			int a = *tmp.rbegin();
			tmp.erase(tmp.find(a));
			if(tmp.find(x - a) == tmp.end()){
				ok = 0;
				break;
			}
			tmp.erase(tmp.find(x - a));
			x = a;
		}
		if(ok == 1){
			ans = i;
		}
	}
	
	if(ans == -1){
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	
	int x = a[mx] + a[ans];
	cout << x << "\n";
	
	multiset<int> tmp;
	rep(i,0,2*n){
		tmp.insert(a[i]);
	}
	
	
	while(sz(tmp)){
		int a = *tmp.rbegin();
		tmp.erase(tmp.find(a));
		tmp.erase(tmp.find(x-a));
		cout << a << " " << x - a << "\n";
		x = a;
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
	cin>>t;
	while(t--) solve();
	return 0;
}