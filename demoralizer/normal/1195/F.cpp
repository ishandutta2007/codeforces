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

const int N=1e5+5;

void reduce(pii &x){
	int g = __gcd(abs(x.fr),abs(x.sc));
	x.fr /= g;
	x.sc /= g;
}

#define LSB(i) ((i) & -(i))
const int maxn=N;
struct fenwick{
	int A[maxn];
	int query(int i){
		i++;
		int sum = 0;
		while (i > 0) 
			sum += A[i], i -= LSB(i);
		return sum;
	}
	void update(int i, int k){
		i++;
		if(i<1)return;
		while (i < maxn) 
			A[i] += k, i += LSB(i);
	}
	int rquery(int l,int r){
		return query(r) - query(l - 1);
	}
}fenw;

void solve(){
	int n;
	cin >> n;
	vector<vector<pii>> s(n);
	rep(j,0,n){
		int k;
		cin >> k;
		vector<pii> v;
		rep(i,0,k){
			int x,y;
			cin >> x >> y;
			v.pb({x,y});
		}
		v.pb(v[0]);
		rep(i,1,k+1){
			int x = v[i].fr - v[i-1].fr;
			int y = v[i].sc - v[i-1].sc;
			pii z = {x,y};
			reduce(z);
			s[j].pb(z);
		}
	}
	
	map<pii, int> last;
	int q;
	cin >> q;
	vector<int> ans(q);
	vector<vector<pii>> queries(n);
	rep(i,0,q){
		int l,r;
		cin >> l >> r;
		r--; l--;
		queries[r].pb({l,i});
	}
	
	rep(i,0,n){
		for(auto x:s[i]){
			if(last.count(x)){
				fenw.update(last[x],-1);
			}
			fenw.update(i,1);
			last[x] = i;
		}
		for(auto q:queries[i]){
			int r = i, l = q.fr, id = q.sc;
			ans[id] = fenw.rquery(l,r);
		}
	}
	
	for(int x:ans){
		cout << x << "\n";
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