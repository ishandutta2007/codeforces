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
using namespace std;
#define pb push_back
#define INF 1000000000
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define SZ(x) ((int)(x.size()))
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

template <class Aug>
struct ITree {
   inline static Aug plus (Aug a1, Aug a2) { // dzialanie w polgrupie Aug
      return min(a1,a2);
   }
   static const Aug identity = INF;

   int leftend, rightend;
   Aug *state;

   ITree (int _leftend, int _rightend) :
      leftend(_leftend), rightend(_rightend) {
      int pot = 1;
      while (pot <= _rightend-_leftend+5) pot <<= 1;
      pot <<= 1;
      state = new Aug[pot+20];
      FOR(i,pot+20) state[i]=identity;
   }

   void set_aux (int x, Aug ile, int v, int from, int to) {
      if (from==to) {
         state[v] = ile;
         return;
      }
      int mid = (from+to)/2;
      if (x <= mid) set_aux(x,ile,2*v+1,from,mid);
      else set_aux(x,ile,2*v+2,mid+1,to);
      state[v] = plus(state[2*v+1],state[2*v+2]);
   }

   void set (int x, Aug ile) {
      set_aux(x,ile,0,leftend,rightend);
   }

   Aug sumofaugsoverkeyssmallerorequal_aux (int x, int v, int from, int to) {
      if (x < from) return identity;
      if (from==to) return state[v];
      int mid = (from+to)/2;
      if (x >= mid+1) return plus(state[2*v+1],sumofaugsoverkeyssmallerorequal_aux(x,2*v+2,mid+1,to));
      return sumofaugsoverkeyssmallerorequal_aux(x,2*v+1,from,mid);
   }

   Aug sumofaugsoverkeysbiggerorequal_aux (int x, int v, int from, int to) {
      if (x > to) return identity;
      if (from==to) return state[v];
      int mid = (from+to)/2;
      if (x <= mid) return plus(sumofaugsoverkeysbiggerorequal_aux(x,2*v+1,from,mid), state[2*v+2]);
      return sumofaugsoverkeysbiggerorequal_aux(x,2*v+2,mid+1,to);
   }

   Aug sumofaugsoverkeyssmallerorequal (int x) {
      return sumofaugsoverkeyssmallerorequal_aux(x,0,leftend,rightend);
   }

   Aug sumofaugsoverkeysbiggerorequal (int x) {
      return sumofaugsoverkeysbiggerorequal_aux(x,0,leftend,rightend);
   }

   Aug sumofaugsoverkeysbetween_aux(int x, int y, int v, int from, int to) {
      if (y < from) return identity;
      if (x > to) return identity;
      if (from==to) return state[v];
      int mid = (from+to)/2;
      if (y < mid+1) return sumofaugsoverkeysbetween_aux(x,y,2*v+1,from,mid);
      if (x > mid) return sumofaugsoverkeysbetween_aux(x,y,2*v+2,mid+1,to);
      return plus(sumofaugsoverkeysbiggerorequal_aux(x,2*v+1,from,mid), sumofaugsoverkeyssmallerorequal_aux(y,2*v+2,mid+1,to));
   }

   Aug sumofaugsoverkeysbetween (int x, int y) {
      if (x > y) return identity; // przedzial pusty
      return sumofaugsoverkeysbetween_aux(x,y,0,leftend,rightend);
   }
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
   int *sa, *lcp;
   ITree<int> tr;
   
   SuffixArray(const string &t, bool with_lcp = 0) : tr(0,SZ(t)-1) {
      int n = SZ(t);
      
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
      
      //vi rank(n+3);
      //FOR(i,n) rank[sa[i]] = i;
      FOR(i,n) tr.set(i,sa[i]);
      //DBG(rank)
   }
};

char buf[100006];
int n;

vi getBest (SuffixArray &a, string &s, string &t) {
   int m = SZ(t), from = 0, to = n-1;
   vi res(m,-1);
   FOR(j,m) {
      int b1 = -1, f1 = from, t1 = to;
      while (f1 <= t1) {
         int mid = (f1+t1)/2;
         int ind = j + a.sa[mid];
         bool ok;
         
         if (ind >= n) {
            ok = 1;
         } else {
            if (s[ind] <= t[j]) ok = 1;
            else ok = 0;
         }
         
         if (ok) {
            b1 = mid;
            f1 = mid+1;
         } else {
            t1 = mid-1;
         }
      }
      
      int b2 = n+600, f2 = from, t2 = to;
      while (f2 <= t2) {
         int mid = (f2+t2)/2;
         int ind = j + a.sa[mid];
         bool ok;
         
         if (ind >= n) {
            ok = 0;
         } else {
            if (s[ind] >= t[j]) ok = 1;
            else ok = 0;
         }
         
         if (ok) {
            b2 = mid;
            t2 = mid-1;
         } else {
            f2 = mid+1;
         }
      }
      
      if (b2 > b1) return res; // przedzial opustoszal
      from = b2;
      to = b1;
      
      //DBG(t.substr(0,j+1))
      //DBG(j)
      //DBG(mp(from,to))
      
      int rmq = a.tr.sumofaugsoverkeysbetween(from,to);
      res[j] = rmq;
      //DBG(rmq)
   }
   return res;
}

int main () {
   scanf("%s",buf);
   string s = buf;
   n = SZ(s);
   SuffixArray a1(s);
   //DBG(vi(a1.sa,a1.sa+n))
   string srev = s;
   reverse(ALL(srev));
   SuffixArray a2(srev);
   
   //vector<bool> jest(300,0);
   //FOR(i,n) jest[s[i]] = 1;
   
   int res = 0;
   TESTS {
      scanf("%s",buf);
      string t(buf);
      string trev = t;
      reverse(ALL(trev));
      int m = SZ(t);
      
      if (m==1) continue;
      
      vi best1 = getBest(a1,s,t), best2 = getBest(a2,srev,trev);
      //DBG(best1)
      //DBG(best2)
      
      if (best1[m-1] != -1) {
         ++res;
         // jest cale slowo
      } else {
         bool ok = 0;
         FOR(i,m-1) {
            //DBG(i)
            int a = best1[i];
            int b = best2[m-2-i];
            if (a == -1 || b == -1) continue;
            //DBG(a)
            //DBG(b)
            b = n-1-b;
            if (b-a+1 >= m) ok = 1;
         }
         if (ok) ++res;
      }
   }
   pisz(res);
}