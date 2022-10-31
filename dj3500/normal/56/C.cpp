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

string in;
int pos = 0;

struct Emp {
   vector<Emp> v;
   string name;
   void read () {
      if (in[pos] == ',') ++pos;
      
      int startpos = pos;
      while (in[pos] != '.' && in[pos] != ':') {
         ++pos;
      }
      name = in.substr(startpos, pos-startpos);
      
      if (in[pos] == '.') {
         ++pos;
         return;
      } else ++pos;
      
      while (in[pos] != '.') {
         Emp e;
         e.read();
         v.pb(e);
      }
      ++pos;
   }
   
   int find (string n, bool myself) {
      int w = 0;
      if (!myself) if (n==name) ++w;
      FOR(i,v.size()) w += v[i].find(n,false);
      return w;
   }
   
   int unc() {
      int w = find(name,true);
      FOR(i,v.size()) w += v[i].unc();
      return w;
   }
};

int main () {
   cin >> in;
   Emp e;
   e.read();
   e.unc();
   cout << e.unc() << endl;
}