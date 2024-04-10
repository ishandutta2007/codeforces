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
#include <climits>
#include <ctime>
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
#define IN(x,y) ((y).find((x))!=(y).end())
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

namespace karkkainen {

inline bool leq(int a1, int a2,   int b1, int b2) { // lexic. order for pairs
  return(a1 < b1 || (a1 == b1 && a2 <= b2));
}                                                   // and triples
inline bool leq(int a1, int a2, int a3,   int b1, int b2, int b3) {
  return(a1 < b1 || (a1 == b1 && leq(a2,a3, b2,b3)));
}

// stably sort a[0..n-1] to b[0..n-1] with keys in 0..K from r
static void radixPass(int* a, int* b, int* r, int n, int K) {
   // count occurrences
   vi c(K+1,0);
   FOR(i,n) c[r[a[i]]]++;
   
   // exclusive prefix sums
   int sum = 0;
   REP(i,0,K) {
     int t = c[i];
     c[i] = sum;
     sum += t;
  }
  
  // sort
  FOR(i,n) b[c[r[a[i]]]++] = a[i];
}

// find the suffix array SA of s[0..n-1] in {1..K}^n
// require s[n]=s[n+1]=s[n+2]=0, n>=2
void suffixArray(int* s, int* SA, int n, int K) {
  int n0 = (n+2)/3, n1 = (n+1)/3, n2 = n/3, n02 = n0+n2; 
  int* s12  = new int[n02 + 3];  s12[n02]= s12[n02+1]= s12[n02+2]=0; 
  int* SA12 = new int[n02 + 3]; SA12[n02]=SA12[n02+1]=SA12[n02+2]=0;
  int* s0   = new int[n0];
  int* SA0  = new int[n0];
 
  // generate positions of mod 1 and mod 2 suffixes
  // the "+(n0-n1)" adds a dummy mod 1 suffix if n%3 == 1
  for (int i=0, j=0;  i < n+(n0-n1);  i++) if (i%3 != 0) s12[j++] = i;

  // lsb radix sort the mod 1 and mod 2 triples
  radixPass(s12 , SA12, s+2, n02, K);
  radixPass(SA12, s12 , s+1, n02, K);
  radixPass(s12 , SA12, s  , n02, K);

  // find lexicographic names of triples
  int name = 0, c0 = -1, c1 = -1, c2 = -1;
  FOR(i,n02) {
    if (s[SA12[i]] != c0 || s[SA12[i]+1] != c1 || s[SA12[i]+2] != c2) { 
      name++;  c0 = s[SA12[i]];  c1 = s[SA12[i]+1];  c2 = s[SA12[i]+2];
    }
    if (SA12[i] % 3 == 1) { s12[SA12[i]/3]      = name; } // left half
    else                  { s12[SA12[i]/3 + n0] = name; } // right half
  }

  // recurse if names are not yet unique
  if (name < n02) {
    suffixArray(s12, SA12, n02, name);
    // store unique names in s12 using the suffix array 
    FOR(i,n02) s12[SA12[i]] = i + 1;
  } else { // generate the suffix array of s12 directly
    FOR(i,n02) SA12[s12[i] - 1] = i;
  }

  // stably sort the mod 0 suffixes from SA12 by their first character
  for (int i = 0, j = 0; i < n02; ++i) if (SA12[i] < n0) s0[j++] = 3*SA12[i];
  radixPass(s0, SA0, s, n0, K);

  // merge sorted SA0 suffixes and sorted SA12 suffixes
  int p = 0, t = n0-n1;
  FOR(k,n) {
#define GetI() (SA12[t] < n0 ? SA12[t] * 3 + 1 : (SA12[t] - n0) * 3 + 2)
    int i = GetI(); // pos of current offset 12 suffix
    int j = SA0[p]; // pos of current offset 0  suffix
    if (SA12[t] < n0 ?
        leq(s[i],       s12[SA12[t] + n0], s[j],       s12[j/3]) :
        leq(s[i],s[i+1],s12[SA12[t]-n0+1], s[j],s[j+1],s12[j/3+n0])) {
      // suffix from SA12 is smaller
      SA[k] = i;  t++;
      if (t == n02) { // done --- only SA0 suffixes left
        for (k++;  p < n0;  p++, k++) SA[k] = SA0[p];
      }
    } else {
      SA[k] = j;  p++;
      if (p == n0)  { // done --- only SA12 suffixes left
        for (k++;  t < n02;  t++, k++) SA[k] = GetI();
      }
    }
  }
  delete [] s12; delete [] SA12; delete [] SA0; delete [] s0; 
}
};


struct SuffixArray {
   int *sa, *lcp, *rank, n;
   vi t;
   
