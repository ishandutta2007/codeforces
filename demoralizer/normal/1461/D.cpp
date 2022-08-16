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

const int N=1e6+5;

int a[N];
long long f[N];
unordered_set<int> s;

void calc(int l,int r){
	if(l > r){
		return;
	}
	while(f[l] == 0 && l < r) l++;
	while(f[r] == 0 && r > l) r--;
	if(l == r){
		if(f[l] == 0) return;
		if(f[l] < M)
			s.insert(f[l]);
		return;
	}
	long long sum = 0;
	rep(i,l,r+1){
		sum += f[i];
	}
	if(sum < M)
		s.insert(sum);
	int mid = (l + r) / 2;
	calc(l,mid);
	calc(mid+1,r);
}

void solve(){
	s.clear();
	int n,q;
	cin >> n >> q;
	rep(i,0,n){
		int x;
		cin >> x;
		a[i] = x;
		f[x] += x;
	}
	
	calc(1,1e6);
	
	rep(i,0,q){
		int x;
		cin >> x;
		if(s.count(x)){
			cout << "Yes\n";
		}
		else{
			cout << "No\n";
		}
	}
	
	rep(i,0,n){
		int x = a[i];
		f[x] -= x;
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