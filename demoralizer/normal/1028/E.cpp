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

const int N=150000;

int a[N];
int b[N];

void solve(){
	int n;
	cin >> n;
	set<int> s;
	rep(i,0,n){
		cin >> b[i];
		s.insert(b[i]);
	}
	if(sz(s) == 1){
		if(b[0] == 0){
			cout << "YES\n";
			rep(i,0,n){
				cout << 1 << " ";
			}
		}
		else{
			cout << "NO";
		}
		return;
	}
	
	int x = 0;
	while(b[x] <= b[(x + n - 1) % n]){
		x++;
	}
	
	a[x] = b[x];
	rep(i,1,n){
		int y = (x - i + n) % n;
		int z = (y + 1) % n;
		int w = (y - 1 + n) % n;
		// cout << y << " " << z << " " << w << "\n";
		w = b[w];
		int t = w - b[y];
		int k = t / a[z];
		while(k * a[z] <= t){
			k++;
		}
		a[y] = k * a[z] + b[y];
	}
	cout << "YES\n";
	rep(i,0,n){
		cout << a[i] << " ";
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