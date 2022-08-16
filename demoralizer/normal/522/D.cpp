#include <bits/stdc++.h>
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

map<int, vector<int>> v;
int a[N],b[N];

#define LSB(i) ((i) & -(i))
const int maxn=N;
struct fenwick{
	int A[maxn];
	fenwick(){
		rep(i,0,maxn){
			A[i] = INF;
		}
	}
	int query(int i){
		int sum = INF;
		while (i > 0) 
			amin(sum , A[i]), i -= LSB(i);
		return sum;
	}
	void update(int i, int k){
		while (i < maxn) 
			amin(A[i] , k), i += LSB(i);
	}
}fenw;

int ans[N];

struct query{
	int l,r,id;
	query(int l,int r,int id):l(l),r(r),id(id){}
};

vector<query> q[N];

void solve(){
	int n,m;
	cin>>n>>m;
	rep(i,1,n+1){
		cin>>a[i];
		v[a[i]].pb(i);
	}
	rep(i,1,n+1){
		auto it = upper_bound(all(v[a[i]]),i);
		if(it == v[a[i]].end()){
			b[i] = INF;
		}
		else{
			b[i] = *it;
		}
	}
	rep(i,0,m){
		int l,r;
		cin>>l>>r;
		q[l].pb({l,r,i});
	}
	
	for(int i=n;i>0;i--){
		if(b[i] <= n){
			fenw.update(b[i],b[i]-i);
		}
		for(auto x:q[i]){
			ans[x.id] = fenw.query(x.r);
		}
	}
	
	rep(i,0,m){
		cout<<(ans[i]==INF?-1:ans[i])<<"\n";
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