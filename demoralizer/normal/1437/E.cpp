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

const int N=5e5+5;

#define LSB(i) ((i) & -(i))
const int maxn=N;
struct fenwick{
	int A[maxn];
	int query(int i){
		int sum = 0;
		while (i > 0) 
			amax(sum, A[i]), i -= LSB(i);
		return sum;
	}
	void update(int i, int k){
		if(i<1)return;
		while (i < maxn) 
			amax(A[i], k), i += LSB(i);
	}
	void rupd(int l,int r,int v){
		update(l,v);
		update(r+1,-v);
	}
}fenw;

void solve(){
	int n,k;
	cin >> n >> k;
	vector<int> a(n),b(n);
	set<int> co;
	map<int, int> cocom;
	int cocnt = 1;
	rep(i,0,n){
		cin >> a[i];
		a[i] -= i;
		co.insert(a[i]);
	}
	for(int x: co){
		cocom[x] = cocnt++;
	}
	rep(i,0,n){
		a[i] = cocom[a[i]];
	}
	
	rep(i,0,k){
		int x;
		cin >> x;
		x--;
		b[x] = 1;
	}
	
	rep(i,0,n){
		int tmp = fenw.query(a[i]);
		if(b[i]) tmp += n;
		else tmp++;
		fenw.update(a[i],tmp);
	}
	
	int ans = fenw.query(N - 2);
	
	if(ans < k * n){
		cout << -1;
		return;
	}
	
	ans -= k * n;
	ans += k;
	cout << n - ans;
	
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