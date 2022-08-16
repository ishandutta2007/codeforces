#include <bits/stdc++.h>
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
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

template<typename T,typename cmp>
struct minqueue
{
	deque<T> q;
	void clear(){
		q.clear();
	}
	void operator+= (T x){
		while(!q.empty() && cmp()(x,q.back())){
			q.ppb();
		}
		q.pb(x);
	}
	void operator-= (T x){
		if(q.front() == x)q.ppf();
	}
	T operator() (){
		return q.front();
	}
};

int a[505][505];
int b[505][505];

void solve(){
	minqueue<int,greater<int> > d;
	int n,m,q,k;
	cin>>n>>m>>k>>q;
	rep(i,0,n){
		rep(j,0,m){
			a[i][j]=INF;
		}
	}
	rep(i,0,q){
		int x,y,t;
		cin>>x>>y>>t;
		x--;
		y--;
		a[x][y]=t;
	}
		
	rep(i,0,n){
		rep(j,0,k){
			d+=(a[i][j]);
		}
		rep(j,0,m-k+1){
			b[i][j]=d();
			d-=(a[i][j]);
			d+=(a[i][j+k]);
		}
		d.clear();
	}
	
	int ans=INF;
	
	rep(j,0,m-k+1){
		rep(i,0,k){
			d+=(b[i][j]);
		}
		rep(i,0,n-k+1){
			amin(ans,d());
			d-=(b[i][j]);
			d+=(b[i+k][j]);
		}
		d.clear();
	}
	if(ans==INF)ans=-1;
	cout<<ans;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SEIVE
		seive();
	#endif
	#ifdef NCR
		init();
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}