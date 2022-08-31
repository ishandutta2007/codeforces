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

const int N=1e6+5;

#define LSB(i) ((i) & -(i))
const int maxn=N;
struct fenwick{
	int A[maxn];
	int query(int i){
		return A[i];
	}
	void update(int i, int k){
		A[i] += k;
	}
	void rupd(int l,int r,int v){
		update(l,v);
		update(r+1,-v);
	}
	void prepare(){
		for(int i = 1; i < maxn; i++){
			A[i] += A[i-1];
		}
	}
}fenw;

void solve(){
	int n,w;
	cin >> n >> w;
	
	rep(i,0,n){
		int l;
		cin >> l;
		vector<int> a(l+2);
		rep(i,1,l+1){
			cin >> a[i];
		}
		if(l == w){
			rep(i,1,w+1){
				fenw.rupd(i,i,a[i]);
			}
			continue;
		}
		if(l >= w - l){
			// mx of the last (w - l + 1) elements
			a.resize(w + 2);
			int e = (w - l + 1);
			deque<int> d;
			d.pb(0);
			rep(i,1,w+1){
				while(!d.empty() && d.back() < a[i]){
					d.ppb();
				}
				d.pb(a[i]);
				if(i >= e){
					if(d.front() == a[i-e]) d.ppf();
				}
				int mx = d.front();
				fenw.rupd(i,i,mx);
			}
		}
		else{
			// range update in the middle (l+1,w-l)
			int mx = 0;
			rep(i,1,l+1) amax(mx,a[i]);
			fenw.rupd(l+1,w-l,mx);
			mx = 0;
			rep(i,1,l+1){
				amax(mx,a[i]);
				fenw.rupd(i,i,mx);
			}
			mx = 0;
			for(int i = l; i > 0; i--){
				int j = w + i - l;
				amax(mx,a[i]);
				fenw.rupd(j,j,mx);
			}
		}
	}
	fenw.prepare();
	rep(i,1,w+1){
		cout << fenw.query(i) << " ";
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