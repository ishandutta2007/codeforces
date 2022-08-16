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

bool prime(int n){
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0){
			return false;
		}
	}
	return true;
}

void solve(){
	int x,d;
	cin >> x >> d;
	
	int c = 0;
	while(x % d == 0){
		c++;
		x /= d;
	}
	
	if(c == 1){
		cout << "NO\n";
		return;
	}
	
	if(x != 1 && !prime(x)){
		cout << "YES\n";
		return;
	}
	
	x *= d;
	c--;
	
	if(c == 1){
		cout << "NO\n";
		return;
	}
	
	for(int i = 2; i * i <= d; i++){
		if(d % i == 0){
			int a = 0, b = 0;
			while(d % i == 0) a++, d /= i;
			while(x % i == 0) b++, x /= i;
			if(d != 1){
				cout << "YES\n";
				return;
			}
			if((b + c - 1) / c < a){
				cout << "YES\n";
				return;
			}
			break;
		}
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