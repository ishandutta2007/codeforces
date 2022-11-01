//#pragma comment(linker, "/stack:200000000")
#define LOCAL1
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
#define maxk 5000

bool is_prime(ll x)
{
    if (x<2) return 0;
    for(int j=2;(ll)j*j<=x;j++) if (x%j==0) return 0;
    return 1;
}

vi fact[maxk+1];
int cnt[maxk+1];
int agree[maxk+1];


int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);

	int n;cin>>n;
	FOR(i,n)
	{
	    int x;cin>>x;
	    if (!x) x++;
	    cnt[x]++;
	}
	int tot=0;
	ll curr=0;
    REP(k,1,maxk){
        REPD(p,maxk,2){
            if (is_prime(p)){
                int ppow=p;
                int sum=0;
                while(ppow<=maxk){
                    sum+=k/ppow;
                    ppow*=p;
                }
                FOR(i,sum)fact[k].pb(p);
            }
        }
        tot+=SZ(fact[k]);
        curr+=SZ(fact[k])*1LL*cnt[k];
    }
    ll best=curr;
    REP(j,1,maxk) agree[j]=1;
    int j=0;
    while(1)
    {
        int mx=-1;
        int pmx=-1;
        vi pcnt(maxk+1,0);
        ll disagree=0;
        REP(k,1,maxk)
        {
            if (j>=SZ(fact[k])) agree[k]=0;
            if (agree[k])
            {
                pcnt[fact[k][j]]+=cnt[k];
            }
            else disagree+=cnt[k];
        }
        debug()<<imie(disagree)<<imie(j);

        REP(p,1,maxk)
        {
            if (pcnt[p]) debug()<<imie(p)<<imie(pcnt[p]);
            if (pcnt[p]>mx) {mx=pcnt[p];pmx=p;}
        }
        REP(k,1,maxk) if (agree[k] && fact[k][j]!=pmx) {agree[k]=0;disagree+=cnt[k];}
        debug()<<imie(pmx)<<imie(mx);
        if (mx<=disagree)
        {
            break;
        }
        debug()<<imie(curr);
        curr=curr-mx+disagree;
        debug()<<imie(curr);
        best=curr;
        j++;
    }
    cout<<best;


    return 0;
}