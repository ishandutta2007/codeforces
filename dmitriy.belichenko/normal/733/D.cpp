 
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stack>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <deque>
#include <bitset>
#define ll long long
#define ull  unsigned long long
#define lf long float
#define MAX 2e9
#define MIN -2e9
#define PI 3.14159265
#define fst first
#define scd second
#define mp make_pair
#define forn(i, x) for(int i = 0; i < x; i++)
#define size(x) x.size()
#define pb push_back
using namespace std;
 
struct vertex {
   int a, b , c, num;
   vertex(int a1, int b1, int c1, int num1) {
      a = a1;
      b = b1;
      c = c1;
      num = num1;
   }
};
int fs = -1, sc = -1, v = -1;
pair<int, int> def(int a, int b, int c, int nm, map< pair<int, int>, set<pair<int, int> > > & g) {
   pair<int, int> osn = mp(a, b);
   pair<int, int> bad = mp(c, nm);
   if(g.find(osn) == g.end()) {
      return mp(-1, -1);
   }
   bool is = false;
   if(g[osn].find(bad) != g[osn].end()) {
      g[osn].erase(bad);
      is = true;
   }
   if(size(g[osn]) == 0) {
         return mp(-1, -1);
   }
   pair<int, int> rz = *g[osn].rbegin();
   g[osn].insert(bad);
   return rz;
}
 
 int get( int v, int a, int b, int c, int c1) {
   int mn = min( min(a, b), c + c1);
   return max(v, mn);
}
 
void vooid(pair<int, int> p, int mn, int mx, int c, int nm) {
    if(p.fst == -1) {
         return;
      }
      int vv = get(v, mn, mx, c, p.fst);
      if(v < vv) {
         fs = nm;
         sc = p.scd;
         v =vv;
      }
      return;
}
int main () {
 //freopen("knapsack.in", "r", stdin);
 //freopen("knapsack.out", "w", stdout);
   int n;
   cin >> n;
 
   map< pair<int, int>, set<pair<int, int> > > g1, g2, g3;
vector<vertex>inp;
 inp.resize(n, vertex(0, 0, 0, 0));
 
   for(int i = 0; i < n; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      inp[i].a = a;
      inp[i].b = b;
      inp[i].c = c;
      inp[i].num = i + 1;
      int mn, mx;
     
      mn = min(a, b);
      mx = max(a, b);
      g1[mp(mn, mx)].insert(mp(c, i + 1));
     
      mn = min(a, c);
      mx = max(a, c);
      g2[mp(mn, mx)].insert(mp(b, i + 1));
     
      mn = min(b, c);
      mx = max(b, c);
      g3[mp(mn, mx)].insert(mp(a, i + 1));
      if(v < min(a, min(b, c))) {
         fs = i + 1;
         v = min(a, min(b, c));
      }
   }
   for(int i = 0; i < n; i++) {
      int a = inp[i].a;
      int b = inp[i].b;
      int c = inp[i].c;
      int nm = inp[i].num;
     
      int mn, mx;
      mn = min(a, b);
      mx = max(a, b);
      pair<int, int> p = def(mn, mx, c, nm, g1);
      vooid(p, mn, mx, c, nm);
     
   p = def(mn, mx, c, nm, g2);
      vooid(p, mn, mx, c, nm);
     
     
      p = def(mn, mx, c, nm, g3);
      vooid(p, mn, mx, c, nm);
     
     
     
      mn = min(a, c);
      mx = max(a, c);
      p = def(mn, mx, b, nm, g1);
      vooid(p, mn, mx, b, nm);
     
     p = def(mn, mx, b, nm, g2);
      vooid(p, mn, mx, b, nm);
     
     
       p = def(mn, mx, b, nm, g3);
      vooid(p, mn, mx, b, nm);
     
     
     
      mn = min(c, b);
      mx = max(c, b);
       p = def(mn, mx, a, nm, g1);
      vooid(p, mn, mx, a, nm);
     
      p = def(mn, mx, a, nm, g2);
      vooid(p, mn, mx, a, nm);
     
     
     p = def(mn, mx, a, nm, g3);
      vooid(p, mn, mx, a, nm);
   }
   if(sc == -1) {
         cout << "1\n" << fs;
   } else {
         cout << "2\n" << fs << " " << sc;
   }
   
   return 0;
}