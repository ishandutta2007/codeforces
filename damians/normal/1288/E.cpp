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


int bit[(1<<20)+2];
int maxval=(1<<20);
// BIT obsluguje przedzial [1..maxval-1]

void czysc(int mxv)
{
    maxval=mxv;
    FOR(i,mxv+1) bit[i]=0;
}

void dodaj(int ind, int war)
{
    while(ind<maxval)
    {
        bit[ind]+=war;
        ind+=(ind & -ind);
    }
}

int suma(int ind)//[1..ind]
{
    int sm=0;
    while(ind>0)
    {
        sm+=bit[ind];
        ind-=(ind & -ind);
    }
    return sm;
}

int suma(int ind1,int ind2)
{
    return suma(ind2)-suma(ind1-1);
}

int mn[1<<20];
int mx[1<<20];
int cur[1<<20];

	
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);
	int n,m;cin>>n>>m;
	int nxt=500000;
	REP(i,1,n) {
		dodaj(nxt+i,1);
		cur[i]=nxt+i;
		mn[i]=mx[i]=i;
	}
	FOR(dsg,m) {
		int x;cin>>x;
		mn[x]=1;
		mx[x]=max(mx[x], suma(1,cur[x]));
		debug()<<imie(x)<<imie(suma(1,cur[x]))<<imie(cur[x]);
		dodaj(cur[x],-1);
		cur[x]=nxt--;
		dodaj(cur[x],1);
	}
	
	REP(x,1,n) mx[x]=max(mx[x], suma(1,cur[x]));
	
	REP(i,1,n) cout<<mn[i]<<" "<<mx[i]<<"\n";


    return 0;
}