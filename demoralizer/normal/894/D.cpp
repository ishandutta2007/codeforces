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

int sa[N];
int sh[N];
int l[N];
int ans[N];


int val[N];
int curval[N];
int totval[N];

void solve(){
	int n,m;
	cin >> n >> m;
	rep(i,1,n){
		cin >> l[i];
	}
	
	val[1] = 0;
	
	rep(i,2,n+1){
		val[i] = val[i/2] + l[i-1];
	}
	
	
	vector<array<int,5>> q; // {val,ver,quer,mul}
	
	rep(i,0,m){
		int a,h;
		cin >> a >> h;
		sa[i] = a;
		sh[i] = h;
		int orga = a;
		// par = ver / 2
		// wt = l[ver - 1]
		q.pb({h + val[a],a,i,1,a});
		while(a != 1){
			int par = a / 2;
			q.pb({h + 2 * val[par] - val[orga],par,i,1,par});
			q.pb({h + 2 * val[par] - val[orga],a,i,-1,par});
			
			a = par;
		}
	}
	
	sort(all(q),[&](array<int,5> &a,array<int,5> &b){
		return a[0] < b[0];
	});
	
	
	vector<pii> vals;
	rep(i,1,n+1){
		vals.pb({val[i],i});
	}
	sort(all(vals));
	
	
	int qp = 0;
	
	
	for(auto x:vals){
		while(qp < sz(q) && q[qp][0] <= x.fr){
			int ver = q[qp][1];
			int quer = q[qp][2];
			int mul = q[qp][3];
			int lca = q[qp][4];
			int tmp = curval[ver] * (val[sa[quer]] - 2 * val[lca]) + totval[ver];
			tmp = curval[ver] * sh[quer] - tmp;
			ans[quer] += mul * tmp;
			qp++;
		}
		int ver = x.sc;
		while(ver){
			curval[ver]++;
			totval[ver] += val[x.sc];
			ver = ver / 2;
		}
		
	}
	while(qp < sz(q)){
		int ver = q[qp][1];
		int quer = q[qp][2];
		int mul = q[qp][3];
		int lca = q[qp][4];
		int tmp = curval[ver] * (val[sa[quer]] - 2 * val[lca]) + totval[ver];
		tmp = curval[ver] * sh[quer] - tmp;
		ans[quer] += mul * tmp;
		qp++;
	}
	
	
	rep(i,0,m){
		cout << ans[i] << "\n";
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