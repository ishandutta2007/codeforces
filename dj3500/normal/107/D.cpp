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


const int MOD = 12345;

typedef int typ;
typedef vector<vector<typ> > macierz;

int ROZM;

void wypisz(const macierz &m) {
   FOR(i,ROZM) {
      FOR(j,ROZM) cout << m[i][j] << " ";
      cout << endl;
   }
}

macierz id() {
   macierz w(ROZM);
   FOR(i,ROZM) {
      w[i].resize(ROZM,0);
      w[i][i] = 1;
   }
   return w;
}

macierz zero() {
   macierz w(ROZM);
   FOR(i,ROZM) w[i].resize(ROZM,0);
   return w;
}

macierz transp(const macierz &m) {
   macierz w = zero();
   FOR(i,ROZM) FOR(j,ROZM) w[i][j]=m[j][i];
   return w;
}

macierz mult_transp(const macierz &m1, const macierz &m2) {
   macierz w = zero(), m3 = transp(m2);
   FOR(i,ROZM) FOR(j,ROZM) {
      ll wyn = 0;
      FOR(k,ROZM) wyn += m1[i][k] * m3[j][k];
      w[i][j] = wyn % MOD;
   }
   return w;
}

macierz potega(const macierz &m, ll k) {
   if (k==0) return id();
   macierz x = potega(m,k/2);
   x = mult_transp(x,x);
   if (k&1) return mult_transp(m,x);
   else return x;
}

set<int> mults[300], goodrests[300]; // dobre reszty (mod prod[i])
int prod[300], pprod[300];

vi decode (int mask) {
   vi w;
   REP(i,'A','Z') w.pb((mask / pprod[i-1]) % prod[i]);
   return w;
}

int encode (vi w) {
   int mask = 0;
   REP(i,'A','Z') mask += pprod[i-1] * w[i-'A'];
   return mask;
}

vi addletter (vi w, char l) {
   w[l-'A']++;
   if (w[l-'A'] == prod[l]) w[l-'A'] = 0;
   return w;
}

int main () {
   ios_base::sync_with_stdio(0);
   ll n;
   int c;
   cin >> n >> c;
   while (c--) {
      string s;
      int mult;
      cin >> s >> mult;
      mults[s[0]].insert(mult);
   }
   int p = 1;
   REP(i,'A','Z') {
      prod[i] = 1;
      FOREACH(it,mults[i]) prod[i] *= *it;
      goodrests[i].insert(0);
      FOREACH(it,mults[i]) for (int x = *it; x < prod[i]; x += *it) goodrests[i].insert(x);
      p *= prod[i];
   }
   pprod['A' - 1] = 1;
   REP(i,'A','Z') pprod[i] = pprod[i-1] * prod[i];

   ROZM = p;

   macierz T = zero();
   FOR(mask,p) REP(l,'A','Z') {
      if (mults[l].empty()) continue; // liczymy tylko przestepstwa ktore wolno popelniac, inaczej nie ma rozroznienia miedzy tymi ktore mozna do woli a tymi ktorych w ogole nie mozna
      int mask2 = encode(addletter(decode(mask),l));
      T[mask2][mask]++;
   }

   macierz Tpot = potega(T,n);
   // wektor A_n = T^n A_0, gdzie A_0 = (1 0 0 ... 0), rowny jest pierwszej kolumnie Tpot
   ll res = 0;
   FOR(mask,p) {
      // spr. czy maska jest dobra (Zeyad nie zostanie ukarany)
      vi w = decode(mask);
      bool ok = 1;
      REP(i,'A','Z') if (!IN(w[i-'A'], goodrests[i])) ok = 0;
      if (ok) res += Tpot[mask][0];
   }
   cout << (res % MOD) << endl;
}