   SuffixArray(const vi &str) : t(str) {
      n = SZ(t);
      
      if (n <= 1) {
         sa = new int[5];
         sa[0] = 0;
      } else {    
         int *arr = new int[n+3];
         sa = new int[n+3];
         FOR(i,n) arr[i] = t[i];
         arr[n] = arr[n+1] = arr[n+2] = 0;
         karkkainen::suffixArray(arr,sa,n,*max_element(arr,arr+n));
         delete [] arr;
      }
      
      rank = new int[n+3];
      FOR(i,n) rank[sa[i]] = i;
      // Kasai
      lcp = new int[n+3];
      for (int i = 0, k = 0; i < n; i++) {
         if (k > 0) k--;
         if (rank[i] == n-1) { lcp[n-1] = -1; k = 0; continue; }
         int j = sa[rank[i]+1];
         while (t[i+k] == t[j+k]) k++;
         lcp[rank[i]] = k;
      }
   }
   
   ~SuffixArray() { // przydatny jesli wiele testow
      delete [] sa;
      delete [] rank;
      delete [] lcp;
   }
};

const int LOGN = 18, N = 1<<LOGN; // mozna zmniejszyc N
int rm[LOGN][N]; // rm[k][i] = min(tab[i], ..., tab[i + 2^k - 1])
void init (int *tab, int n) { // tab[0..n-1]
   FOR(i,n) rm[0][i] = tab[i];
   REP(k,1,LOGN-1) REP(i,0,n-(1<<k)) rm[k][i] = min(rm[k-1][i], rm[k-1][i+(1<<(k-1))]);
}
int query (int a, int b) { // a <= b bo inaczej segfault
   int k = 31 - __builtin_clz(b-a+1);
   return min(rm[k][a], rm[k][b-(1<<k)+1]);
}

int inp[N];
int word[N];
int ans[N];
int newword[N];

struct Todo {
   int from, to, maxIndex, whichQuery, multiplier, uniq;
};
bool operator < (const Todo &t, const Todo &r) {
   return t.maxIndex != r.maxIndex ? t.maxIndex < r.maxIndex : t.uniq < r.uniq;
}

namespace Fenwick {
#define MAXN 200007
int a[MAXN];
// value[n] += x
void add(int n, int x) { for (; n < MAXN; n |= n + 1) a[n] += x; }
// Returns value[0] + value[1] + ... + value[n]
int sum(int n) { int s=0; while (n>=0) { s+=a[n]; n=(n&(n+1))-1; } return s; }
};

int main () {
   wez(n)
   FOR(i,n) {
      scanf("%d", inp+i);
   }
   FOR(i,n-1) {
      word[i] = inp[i+1] - inp[i];
   }
   word[n-1] = INT_MAX;
   FOR(i,n-1) {
      word[n+i] = -word[i];
   }
   int len = 2*n - 1;
   
   map<int,int> mapa;
   int now = 1;
   FOR(i,len) mapa[word[i]] = now++;
   FOR(i,len) newword[i] = mapa[word[i]];
   
   SuffixArray sa(vi(newword,newword+len));
   init(sa.lcp, sa.n);
   
   vector<Todo> todo;
   int uniquer = 0;
   wez(queries)
   FOR(q,queries) {
      wez2(l,r)
      --l;--r;
      if (l == r) {
         ans[q] = n - 1;
      } else {
         // znajdz a oraz b
         int indexInSa = sa.rank[n+l];
         
         int a = indexInSa, b = indexInSa;
         {
            int from = 0, to = indexInSa-1;
            while (from <= to) {
               int mid = (from + to)/2;
               if (query(mid, indexInSa-1) < r-l) {
                  from = mid+1;
               } else {
                  a = mid;
                  to = mid - 1;
               }
            }
         }
         {
            int from = indexInSa + 1, to = sa.n - 1;
            while (from <= to) {
               int mid = (from + to) / 2;
               if (query(indexInSa, mid - 1) < r-l) {
                  to = mid-1;
               } else {
                  b = mid;
                  from = mid+1;
               }
            }
         }
                     
         // pytamy, ile w word[r+1..n-2] oraz word[0.. l - (r-l+1)] (te przedzialy moga byc puste) jest poczatkow wystapien podslowa word[n+l .. n+r-1]
         ans[q] = 0;
         if (r+1 <= n-2) {
            todo.pb((Todo){a,b,n-2,q,1,uniquer++});
            todo.pb((Todo){a,b,r,q,-1,uniquer++});
         }
         if (0 <= l-(r-l+1)) {
            todo.pb((Todo){a,b,l-(r-l+1),q,1,uniquer++});
         }
      }
   }
   
   // wykonaj todo
   sort(ALL(todo));
   int nowToAddIndex = 0;
   FOREACH(td,todo) {
      for (; nowToAddIndex <= td->maxIndex; ++nowToAddIndex) {
         Fenwick::add(sa.rank[nowToAddIndex], 1);
      }
      int res = Fenwick::sum(td->to) - (td->from == 0 ? 0 : Fenwick::sum(td->from-1));
      ans[td->whichQuery] += td->multiplier * res;
   }
   
   FOR(q,queries) pisz(ans[q]);
}