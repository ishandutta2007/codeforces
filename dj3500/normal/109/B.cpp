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
#define INF 1050000000
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

ll fromOtherBase(string s, int b) {
   ll res = 0, po = 1;
   REPD(i,s.length()-1,0) {
      int num;
      if (s[i] >= '0' && s[i] <= '9') num = s[i]-'0';
      else num = s[i]-'A'+10;
      res += po*num;
      po *= b;
   }
   return res;
}

string toOtherBase(ll num, int b) {
   string w;
   if (num==0) w = "0";
   while (num != 0) {
      int r = num%b;
      num /= b;
      if (r < 10) w += r+'0';
      else w += r+'A'-10;
   }
   reverse(ALL(w));
   return w;
}

vi lucky;

ll wynik (int pl, int pr, int vl, int vr, int k) {
   ll suma = 0;
   for (int i = 0; i+k-1 < SZ(lucky); ++i) {
      int zlea = (i==0) ? 0 : lucky[i-1];
      int zleb = (i+k == SZ(lucky)) ? INF : lucky[i+k];
      int dobrzea = lucky[i], dobrzeb = lucky[i+k-1];
      ll maxa = max(zlea+1, pl), mina = min(dobrzea, pr);
      ll maxb = max(dobrzeb, vl), minb = min(zleb-1, vr);
      ll sizea = 0, sizeb = 0;
      if (maxa <= mina) sizea = mina - maxa + 1;
      if (maxb <= minb) sizeb = minb - maxb + 1;
      suma += sizea * sizeb;
   }
   return suma;
}

char konw[300];

int main () {
   wez2(pl,pr)
   wez3(vl,vr,k)
   //ll pl = _pl, pr = _pr, vl = _vl, vr = _vr;

   konw['0'] = '4';
   konw['1'] = '7';

   FORI(pot,9) {
      FOR(num,1<<pot) {
         string s = toOtherBase(num,2);
         string temp = "0";
         while (SZ(s) < pot) s = temp + s;
         FOR(u,SZ(s)) s[u] = konw[s[u]];
         lucky.pb(fromOtherBase(s,10));
      }
   }

   ll wyn = wynik(pl,pr,vl,vr,k) + wynik(vl,vr,pl,pr,k);

   if (k==1) FOR(i,SZ(lucky)) if (pl <= lucky[i] && lucky[i] <= pr && vl <= lucky[i] && lucky[i] <= vr) --wyn;

   ll wszystkiepary = ((ll)pr-pl+1)*((ll)vr-vl+1);
   cout << fixed << setprecision(11) << (long double)wyn/wszystkiepary << endl;
}