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

int query(int t,int i,int j,int k){
	cout << t << " " << i << " " << j << " " << k << endl;
	int val;
	cin >> val;
	return val;
}

int dis[N];

void solve(){
	int n;
	cin >> n;
	
	int best = 2;
	rep(i,3,n+1){
		if(query(2,1,best,i) > 0){
			best = i;
		}
	}
	
	rep(i,2,n+1){
		if(i == best){
			continue;
		}
		dis[i] = query(1,1,best,i);
	}
	
	int far = 2;
	rep(i,2,n+1){
		if(dis[far] < dis[i]){
			far = i;
		}
	}
	
	vector<int> left, right;
	rep(i,2,n+1){
		if(i == far) continue;
		if(query(2,1,far,i) > 0){
			left.pb(i);
		}
		else{
			right.pb(i);
		}
	}
	
	sort(all(left),[&](int a,int b){
		return dis[a] > dis[b];
	});
	sort(all(right),[&](int a,int b){
		return dis[a] < dis[b];
	});
	
	cout << "0 1 ";
	for(int x:right){
		cout << x << " ";
	}
	
	cout << far << " ";
	
	for(int x:left){
		cout << x << " ";
	}
	cout << endl;
	
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