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
	int n;
	cin >> n;
	vector<int> a(n),b(n),c(n);
	rep(i,0,n){
		cin >> a[i];
		b[i] = a[i];
		if(i > 1){
			a[i] += a[i - 2];
		}
	}
	
	if(a[n-1] == a[n-2]){
		bool ok = 1;
		rep(i,1,n){
			if(a[i] < a[i - 1]) ok = 0;
		}
		if(ok){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
		return;
	}
	int diff = abs(a[n-1] - a[n-2]);
	if(diff % 2){
		cout << "NO\n";
		return;
	}
	diff = a[n-1] - a[n-2];
	diff /= 2;
	
	int inctill = 0;
	rep(i,1,n){
		if(a[i] >= a[i-1]) inctill = i;
		else break;
	}
	rep(i,0,n){
		c[i] = a[i];
		if(i % 2 == (n - 1) % 2){
			c[i] -= diff;
		}
		else{
			c[i] += diff;
		}
	}
	
	int incfrom = n-1;
	for(int i = n - 2; i >= 0; i--){
		if(c[i] <= c[i+1]) incfrom = i;
		else break;
	}
	
	// cout << diff << "\n";
	
	rep(i,0,n-1){
		if(i % 2 == (n - 1) % 2){
			if(b[i+1] - b[i] == -diff){
				if((i == 0 || a[i-1] <= c[i]) && inctill >= i - 1 && incfrom <= i){
					cout << "YES\n";
					return;
				}
			}
		}
		else{
			if(b[i] - b[i+1] == -diff){
				if((i == 0 || a[i-1] <= c[i]) && inctill >= i - 1 && incfrom <= i){
					cout << "YES\n";
					return;
				}
			}
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