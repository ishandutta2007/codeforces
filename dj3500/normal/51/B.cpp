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

string s;
int pos;
vector<int> l;

string tag () {
   if (s.substr(pos,4) == "<td>") {pos +=4; return "td"; }
   if (s.substr(pos,4) == "<tr>") { pos += 4; return "tr"; }
   if (s.substr(pos,5) == "</td>") { pos += 5; return "/td"; }
   if (s.substr(pos,5) == "</tr>") { pos += 5; return "/tr"; }
   if (s.substr(pos,7) == "<table>") { pos += 7; return "table"; }
   if (s.substr(pos,8) == "</table>") { pos += 8; return "/table"; }
   cout << "wtf: " << s.substr(pos,100000);
   return "niewiem";
}

void rd(int tds = 0) {
   string t = tag();
   if (t == "tr" || t == "/tr" || t == "/td") return rd(tds);
   if (t == "td") return rd(tds+1);
   if (t == "table") {
      rd();
      return rd(tds);
   }
   if (t == "/table") {
      l.pb(tds);
      return;
   }
}
      

int main () {
   string t;
   while (cin >> t) s += t;
   pos = 7;
   rd();
   sort(l.begin(),l.end());
   FOR(i,l.size()) printf("%d ",l[i]);
}