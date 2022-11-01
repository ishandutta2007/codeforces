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


#define M (1<<19)
int d[2*M];

void czysc()
{
    memset(d,0,sizeof(d));
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
    int mx=0;
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

namespace d2 {
#define INF 2000000003

int d[2*M];
int mx[2*M];
int aa,bb,vv;

void czysc()
{
    FOR(i,2*M) d[i]=0;
    FOR(i,2*M) mx[i]=0;
}

void dodp(int l,int p,int nr)
{
    if (p<aa || l>bb) return;
    if (aa<=l && p<=bb) d[nr]+=vv;
    else
    {
        dodp(l,(l+p)/2,nr*2);
        dodp((l+p)/2+1,p,nr*2+1);
    }
    mx[nr]=(l==p?d[nr]:d[nr]+max(mx[nr*2],mx[nr*2+1]));
}

void dod(int a,int b,int val)//dodaje do wszystkich z [a,b] wartosc val
{
    aa=a;bb=b;vv=val;
    dodp(0,M-1,1);
}

int wezmaxp(int l,int p,int nr)
{
    if (p<aa || l>bb) return -INF;
    if (aa<=l && p<=bb) return mx[nr];
    return d[nr]+max(wezmaxp(l,(l+p)/2,nr*2),wezmaxp((l+p)/2+1,p,nr*2+1));
}

int wezmax(int a,int b)//max prz. [a,b]
{
    aa=a;bb=b;
    return wezmaxp(0,M-1,1);
}
}


int p[1<<20], rp[1<<20];
int q[1<<20], rq[1<<20];
	
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);
	int n;cin>>n;
	FOR(i,n) {cin>>p[i];p[i]--;}
	FOR(i,n) {cin>>q[i];q[i]--;}
	FOR(i,n)rp[p[i]]=i;
	FOR(i,n) ustaw(i,p[i]);
	
	FOR(i,n) {
		cout<<wezmax(0,n-1)+1<<" ";
		d2::dod(q[i],n-1,1);
		int lo=-1,hi=n-1,mid;
		while(hi-lo>1) {
			mid=(hi+lo)/2;
			//debug()<<imie(mid)<<imie(d2::wezmax(0,mid));
			if (d2::wezmax(0,mid)>0)
				hi=mid;
			else lo=mid;
		}
		//debug()<<imie(d2::wezmax(0,1));
		//debug()<<imie(d2::wezmax(0,2));
		//debug()<<imie(d2::wezmax(0,3));
		//debug()<<imie(d2::wezmax(0,4));
		//debug()<<imie(i)<<imie(q[i])<<imie(hi);
		int wm=wezmax(0,hi);
		int z=rp[wm];
		//debug()<<imie(wm)<<imie(z);
		ustaw(z,-1);
		d2::dod(z,n-1,-1);
	}


    return 0;
}