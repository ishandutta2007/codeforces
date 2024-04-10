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
 
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const int MOD=1e9+7;//998244353;

#define NODE 3000000
#define EDGE 3000000

int a[EDGE],b[EDGE];
bool uz[EDGE];
int roz[NODE];
vi kr[NODE];
bool odw[NODE];
int akt;
int N;
vector<pii> tour;

vi spec[1<<21];

void dod_kr(int x,int y)
{
    a[akt]=x;
    b[akt]=y;
    uz[akt]=0;
    kr[x].pb(akt);
    kr[y].pb(akt);
    akt++;
}

void czysc(int _N)
{
    N=_N;
    FOR(i,N) kr[i].clear();
    FOR(i,N) roz[i]=0;
    akt=0;
}

void dfs(int u,int par)
{
    //DBG(u);
    while(roz[u]<SZ(kr[u]))
    {
        //DBG(roz[u]);
        //DBG(kr[u]);
        int r=roz[u];
        roz[u]++;
        if (!uz[kr[u][r]])
        {
            uz[kr[u][r]]=1;
            if (a[kr[u][r]]==u) dfs(b[kr[u][r]],u);
            else dfs(a[kr[u][r]],u);
        }
    }
    if (par!=-1)
    tour.pb(mp(par,u));
}

void spojny(int u)
{
    odw[u]=1;
    FOR(i,SZ(kr[u]))
    {
        int z=(a[kr[u][i]]==u?b[kr[u][i]]:a[kr[u][i]]);
        if (!odw[z]) spojny(z);
    }
}

vector<pii> get_tour(int u)//jesli istnieje to zwraca ciag krawedzi, jesli nie to pusty
{
    tour.clear();
    FOR(i,N) if (SZ(kr[i])%2) return tour;
    FOR(i,N) odw[i]=0;
    spojny(u);
    FOR(i,N) if (SZ(kr[i]) && !odw[i]) return tour;
    dfs(u,-1);
    reverse(ALL(tour));
    return tour;
}

int col[1<<20][2];
int c[1<<21];

int p[1<<21];
int szuk(int x){if (x==p[x]) return x;return p[x]=szuk(p[x]);}
inline void unia(int x,int y){p[szuk(x)]=szuk(y);}

	
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);
	int n;cin>>n;
	FOR(i,n) cin>>col[i][0]>>col[i][1];
	
	int lo=0,hi=21,mid;
	while(hi-lo>1) {
		mid=(hi+lo)/2;
		FOR(i,(1<<mid))  c[i]=0;
		
		bool ok=1;
		int msk = (1<<mid)-1;
		
		FOR(i,n) c[col[i][0]&msk]++;
		FOR(i,n) c[col[i][1]&msk]++;
		int ce = col[0][0]&msk;
		
		FOR(i,(1<<mid)) if (c[i]%2) {ok=0;break;}
		if (ok) {
			FOR(i,(1<<mid)) p[i]=i;
			FOR(i,n) unia(col[i][0]&msk,col[i][1]&msk);
			FOR(i,(1<<mid)) if (c[i] && szuk(i)!=szuk(ce)) ok=0;
		}
		if (ok) lo=mid;
		else hi=mid;
	}
	
	
	int B = lo;
	cout<<B<<"\n";
	int msk = (1<<B)-1;
	set<pair<pii,int> > s;
	int u=0;
	int non_spe=0;
	FOR(i,n) {
		int a0=col[i][0]&msk;
		int a1=col[i][1]&msk;
		u=a0;
		if (a0==a1) {
			spec[a0].pb(i);continue;
		}
		non_spe++;
		dod_kr(a0,a1);
		s.insert({{a0,a1},i});
	}
	if (non_spe) {
		auto v = get_tour(u);
		FOR(j, SZ(v)) {
			int a0=v[j].st,a1=v[j].nd;
			while(SZ(spec[a0])) {
				int ii=spec[a0].back();
				spec[a0].pop_back();
				cout<<2*ii+1<<" "<<2*ii+2<<" ";
			}
			int ind;
			int swp=0;
			auto it = s.lower_bound({{a0,a1},0});
			if (it!=s.end() && (*it).st == mp(a0,a1)) {
				ind = (*it).nd;
				s.erase(it);
			} else {
				swap(a0,a1);
				it = s.lower_bound({{a0,a1},0});
				ind = (*it).nd;
				swp=1;
				s.erase(it);
			}
			if (!swp) cout<<2*ind+1<<" "<<2*ind+2<<" ";
			else cout<<2*ind+2<<" "<<2*ind+1<<" ";
			
			while(SZ(spec[a1])) {
				int ii=spec[a1].back();
				spec[a1].pop_back();
				cout<<2*ii+1<<" "<<2*ii+2<<" ";
			}
		}
	} else {
		FOR(ind,n) cout<<2*ind+1<<" "<<2*ind+2<<" ";
	}
	
	


    return 0;
}