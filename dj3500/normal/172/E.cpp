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

char s[1000007], buf[4007];
int res[205], matched[205], patternLength[205], patternCodes[205][205], n, ind;
vector<pii> html;

void go () {
   int code = html[ind].se;
   //printf("opening %d\n", code);
   vi risen;
   FOR(i,n) {
      if (code == patternCodes[i][matched[i]]) {
         if (matched[i] == patternLength[i]-1) {
            ++res[i];
         } else {
            matched[i]++;
            risen.pb(i);
         }
      }
   }
   
   ind++;
   if (html[ind].fi == 1) {
      go(); // przepuszczamy
   }
   
   // zamykajacy teraz
   //printf("closing %d\n", code);
   FOREACH(x,risen) --matched[*x];
   
   ind++;
   if (ind < SZ(html) && html[ind].fi == 1) go();      
}

map<string,int> kod;
int nextCode = 1;
void init (const string &str) {
   //DBG(str)
   if (!IN(str,kod)) kod[str] = nextCode++;
}

int main () {
   IOS
   cin.getline(s,1000004);
   cin >> n;
   cin.getline(buf,20);
   FOR(i,n) {
      cin.getline(buf,4003);
      stringstream ss(buf);
      string x;
      patternLength[i] = 0;
      matched[i] = 0;
      res[i] = 0;
      while (ss >> x) {
         init(x);
         patternCodes[i][patternLength[i]++] = kod[x];
      }
   }
   
   int pos = 0, len = strlen(s);
   while (pos < len) {
      pos++;
      string name;
      while (s[pos] != '>') {
         name += s[pos];
         pos++;
      }
      pos++;
      if (name[0] == '/') {
         string nowy = name.substr(1);
         init(nowy);
         html.pb(mp(-1,kod[nowy]));
      } else if (name[SZ(name)-1] == '/') {
         string nowy = name.substr(0,SZ(name)-1);
         init(nowy);
         html.pb(mp(1,kod[nowy]));
         html.pb(mp(-1,kod[nowy]));
      } else {
         init(name);
         html.pb(mp(1,kod[name]));
      }
   }
   //DBG(html)
   
   ind = 0;
   go();
   
   FOR(i,n) pisz(res[i]);
}