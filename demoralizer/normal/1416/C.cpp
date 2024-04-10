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

const int N=3e5+5;


void solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	rep(i,0,n){
		cin>>a[i];
	}
	
	int x = 0;
	int tot = 0;
	for(int b = 30; b >= 0; b--){
		int B = b+1;
		stable_sort(all(a),[&](int x,int y){
			return (x>>B) < (y>>B);
		});
		int cnt0 = 0, cnt1 = 0;
		
		int ans0 = 0, ans1 = 0;
		
		for(int i = n-1; i >= 0; i--){
			if(i != n-1){
				if(a[i]>>B != a[i+1]>>B){
					cnt1 = cnt0 = 0;
				}
				if(a[i]>>b&1){
					ans0 += cnt0;
				}
				else{
					ans1 += cnt1;
				}
			}
			if(a[i]>>b&1) cnt1++;
			else cnt0++;
			
		}
		if(ans1 < ans0){
			x |= (1 << b);
			tot += ans1;
		}
		else{
			tot += ans0;
		}
	}
	cout << tot << " " << x;
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