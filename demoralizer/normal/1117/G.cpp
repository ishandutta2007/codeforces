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

int p[N];
int ans[N];
int l[N], r[N];
int lef[N], rig[N];

#define LSB(i) ((i) & -(i))
const int maxn=N;
struct fenwick{
	int A[maxn];
	int query(int i){
		int sum = 0;
		while (i > 0) 
			sum += A[i], i -= LSB(i);
		return sum;
	}
	void update(int i, int k){
		if(i<1)return;
		while (i < maxn) 
			A[i] += k, i += LSB(i);
	}
	int rquery(int l,int r){
		return query(r) - query(l - 1);
	}
	void clear(){
		mem0(A);
	}
}fsum,fcnt;

void solve(){
	int n,q;
	cin >> n >> q;
	rep(i,1,n+1){
		cin >> p[i];
	}
	
	p[0] = p[n+1] = INF;
	p[0]++;
	vector<int> stk(1);
	rep(i,1,n+2){
		while(p[stk.back()] < p[i]){
			rig[stk.back()] = i - 1;
			stk.ppb();
		}
		lef[i] = stk.back() + 1;
		stk.pb(i);
	}
	
	vector<array<int,3>> rs,ls;
	
	rep(i,0,q){
		cin >> l[i];
	}
	rep(i,0,q){
		cin >> r[i];
		
		ans[i] = (r[i] - l[i] + 1);
		// l[i],r[i] -> add to range (l,r):
		// rig - lef + 1
		// sum(rig) - sum(lef) + (r - l + 1)
		// sum(rig) = [l,r]
		rs.pb({r[i],l[i],i});
		ls.pb({l[i],r[i],i}); 
	}
	
	// rs -> in range 1,0: add rig less than 0 plus cnt * 0
	vector<pii> vals;
	rep(i,1,n+1){
		vals.pb({rig[i],i});
	}
	sort(all(vals));
	reverse(all(vals));
	sort(all(rs));
	for(auto x:rs){
		int r = x[0], l = x[1], i = x[2];
		while(sz(vals) && vals.back().fr <= r){
			fsum.update(vals.back().sc, vals.back().fr);
			fcnt.update(vals.back().sc, 1);
			vals.ppb();
		}
		
		ans[i] += fsum.rquery(l,r);
		ans[i] += r * (r-l+1 - fcnt.rquery(l,r));
	}
	
	
	// ls -> in range 0,1: add lef gr than 0 plus cnt * 0
	fsum.clear();
	fcnt.clear();
	vals.clear();
	rep(i,1,n+1){
		vals.pb({lef[i],i});
	}
	sort(all(vals));
	sort(all(ls));
	reverse(all(ls));
	for(auto x:ls){
		int l = x[0], r = x[1], i = x[2];
		while(sz(vals) && vals.back().fr >= l){
			fsum.update(vals.back().sc, vals.back().fr);
			fcnt.update(vals.back().sc, 1);
			vals.ppb();
		}
		
		ans[i] -= fsum.rquery(l,r);
		ans[i] -= l * (r-l+1 - fcnt.rquery(l,r));
	}
	
	
	rep(i,0,q){
		cout << ans[i] << " ";
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