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

vi prefsufy (string wzo) {
   #define KMPH(z) while(k > 0 && wzo[k] != z[q]) k = p[k]; if (wzo[k]==z[q]) k++;
   int p[SZ(wzo)+1],k=0,q;
   vi wyn;
   p[1]=0;
   for (q=1;wzo[q];q++) {
      KMPH(wzo);
      p[q+1]=k;
   }
   int u = SZ(wzo);
   vi res;
   while (u > 0) {
      res.pb(u);
      u = p[u];
   }
   return res;
   //DBG(vi(p+1,p+SZ(wzo)+1))
}

int maxppos = -1;
void kmp(string t, string p) { // text, pattern
   vi kn(SZ(p)+1,-1); // funkcja prefiksowa Knutha
   FORI(i,SZ(p)) {
      int j = kn[i-1];
      while (j != -1 && p[j] != p[i-1]) j=kn[j];
      kn[i] = j+1;
   }

   int ppos=0,tpos=0;
   while (tpos<SZ(t)) {
      while (ppos!=-1 && (ppos == SZ(p) || p[ppos]!=t[tpos])) ppos=kn[ppos];
      ppos++;
      tpos++;
      //if (ppos==SZ(p)) return 1;
      REMAX(maxppos, ppos);
   }
}

char inp[1000006];

int main () {
   //string s = "abcabddabcab";
   //kmp("",s);
   scanf("%s",inp);
   string s(inp);
   string niecaly = s.substr(1,SZ(s)-2);
   //DBG(s)
   //DBG(niecaly)
   vi prefsuf = prefsufy(s);
   reverse(ALL(prefsuf));
   //DBG(prefsuf)
   
   kmp(niecaly,s);
   //DBG(maxppos)
   
   int best = -1;
   FOR(i,SZ(prefsuf)) {
      if (maxppos >= prefsuf[i]) best = prefsuf[i];
   }
   
   if (best == -1) {
      printf("Just a legend\n");
   } else {
      printf("%s\n",s.substr(0,best).c_str());
   }
}