#include "bits/stdc++.h"
using namespace std;
// #define int               long long
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


#define left LeFt
#define right RiGhT

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=2e5+5;

// 87 onwards

#define SIEVE
int primes[N];
vector<int> pr;
void sieve(){
	for(int i=2;i<N;i++){
		if(primes[i]==0){
			pr.pb(i);
			if(i < 500)
			for(int j=i*i;j<N;j+=i){
				primes[j]=1;
			}
		}
		primes[i]^=1;
	}
}

int pw(int a,int p=M-2,int MOD=M){
	int result = 1;
	while (p > 0) {
		if (p & 1)
			result = 1LL * a * result % MOD;
		a = 1LL * a * a % MOD;
		p >>= 1;
	}
	return result;
}

const int maxn = 1e5+5;

int a[25*N],left[25*N],right[25*N];
int cur = 1;
int update(int pos,int val,int root = 0,int tl = 0,int tr = maxn-1){
	if(tl == tr){
		a[cur] = val;
		return cur++;
	}
	int tm = (tl + tr) / 2;
	int tmp = cur++;
	left[tmp] = left[root];
	right[tmp] = right[root];
	if(pos > tm)
		right[tmp] = update(pos,val,right[root],tm+1,tr);
	else
		left[tmp] = update(pos,val,left[root],tl,tm);
	a[tmp] = 1LL * a[left[tmp]] * a[right[tmp]] % M;
	return tmp;
}

int query(int l,int r,int root,int tl = 0,int tr = maxn-1){
	if(tl >= l && tr <= r){
		return a[root];
	}
	if(tl > r || tr < l){
		return 1;
	}
	int tm = (tl + tr) / 2;
	return 1LL * query(l,r,left[root],tl,tm) * query(l,r,right[root],tm+1,tr) % M;
}



int ver[maxn];
int last[N];



array<int,87> st[4*maxn];
array<int,87> inp[maxn];

array<int,87> comb(array<int,87> x,array<int,87> y){
	array<int,87> z;
	rep(i,0,87) z[i] = max(y[i],x[i]);
	return z;
}

void build(int v = 1,int tl = 0,int tr = maxn-1){
	if(tl == tr){
		st[v] = inp[tl];
		return;
	}
	int tm = (tl + tr) / 2;
	build(2*v,tl,tm);
	build(2*v+1,tm+1,tr);
	st[v] = comb(st[2*v],st[2*v+1]);
}

array<int,87> stquery(int l,int r,int v = 1,int tl = 0,int tr = maxn-1){
	if(tl >= l && tr <= r){
		return st[v];
	}
	if(tl > r || tr < l) return {};
	int tm = (tl + tr) / 2;
	return comb(stquery(l,r,2*v,tl,tm),stquery(l,r,2*v+1,tm+1,tr));
}


void solve(){
	int n;
	cin >> n;
	rep(i,1,n+1){
		int x;
		cin >> x;
		rep(j,0,87){
			int p = pr[j];
			int cnt = 0;
			while(x % p == 0){
				x /= p;
				cnt++;
			}
			inp[i][j] = cnt;
		}
		ver[i] = update(last[x],1,ver[i-1]);
		ver[i] = update(i,x,ver[i]);
		last[x] = i;
	}
	
	build();
	
	int q;
	cin >> q;
	
	int ans = 0;
	
	while(q--){
		int x,y;
		cin >> x >> y;
		int l = (ans + x) % n + 1;
		int r = (ans + y) % n + 1;
		if(l > r) swap(l,r);
		ans = query(l,r,ver[r]);
		array<int,87> tmp = stquery(l,r);
		rep(i,0,87) ans = 1LL * ans * pw(pr[i],tmp[i]) % M;
		cout << ans << endl;
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