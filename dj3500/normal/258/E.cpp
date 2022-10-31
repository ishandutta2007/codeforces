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

// Struktura umozliwia dodawanie i usuwanie odcinkow oraz wyznaczanie 
// wielkosci obszaru przez nie pokrytego
struct CoverTree { 
#define nr (wp + wk + 1) >> 1
	int *el, *ma, s, p, k, il;
// Konstruktor przyjmuje jako parametr wysokosc konstruowanego drzewa (koce 
// odcinkow, na ktorych wykonywane sa operacje naleza do przedzialu [0..2^size-1])
	CoverTree(int size) {
// Tablica el przechowuje liczbe odcinkow pokrywajacych w calosci przedzial
// reprezentowany przez odpowiedni wezel
		el = new int[s = 1 << (size + 1)];
// Tablica ma przechowuje sumaryczna pokryta powierzchnie przedzialu 
// reprezentowanego przez odpowiedni wezel
		ma = new int[s];
		FOR(x, s) el[x] = ma[x] = 0;
	}
// Destruktor zwalnia zaalokowana pamiec
	~CoverTree() {
		delete[] el;
		delete[] ma;
	}
// Funkcja pomocnicza wykorzystywana przez operacje dodawania i usuwania odcinkow. 
// Wykonuje ona aktualizacje wartosci w wezlach
	void Mark(int wp, int wk, int g) {
// Jesli dodawany/usuwany odcinek jest rozlaczny z przedzialem 
// reprezentowanym przez aktualny wezel, to przerwij
		if(k<=wp || p>=wk) return;
// Jesli odcinek pokrywa w calosci przedzial aktualnego wezla, to zmie wartosc el,
		if(p<=wp && k>=wk) el[g] += il; else {
// a jesli nie, to wykonaj aktualizacje zmiennych synow aktualnego wezla
			Mark(wp, nr, 2 * g); 
			Mark(nr, wk, 2 * g + 1);
		}
// Dokonaj aktualizacji pokrytego obszaru przetwarzanego przedzialu
		ma[g] = el[g] > 0 ? wk - wp : 
			(wk - 1 == wp ? 0 : ma[2 * g] + ma[2 * g + 1]);
	}
// Funkcja dodajaca i1 wystapie odcinka [p1..k1] do drzewa. W przypadku,
// gdy i1 jest wartoscia ujemna, nastepuje usuniecie odcinka
	void Add(int p1, int k1, int i1) {
		p = p1;
		k = k1;
		il = i1;
		Mark(0, s / 2, 1);
	}
// Funkcja pomocnicza sluzaca do wyznaczania wielkosci obszaru 
// [wp, wk] pokrytego przez odcinki
    int F(int wp, int wk, int g) {
// Jesli testowany odcinek jest rozlaczny z aktualnym przedzialem, 
// to pokrycie jest rowne 0
		if (wp >= k || wk <= p) return 0;
// Jesli przedzial jest w calosci pokryty, to zwroc wielkosc 
// czesci wspolnej testowanego odcinka i przedzialu
		if (el[g] > 0) return min(k, wk) - max(p, wp);
// Jesli odcinek pokrywa w calosci przedzial, to zwroc pokrycie przedzialu
		if (p <= wp && wk <= k) return ma[g];
// Zwroc jako wynik sume pokryc swoich synow
		return wp == wk - 1 ? 0 : F(wp, nr, 2 * g) + F(nr, wk, 2 * g + 1);
    }
// Wlasciwa funkcja realizujaca wyznaczanie wielkosci obszaru 
// [p1, k1] pokrytego przez odcinki
    int Find(int p1, int k1) { 
		p = p1;
		k = k1;
		return F(0, s / 2, 1);
	}
};

#define N 100007
vi adj[N], links[N];
int newnum[N], maxinsubtree[N], parent[N], res[N], oldnum[N], n;
int t = 0;

void dfs (int v, int p) {
   newnum[v] = ++t;
   oldnum[newnum[v]] = v;
   maxinsubtree[newnum[v]] = newnum[v];
   FOREACH(x,adj[v]) if (*x != p) {
      dfs(*x,v);
      REMAX(maxinsubtree[newnum[v]], maxinsubtree[newnum[*x]]);
   }
   parent[v] = newnum[p];
}

CoverTree ct(17);
void go (int v, int p) {
   FOREACH(x,links[v]) {
      ct.Add(*x,maxinsubtree[*x]+1,1);
      ct.Add(v,maxinsubtree[v]+1,1);
   }
   res[v] = ct.Find(0,n+1);
   if (res[v] > 0) res[v] -= 1;
   FOREACH(x,adj[oldnum[v]]) {
      int w = newnum[*x];
      if (w != p) go(w,v);
   }
   FOREACH(x,links[v]) {
      ct.Add(*x,maxinsubtree[*x]+1,-1);
      ct.Add(v,maxinsubtree[v]+1,-1);
   }
}

int main () {
   scanf("%d", &n);
   wez(m)
   FOR(i,n-1) {
      wez2(u,v)
      adj[u].pb(v);
      adj[v].pb(u);
   }
   dfs(1,0);
   while (m--) {
      wez2(a,b)
      a = newnum[a];
      b = newnum[b];
      links[a].pb(b);
      links[b].pb(a);
   }
   
   FORI(i,n) res[i] = 0;
   go(1,0);
   
   
   FORI(i,n) printf("%d ", res[newnum[i]]);
}