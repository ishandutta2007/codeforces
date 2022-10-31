#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
#define pb push_back
#define INF (int)1e9
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define wez(n) int (n); scanf("%d",&(n));
#define IN(x,y) ((y).find((x))!=(y).end()) 
#define DBG(vari) cout<<#vari<<" = "<<vari<<endl;

inline void pisz(int n) {
   printf("%d\n",n);
}

struct UnionFind {
   vector<int> tab,ile;
   int size;
   
   UnionFind(int _size) : // tworzy UF na 0, 1, ..., n-1
      size(_size), tab(_size), ile(_size,1) {
      FOR(i,size) tab[i] = i;
   }
 
   int find(int a) {
        if (tab[a]==a) return a;
        int fa = find(tab[a]);
        tab[a] = fa;
        return fa;
   }
 
   bool unia(int a, int b) { // zwraca, czy odbylo sie polaczenie
        int fa = find(a);
        int fb = find(b);
 
        if (fa==fb) return false;
        if (ile[fa] <= ile[fb]) {
                ile[fb] += ile[fa];
                tab[fa] = fb;
        } else {
                ile[fa] += ile[fb];
                tab[fb] = fa;
        }
        return true;
   }
   
   int ileKlas() { // ile jest klas abstrakcji? UWAGA: zakada, e wszystkie numerki s wykorzystane
      int w = 0;
      FOR(i,size) if (tab[i]==i) ++w;
      return w;
   }
};



int przelicz(int a,int b,int c) {
   return 100*a+10*b+c;
}

bool empty[11][11][11];
 
int main()
{
	UnionFind uf(1000);
	
	wez(k)wez(n)wez(m)
	FOR(k1,k) FOR(n1,n) {
      string s;
      cin >> s;
      FOR(m1,m) {
         if (s[m1] == '.')  {
            empty[k1][n1][m1] = true;
         } else empty[k1][n1][m1] = false;
      }
   }
   wez(x)
   wez(y)
   
   FOR(k1,k) FOR(n1,n) FOR(m1,m) {
      if (empty[k1][n1][m1]) {
         if (m1 != 0) if (empty[k1][n1][m1-1]) uf.unia(przelicz(k1,n1,m1), przelicz(k1,n1,m1-1));
         if (k1 != 0) if (empty[k1-1][n1][m1]) uf.unia(przelicz(k1,n1,m1), przelicz(k1-1,n1,m1));
         if (n1 != 0) if (empty[k1][n1-1][m1]) uf.unia(przelicz(k1,n1,m1), przelicz(k1,n1-1,m1));
      }
   }
   pisz(uf.ile[uf.find(przelicz(0,x-1,y-1))]);
}