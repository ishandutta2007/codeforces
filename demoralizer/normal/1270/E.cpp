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

const int N=1005;

int x[N],y[N];
int t[N];

void solve(){
	int n;
	cin >> n;
	// if(n == 2){
	// 	cout << "1\n1";
	// 	return;
	// }
	
	rep(i,0,n){
		cin >> x[i] >> y[i];
		x[i] += 3 * N * N;
		y[i] += 3 * N * N;
	}
	int d = 2;
	while(1){
		
		set<int> r;
		rep(i,0,n){
			int t = abs(x[i] + y[i]);
			t %= d;
			r.insert(t);
		}
		if(sz(r) == 1){
			rep(i,0,n){
				int a = x[i] + y[i], b = x[i] - y[i];
				x[i] = a;
				y[i] = b;
			}
			d *= 2;
		}
		else{
			vector<int> a;
			rep(i,0,n){
				if(abs(x[i] + y[i]) % d == abs(x[0] + y[0]) % d){
					a.pb(i + 1);
				}
			}
			cout << sz(a) << "\n";
			for(int x:a){
				cout << x << " ";
			}
			return;
		}
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