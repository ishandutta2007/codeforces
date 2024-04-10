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

const int N=1e6+1;

int t;
int mx;
int a[N];

int n,m,x,y;

void check(){
	if(x < 1 || y < 1 || x > n || y > m){
		// cout << "\n" << n << " " << m << " " << x << " " << y << "\n";
		return;
	}
	vector<int> cnt(mx+1);
	rep(i,1,n+1){
		rep(j,1,m+1){
			int dis = abs(i - x) + abs(j - y);
			if(dis > mx){
				return;
			}
			cnt[dis]++;
		}
	}
	rep(i,0,mx+1){
		if(cnt[i] != a[i]){
			return;
		}
	}
	cout << n << " " << m << "\n" << x << " " << y;
	exit(0);
}

void solve(){
	cin >> t;
	rep(i,0,t){
		int x;
		cin >> x;
		a[x]++;
		amax(mx,x);
	}
	
	if(a[0] != 1){
		cout << -1;
		return;
	}
	
	if(t == 1){
		cout << "1 1\n1 1";
		return;
	}
	
	int w = 1;
	while(a[w] == 4 * w){
		w++;
	}
	
	int dis,tmp;
	x = w;
	
	for(int i = 1; i * i <= t; i++){
		if(t % i) continue;
		n = i;
		m = t / i;
		
		dis = n + m - 2 - mx;
		tmp = dis - (x - 1);
		y = tmp + 1;
		check();
		
		swap(n,m);
		
		dis = n + m - 2 - mx;
		tmp = dis - (x - 1);
		y = tmp + 1;
		check();
	}
	
	cout << -1;
	return;	
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
	// cin>>t;
	while(t--) solve();
	return 0;
}