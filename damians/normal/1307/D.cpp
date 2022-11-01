//#pragma comment(linker, "/stack:200000000")
#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

 
using namespace __gnu_pbds;
using namespace std;
 
template <typename T>
using ordered_set =
	tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define un(x) x.erase(unique(ALL(x)),x.end())
#define REP(i,x,v)for(int i=x;i<=v;i++)
#define REPD(i,x,v)for(int i=x;i>=v;i--)
#define FOR(i,v)for(int i=0;i<v;i++)
#define TRAV(i,v)for(auto &i:(v))
 
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const int MOD=1e9+7;//998244353;
int n;
#define INF (1<<20)
vi kr[1<<20];
vi bfs(int u) {
	deque<int> Q;
	vi d(n,INF);
	d[u]=0;
	Q.push_back(u);
	while(SZ(Q)) {
		int v=Q.front();Q.pop_front();
		for(auto w:kr[v]) {
			if (d[w]<INF) continue;
			d[w]=d[v]+1;
			Q.push_back(w);
		}
	}
	return d;
}

int A[1<<20];
vi x,y;

int maxx[1<<20];


#define M (1<<18)
int d[2*M];

void czysc()
{
    memset(d,0,sizeof(d));
    FOR(i,2*M) d[i]=-INF;
}

void ustaw(int pos,int war)
{
    pos+=M;
    d[pos]=war;
    pos/=2;
    while(pos>0)
    {
        d[pos]=max(d[pos*2],d[pos*2+1]);
        pos/=2;
    }
}


int wezmax(int a,int b)
{
    int mx=-INF;
    a+=M;
    b+=M;
    while(a<b)
    {
        if (a&1) mx=max(mx,d[a++]);
        if (!(b&1)) mx=max(mx,d[b--]);
        a>>=1;
        b>>=1;
    }
    if (a==b) mx=max(mx,d[a]);
    return mx;
}
	
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);
	int m,k;cin>>n>>m>>k;
	FOR(i,k) cin>>A[i];
	FOR(i,k) A[i]--;
	FOR(i,m) {
		int a,b;cin>>a>>b;a--;b--;
		kr[a].pb(b);
		kr[b].pb(a);
	}
	x=bfs(0);
	y=bfs(n-1);
	int lo=0,hi=n,mid;
	FOR(i,n+1) maxx[i]=-INF;
	
	FOR(i,k) maxx[y[A[i]]]=max(maxx[y[A[i]]],x[A[i]]);
	FOR(i,k) debug()<<imie(y[A[i]])<<imie(x[A[i]]);
	REPD(i,n-1,0) maxx[i]=max(maxx[i],maxx[i+1]);
	while(hi-lo>1) {
		mid=(hi+lo)/2;
		bool ok=0;
		czysc();
		for(int i=0;i<k;i++) {
			if (wezmax(max(0,mid-x[A[i]]),M-1) +y[A[i]]>=mid) ok=1;
			if (d[M+y[A[i]]]<=x[A[i]]) ustaw(y[A[i]],x[A[i]]);
		}
		if (ok) lo=mid;
		else hi=mid;
			
	}
	debug()<<imie(x[n-1])<<imie(lo);
	cout<<min(x[n-1],lo+1)<<endl;;
	
	


    return 0;
}