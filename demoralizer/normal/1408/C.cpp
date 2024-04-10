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

const int N=1e5+5;

int a[N];
double lef[N];
double rig[N];

void solve(){
	int n,l;
	cin >> n >> l;
	rep(i,1,n+1){
		cin >> a[i];
		lef[i] = lef[i - 1] + (a[i] - a[i - 1]) * 1.0 / i;
	}
	a[0] = 0;
	a[n+1] = l;
	rig[n+1] = 0;
	for(int i = n; i >= 1; i--){
		rig[i] = rig[i + 1] + (a[i+1] - a[i]) * 1.0 / (n - i + 1);
	}
	
	double L = 0, U = l;
	double tl = 0, tr = 0;
	rep(i,0,60){
		tl = tr = 0;
		double m = (L + U) / 2;
		int id = upper_bound(a+1,a+1+n,m) - (a);
		tr += rig[id];
		tl += lef[id-1];
		tl += (m - a[id-1]) * 1.0 / id;
		tr += (a[id] - m) * 1.0 / (n - id + 2);
		
		// cout << id << " " << tl <<  " " << tr << "\n";
		
		if(tl < tr){
			L = m;
		}
		else{
			U = m;
		}
	}
	cout<<setprecision(12);
	cout<<fixed;
	cout << tl << "\n";
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