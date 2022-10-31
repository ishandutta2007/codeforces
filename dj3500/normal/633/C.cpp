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


struct Node {
   map<char,Node*> m;
   int patnum;
   Node () : patnum(-1) {}
   void wstaw (const char *s, int num) {
      if (*s == 0) {
         patnum = num;
         return;
      }
      int c = *s;
      if (!m.count(c)) {
         m[c] = new Node();
      }
      m[c]->wstaw(s+1, num);
   }
};


const int N = 1001001;
char s[N], buf[N];
string t[N], orig[N];
vi pats[N];
int dp[N];

int main () {
   wez(n)
   scanf("%s", s);
   wez(m)
   FORI(j,m) {
      scanf("%s", buf);
      orig[j] = t[j] = buf;
      for (char &c : t[j]) if (isupper(c)) c = c - 'A' + 'a';
      reverse(ALL(t[j]));
   }
   
   Node root;
   FORI(j,m) root.wstaw(t[j].c_str(), j);
   dp[n] = 0;
   REPD(i,n-1,0) {
      dp[i] = -1;
      Node* x = &root;
      REP(k,i,n-1) {
         if (x->m.count(s[k])) {
            x = x->m[s[k]];
            if (x->patnum != -1) {
               if (dp[i + SZ(t[x->patnum])] != -1) {
                  dp[i] = x->patnum;
                  break;
               }
            }
         } else {
            break;
         }
      }
   }
   int i = 0;
   while (i != n) {
      printf("%s ", orig[dp[i]].c_str());
      i += SZ(t[dp[i]]);
   }
}