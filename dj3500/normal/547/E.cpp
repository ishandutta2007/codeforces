// tested by Hightail: https://github.com/dj3500/hightail
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <stack>
#include <cstring>
#include <iomanip>
#include <ctime>
#include <cassert>
using namespace std;
#define pb push_back
#define INF 1001001001
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define SZ(x) ((int)((x).size()))
#define fi first
#define se second
#define wez(n) int (n); scanf("%d",&(n));
#define wez2(n,m) int (n),(m); scanf("%d %d",&(n),&(m));
#define wez3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k));
inline void pisz(int n) { printf("%d\n",n); }
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){FOR(i,SZ(t))s<<t[i]<<" ";return s; }
#define DBG(vari) //cout<<"["<<__LINE__<<"] "<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (__typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

namespace SA {
#define MAXN 1000007
int temp[MAXN], s0[MAXN], s12[MAXN], rnk[MAXN], recOut[MAXN], c[MAXN], sa[MAXN], arr[MAXN], lcp[MAXN], n, *_s;
void countSort(int* in, int* out, int* key, int N, int M) {
   fill_n(c, M, 0);
   FOR(i,N) ++c[key[in[i]]];
   REP(i,1,M-1) c[i] += c[i-1];
   REPD(i,N-1,0) out[--c[key[in[i]]]] = in[i];
}

inline bool cmp(int u, int v) {
   while(1) {
      if (_s[u] != _s[v]) return _s[u] < _s[v];
      if ((u%3) && (v%3)) return rnk[u] < rnk[v];
      ++u; ++v;
   }
}

void suffixArray(int* s, int N, int* out, int K) {
   int n0 = (N+2)/3, n1 = (N+1)/3, n12 = 0;
   FOR(i,N) if (i%3) temp[n12++] = i;

   countSort(temp, s12, s+2, n12, K);
   countSort(s12, temp, s+1, n12, K);
   countSort(temp, s12, s,   n12, K);

   int cnt = 2, *recIn = new int[n12 + 5];
   FOR(i,n12) {
      if (i>0 && !equal(s+s12[i-1], s+s12[i-1]+3, s+s12[i])) ++cnt;
      recIn[s12[i]%3==1 ? s12[i]/3 : s12[i]/3+n1+1] = cnt;
   }

   if (cnt != n12+1) {
      FOR(i,3) recIn[n12+1+i] = 0;
      recIn[n1] = 1;
      suffixArray(recIn, n12+1, recOut, cnt+1);
      FORI(i,n12) s12[i-1] = recOut[i]<n1? 3*recOut[i]+1 : 3*(recOut[i]-n1)-1;
   }
   delete [] recIn;

   FOR(i,n12) rnk[s12[i]] = i+1;
   rnk[N] = 0;

   FOR(i,n0) s0[i] = 3*i;
   countSort(s0,temp,rnk+1,n0,n12+2);
   countSort(temp,s0,s,n0,K);

   _s = s;
   merge(s12, s12+n12, s0, s0+n0, out, cmp);
}

void init (const vi &t) {
   n = SZ(t);
   if (n <= 1) sa[0] = 0; else {
      FOR(i,n) arr[i] = t[i];
      arr[n] = arr[n+1] = arr[n+2] = 0;
      suffixArray(arr, n, sa, *max_element(arr,arr+n)+1);
   }
   FOR(i,n) rnk[sa[i]] = i; // "rnk" changes meaning now
   // Kasai
   for (int i = 0, k = 0; i < n; i++) {
      if (k > 0) k--;
      if (rnk[i] == n-1) { lcp[n-1] = -1; k = 0; continue; }
      int j = sa[rnk[i]+1];
      while (t[i+k] == t[j+k]) k++;
      lcp[rnk[i]] = k;
   }
}
};

const int LOGN = 20, N = 1<<LOGN; // mozna zmniejszyc N
int rm[LOGN][N]; // rm[k][i] = min(tab[i], ..., tab[i + 2^k - 1])
void init (int *tab, int n) { // tab[0..n-1]
   FOR(i,n) rm[0][i] = tab[i];
   REP(k,1,LOGN-1) REP(i,0,n-(1<<k)) rm[k][i] = min(rm[k-1][i], rm[k-1][i+(1<<(k-1))]);
}
int query (int a, int b) { // a <= b bo inaczej segfault
   int k = 31 - __builtin_clz(b-a+1);
   return min(rm[k][a], rm[k][b-(1<<k)+1]);
}

// zwraca przedzia w tablicy sufiksowej ktory odpowiada
// sufiksom rozpoczynajcym si od substringa s[k .. k+len-1]
pii getSubstringsInterval (int k, int len) {
    int B = SA::rnk[k], A = B, from = 0, to = B-1;
    while (from <= to) {
        int mid = (from + to) / 2;
        if (query(mid, B-1) >= len) {
            A = mid;
            to = mid-1;
        } else {
            from = mid+1;
        }
    }
    from = B+1, to = SA::n-1;
    while (from <= to) {
        int mid = (from + to) / 2;
        if (query(A, mid-1) >= len) {
            B = mid;
            from = mid+1;
        } else {
            to = mid-1;
        }
    }
    return mp(A,B);
}

struct tree {
   int sz;
   vector<vi> V;

   // val[0..n-1]: wektor wartosci
   tree(const vi &val) {
      int n = SZ(val);
      for (sz = 1; sz < n; sz *= 2);
      V.assign(2*sz, vi());
      FOR(i,n)	V[sz+i].pb(val[i]);
      REPD(i,sz-1,1)	{
         V[i].resize(SZ(V[2*i]) + SZ(V[2*i+1]));
         merge(ALL(V[2*i]), ALL(V[2*i+1]), V[i].begin());
      }
   }

   // policz ile jest i in [b,e] tze val[i] <= x
   // precondition: 0 <= b <= e < n
   int query(int b, int e, int x) {
      return _get(sz+b, sz+e+1, x);
   }

   int ile(int v, int x) {
      return upper_bound(ALL(V[v]), x) - V[v].begin();
   }

   int _get(int p, int q, int x) {
      if (p + 1 == q) return ile(p, x);
      if (p&1) return ile(p, x) + _get(p+1, q, x);
      if (q&1) return ile(q-1, x) + _get(p, q-1, x);
      return _get(p/2, q/2, x);
   }
};

string s[N];
int startpos[N], posfrom[N];
char temp[N];

int main () {
    wez2(n,Q)
    FORI(i,n) {
        scanf("%s", temp);
        s[i] = temp;
    }
    vi t;
    t.pb(256);
    FORI(i,n) {
        startpos[i] = SZ(t);
        FOREACH(w,s[i]) {
            posfrom[SZ(t)] = i;
            t.pb(*w);
        }
        t.pb(256 + i);
    }

    SA::init(t);
    init(SA::lcp, SZ(t));

    vi val(SZ(t), 0);
    FOR(i,SZ(t)) val[i] = posfrom[SA::sa[i]];
    tree kri(val);

    FORI(q,Q) {
        wez3(l,r,k)
        pii AB = getSubstringsInterval(startpos[k], SZ(s[k]));
        pisz(kri.query(AB.fi,AB.se,r) - kri.query(AB.fi,AB.se,l-1)); // [A,B] x [l,r]
    }
}