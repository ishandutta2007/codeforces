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
#define FOREACH(i,t) for (__typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

bool allowed[200];
vector<string> all;

void gen (string x) {
   if (SZ(x) <= 10) {
      REP(c,'0','9') if (allowed[c]) {
         stringstream ss;
         ss << char(c) << x << char(c);
         gen(ss.str());
      }
   }
   if (SZ(x) >= 4 && SZ(x) <= 12) all.pb(x);
}

int cnt[300];
char temp[300];

int main () {
   vector<string> results;
   wez(n)
   REP(c,'0','9') allowed[c] = 0;
   FOR(u,n) {
      wez(x)
      allowed['0' + x] = 1;
   }
   if (n >= 7) {
      pisz(0);
      return 0;
   }
   
   REP(c,0,9) if (allowed[c+'0']){
      stringstream ss;
      ss << c;
      gen(ss.str());
   }
   gen("");
   //int bads = 0;
   FOR(i,SZ(all)) {
      REP(c,'0','9') cnt[c] = 0;
      FOR(j,SZ(all[i])) cnt[all[i][j]]++;
      bool bad = 0;
      REP(c,'0','9') if (cnt[c] == 0 && allowed[c]) { bad = 1; break; }
      if (!bad) {
         string s = all[i];
         REP(la,1,3) REP(lb,1,3) REP(lc,1,3) REP(ld,1,3) if (la+lb+lc+ld==SZ(s)) {
            bool zle = 0;
            int st[4] = {0,la,la+lb,la+lb+lc}, len[4] = {la,lb,lc,ld};
            FOR(u,4) {
               if (s[st[u]] == '0' && len[u] > 1) { zle = 1; break; }
            }
            if (zle) continue;
            FOR(u,4) {
               int num = atoi(s.substr(st[u],len[u]).c_str());
               if (num > 255) { zle = 1; break; }
            }
            if (!zle) {
               sprintf(temp, "%s.%s.%s.%s", s.substr(st[0],len[0]).c_str(), s.substr(st[1],len[1]).c_str(), s.substr(st[2],len[2]).c_str(), s.substr(st[3],len[3]).c_str());
               results.pb(string(temp));
            }
         }
      }
   }
   
   pisz(SZ(results));
   sort(ALL(results));
   FOREACH(x,results) printf("%s\n", x->c_str());
}