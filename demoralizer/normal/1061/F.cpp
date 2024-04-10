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

int n,k;
int query(int a,int b,int c){
	cout << "? " << a << " " << b << " " << c << endl;
	string ans;
	cin >> ans;
	return (ans == "Yes");
}

vector<int> v;
vector<int> on_path;
int dis(int x,int y){
	on_path.clear();
	int ans = 0;
	rep(i,1,n+1){
		if(x == i || y == i) continue;
		if(query(x,i,y)){
			ans++;
			on_path.pb(i);
		}
	}
	return ans + 2;
}

void solve(){
	cin >> n >> k;
	vector<int> vers(1,1);
	while(vers.back() <= n){
		vers.pb(vers.back() * k);
	}
	int levs = 0;
	int tot = 0;
	while(tot != n){
		tot += vers[levs];
		levs++;
	}
	rep(i,1,n+1){
		v.pb(i);
	}
	int dia = (levs - 1) * 2 + 1;
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	auto dist=uniform_int_distribution<int>(1,n);
	while(1){
		int x = dist(rng), y = dist(rng);
		if(x == y) continue;
		if(dis(x,y) == dia){
			v = on_path;
			for(int z:v){
				if(dis(x,z) == levs){
					cout << "! " << z << endl;
					return;
				}
			}
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