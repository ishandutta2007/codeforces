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
#define DBG(vari) cout<<"["<<__LINE__<<"] "<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (__typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

namespace sat {
#define N 1007
int n,       // input
ind[N],    // temp
lowlink[N],  // temp
onstack[N],  // temp
last,        // temp
n2,          // output
t[N];        // output
vi adj[N],   // input
st;          // temp

void go (int v) {
   ind[v] = lowlink[v] = ++last;
   st.pb(v);
   onstack[v] = 1;
   FOREACH(w,adj[v]) {
      if (!ind[*w]) {
         go(*w);
         lowlink[v] = min(lowlink[v], lowlink[*w]);
      } else if (onstack[*w]) {
         lowlink[v] = min(lowlink[v], lowlink[*w]);
      }
   }
   if (lowlink[v] == ind[v]) { // v is a root node
      ++n2;
      for (int w = -1; w != v; ) {
         w = st.back();
         st.pop_back();
         onstack[w] = 0;
         t[w] = n2;
      }
   }
}

void scc() {
   last = n2 = 0;
   FORI(i,n) ind[i] = onstack[i] = 0;
   FORI(i,n) if (!ind[i]) go(i);
   FORI(i,n) t[i] = n2 + 1 - t[i]; // zeby byl zwykly porzadek topologiczny
}

// przed uzyciem wypelnic:
//    N (przed scc()): DWA RAZY! max liczba zmiennych
//    k: liczba zmiennych, numerowanych od 1 do k
//    clauses: wektor par (i,j) oznaczajacych klauzule (xi v xj)
//             negacja to minus, np. (-3,5) oznacza (~x3 v x5)
// dwasat() zwraca, czy formula jest spelnialna
// jesli jest, to dodatkowo w val[i] znajduje sie wartosciowanie xi

int k,               // input
val[N];              // output
vector<pii> clauses; // input

bool dwasat() {
   // konstrukcja grafu
   n = 2*k;
   FORI(i,n) adj[i].clear();
   FOR(i,SZ(clauses)) {
      int a = clauses[i].fi, b = clauses[i].se;
      if (a < 0) a = n+1+a; // negacja
      if (b < 0) b = n+1+b;
      adj[n+1-a].pb(b);
      adj[n+1-b].pb(a);
   }
   // silnie spojne skladowe (+ sort. top.)
   scc();
   // spr czy formula jest spelnialna
   FORI(i,k) if (t[i] == t[n+1-i]) return 0;
   return 1;
}
};

char s[N], _vow[N];
bool vow[N];
int n,m;
bool present[2];

bool isPossible (int pos, bool truth) {
    sat::clauses.erase(sat::clauses.begin() + m, sat::clauses.end());
    REP(i,0,pos-1) {
        bool isV = vow[s[i]];
        int I = isV ? i+1 : -i-1;
        sat::clauses.pb(mp(I,I));
    }
    if (pos < n) {
        int I = truth ? pos+1 : -pos-1;
        sat::clauses.pb(mp(I,I));

        // to handle only-consonant or only-vowel alphabets
        REP(i,pos+1,n-1) {
           if (!present[0]) sat::clauses.pb(mp(i+1,i+1));
           if (!present[1]) sat::clauses.pb(mp(-i-1,-i-1));
        }
    }
    return sat::dwasat();
}

int main () {
    scanf("%s", _vow + 'a');
    int l = strlen(_vow + 'a');
    //DBG(l)
    REP(letter,'a','a'+l-1) {
       vow[letter] = ('V' == _vow[letter]);
       present[vow[letter]] = 1;
    }
    scanf("%d %d", &n, &m);
    FORI(i,m) {
        int p1, p2;
        char t1, t2;
        scanf("%d %c %d %c", &p1, &t1, &p2, &t2);
        if (t1 == 'C') p1 *= -1;
        if (t2 == 'C') p2 *= -1;
        p1 *= -1;
        sat::clauses.pb(mp(p1,p2));
    }
    scanf("%s", s);
    sat::k = n;

    if (isPossible(n, 0)) {
        cout << s;
        return 0;
    }

    //DBG(isPossible(n-1,0))
    //DBG(isPossible(n-2,0))

    int pos;
    for (pos = n-1; pos >= 0; --pos) {
        // zwieksze pozycje pos
        bool possible[2];
        FOR(truth,2) {
            possible[truth] = isPossible(pos, truth);
        }
        int availableHigher[2] = {INF, INF};
        REP(letter, s[pos] + 1, 'a' + l-1) {
            REMIN(availableHigher[vow[letter]], letter);
        }
        FOR(truth, 2) if (INF == availableHigher[truth]) possible[truth] = 0;
        if (possible[0] || possible[1]) {
            int truth;
            if (possible[0] && possible[1]) {
                truth = 0;
                if (availableHigher[1] < availableHigher[0]) truth = 1;
            } else if (possible[0]) {
                truth = 0;
            } else {
                truth = 1;
            }
            s[pos] = availableHigher[truth];
            break;
        } else {
            // nie da sie
        }
    }

    if (pos == -1) {
        pisz(-1);
        return 0;
    }
    //DBG(pos)

    int availableHigher[2] = {INF, INF};
    REP(letter, 'a', 'a' + l-1) {
        REMIN(availableHigher[vow[letter]], letter);
    }

    for (++pos; pos < n; ++pos) {
        bool possible[2];
        FOR(truth,2) possible[truth] = isPossible(pos, truth);
        FOR(truth,2) if (INF == availableHigher[truth]) possible[truth] = 0;
        if (possible[0] || possible[1]) {
            int truth;
            if (possible[0] && possible[1]) {
                truth = 0;
                if (availableHigher[1] < availableHigher[0]) truth = 1;
            } else if (possible[0]) {
                truth = 0;
            } else {
                truth = 1;
            }
            s[pos] = availableHigher[truth];
        } else {
            // tu nie powinno wchodzic...
        }
    }

    cout << s;
}