//#pragma comment(linker, "/stack:200000000")
#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

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
#define var(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

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
#define REMIN(x,v) x=min(x,v);
#define REMAX(x,v) x=max(x,v);

mt19937_64 rng(134569);
int rd(int l, int r) {return uniform_int_distribution<int>(l, r)(rng);}

using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const int MOD=1e9+7;//998244353;


ll mpow(ll a, ll b)
{
    a=a%MOD;
    ll w=1;
    while(b)
    {
        if (b%2) w=(w*a)%MOD;
        a=(a*a)%MOD;
        b/=2;
    }
    return w;
}

ll getp2(int l) {
  if (l>=0) return mpow(2,l);
  return mpow(mpow(2,-l), MOD-2);
}

int kmp(string t, string p) {
   vi kn(SZ(p)+1,-1); // funkcja prefiksowa Knutha
   REP(i,1,SZ(p)) {
      int j = kn[i-1];
      while (j != -1 && p[j] != p[i-1]) j=kn[j];
      kn[i] = j+1;
   }

   int ans=0;
   int ppos=0,tpos=0;
   while (tpos<SZ(t)) {
      while (ppos!=-1 && (ppos == SZ(p) || p[ppos]!=t[tpos])) ppos=kn[ppos];
      ppos++;
      tpos++;
      if (ppos==SZ(p)) ans++;
   }
   return ans;
}

ll p2[(1<<20)+2];
ll p[26][111111];


int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  p2[0]=1;
  REP(i,1,(1<<20)) p2[i]=(p2[i-1]*2)%MOD;

	ios_base::sync_with_stdio(0);cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);
  int n,q;cin>>n>>q;
  string s;cin>>s;
  string t;cin>>t;
  FOR(i, SZ(t)) {
    FOR(c,26) {
      p[c][i+1]=(2*p[c][i] +(c+'a'==t[i]))%MOD;
    }
  }

  while(q--) {
    int K;cin>>K;
    string w;cin>>w;
    int k=0;
    string r=s;
    while(SZ(w)>SZ(r)) {
      if (k>=n) break;
      r=r+t.substr(k,1)+r;
      k++;
    }
    if (k>K) {
      cout<<0<<"\n";
      continue;
    }
    if (k==K) {
      cout<<kmp(r,w)<<"\n";
      continue;
    }
    r=r+t.substr(k,1)+r;
    k++;

    int center=SZ(r)/2;
    vi a(26);
    string R=r.substr(center-SZ(w)+1, 2*SZ(w)-1);
    //debug()<<var(t)<<var(r)<<var(w)<<var(R)<<var(k)<<var(K);
    FOR(c,26) {
      R[SZ(w)-1]='a'+c;
      a[c]=kmp(R,w);
    }
    //debug()<<var(a);
    ll sum=(kmp(r,w)*p2[K-k])%MOD;
    ll sum2=0;
    FOR(c,26) {
      sum2=(sum2+a[c]*(p[c][K]-p[c][k]*p2[K-k]))%MOD;
      //debug()<<var(c)<<var(p[c][K]-p[c][k]);
    }
    //debug()<<var(sum)<<var(sum2);
    //sum2=(sum2*getp2(K-k-1))%MOD;

    sum2=(sum2+MOD)%MOD;

    //sum2=(sum2*getp2(K-k-1))%MOD;
    sum=(sum+sum2)%MOD;
    cout<<sum<<"\n";
  }




    return 0;
}