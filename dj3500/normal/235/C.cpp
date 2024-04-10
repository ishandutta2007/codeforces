#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) int((x).size())
#define IN(x,y) ((y).find((x))!=(y).end())
#define DBG(v) cerr<<#v<<" = "<<(v)<<endl;
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define fi first
#define se second
#define REPD(i,a,b) for (int i = (a); i >= (b); --i)



// kod jest bardzo szybki (0.3 sek dla 2 mln) ale zzera n log n pamieci
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

namespace Fenwick {
#define MAXN 2000007
int a[MAXN];
// value[n] += x
void add(int n, int x) { for (; n < MAXN; n |= n + 1) a[n] += x; }
// Returns value[0] + value[1] + ... + value[n]
int sum(int n) { int s=0; while (n>=0) { s+=a[n]; n=(n&(n+1))-1; } return s; }

};

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
   string t;
   
   SuffixArray(const char *str) : t(str) {
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
   
   ~SuffixArray() {
      delete [] sa;
      delete [] rank;
      delete [] lcp;
   }
   
   // match to para [a,b]: NIEPUSTY przedzial w SA odpowiadajacy dokladnie tym
   // sufiksom ktore zaczynaja sie od pewnego stringa s dlugosci len >= 0
   // (len nazywamy dalej dlugoscia matcha)
   // (poczatkowy match to [0,n-1] odp. slowu pustemu)
   
   // przedluza match o dlugosci len do dlugosci len+1, o litere x
   // jesli sie nie udalo, to zwraca PUSTY przedzial (tze fi > se)
   // precondition: match NIEPUSTY
   pii prolongMatch (const pii &match, int len, int x) {
      // c = min z [match.fi,match.se] tze s[sa[c] + len] >= x
      int c = match.se + 1, d = match.fi - 1;
      int from = match.fi, to = match.se;
      while (from <= to) {
         int mid = (from + to) / 2;
         if (sa[mid] + len < n && t[sa[mid] + len] >= x) {
            c = mid;
            to = mid - 1;
         } else {
            from = mid + 1;
         }
      }
      // d = max z [match.fi,match.se] tze s[sa[d] + len] <= x
      from = match.fi, to = match.se;
      while (from <= to) {
         int mid = (from + to) / 2;
         if (sa[mid] + len >= n || t[sa[mid] + len] <= x) {
            d = mid;
            from = mid + 1;
         } else {
            to = mid - 1;
         }
      }
      return mp(c,d);
   }
   
   // skraca match o dlugosci len do dlugosci len-1
   // wymaga obecnosci funkcji query(a,b) ktora zwroci min(lcp[a],...,lcp[b])
   // (jesli nie mamy RAMu na nlogn-strukture do RMQ, to mozna tez
   //  zastapic te binary searche przez AugTreap<int,IntMin>::minquery)
   // precondition: match NIEPUSTY i dlugosci >= 2
   pii suffixMatch (const pii &match, int len) {
      int any = rank[sa[match.fi] + 1];
      int c = any, d = any;
      // d = max tze t[sa[d]..] zaczyna sie od naszego sufiksu
      int from = any + 1, to = n - 1;
      while (from <= to) {
         int mid = (from + to) / 2;
         if (query(any, mid - 1) < len - 1) {
            to = mid - 1;
         } else {
            d = mid;
            from = mid + 1;
         }
      }
      // c = min tze (to samo)
      from = 0, to = any - 1;
      while (from <= to) {
         int mid = (from + to) / 2;
         if (query(mid, any - 1) < len - 1) {
            from = mid + 1;
         } else {
            c = mid;
            to = mid - 1;
         }
      }
      return mp(c,d);
   }
};

vi kmp(string t, string p) {
   vi kn(SZ(p)+1,-1); // funkcja prefiksowa Knutha
   FORI(i,SZ(p)) {
      int j = kn[i-1];
      while (j != -1 && p[j] != p[i-1]) j=kn[j];
      kn[i] = j+1;
   }
   // kn obliczone
   
   vi ans;
   int ppos=0,tpos=0;
   while (tpos<SZ(t)) {
      while (ppos!=-1 && (ppos == SZ(p) || p[ppos]!=t[tpos])) ppos=kn[ppos];
      ppos++;
      tpos++;
      if (ppos==SZ(p)) ans.pb(tpos-SZ(p));
   }
   return ans;
}

int per (string s) {
   vi km = kmp(s+s,s);
   return km[1];
}

char str[1000007];

int main () {
   scanf("%s", str);
   SuffixArray sa(str);
   int n = sa.n;
   init(sa.lcp, n);
   int queries;
   scanf("%d", &queries);
   while (queries--) {
      int res = 0;
      scanf("%s", str);
      int len = strlen(str);
      int maxStart = per(str) - 1;
      int start = 0, end = 0; // [)
      pii match(0,n-1);
      while(1) {
         // sprobuj przedluzyc z konca
         bool zKoncaOk = 0;
         if (end - start == len) {
            res += match.se - match.fi + 1;
            // nie probuj przedluzac z konca
         } else if (end < maxStart + len) {
            pii newMatch = sa.prolongMatch(match, end - start, str[end % len]);
            if (newMatch.fi <= newMatch.se) { // newMatch niepusty
               match = newMatch;
               end++;
               zKoncaOk = 1;
            }
         }
         if (!zKoncaOk) {
            // nie dalo sie z konca, sprobuj z poczatku
            if (start < maxStart) {
               match = sa.suffixMatch(match, end - start);
               start++;
            } else {
               break; // jak tez sie nie da, to koniec
            }
         }
      }
      printf("%d\n", res);
   }
}