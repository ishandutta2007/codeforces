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

bool isSuffix (string s, string t) {
  if (s.length() > t.length()) return 0;
  FOR(i,s.length()) {
    if (s[i] != t[t.length()-s.length()+i]) return 0;
  }
  return 1;
}

const string lios = "lios", liala = "liala", etr = "etr", etra = "etra", initis = "initis", inites = "inites";

bool isvalid (const string &s, int &gender, int &type) {
   if (isSuffix(lios,s)) {
      gender = 0;
      type = 0;
      return 1;
   }
   if (isSuffix(liala,s)) {
      gender = 1;
      type = 0;
      return 1;
   }
   if (isSuffix(etr,s)) {
      gender = 0;
      type = 1;
      return 1;
   }
   if (isSuffix(etra,s)) {
      gender = 1;
      type = 1;
      return 1;
   }
   if (isSuffix(initis,s)) {
      gender = 0;
      type = 2;
      return 1;
   }
   if (isSuffix(inites,s)) {
      gender = 1;
      type = 2;
      return 1;
   }
   return 0;
}

int main () {
   ios_base::sync_with_stdio(0);
   string s;
   int no = 0, allgend = -1;
   vi types;
   while (cin >> s) {
      int gender, type;
      if (!isvalid(s,gender,type)) {
         cout << "NO" << endl;
         return 0;
      }
      if (no > 0 && allgend != gender) {
         cout << "NO" << endl;
         return 0;
      }
      allgend = gender;
      no++;
      types.pb(type);
   }
   if (no == 1) {
      cout << "YES"<<endl;
   } else {
      int last = 0, nouns = 0;
      FOR(k,SZ(types)) {
         if (types[k] == 1) nouns++;
         if (last > types[k]) {
            cout << "NO" << endl;
            return 0;
         }
         last = types[k];
      }
      if (nouns == 1) {
         cout << "YES" << endl;
         return 0;
      } else {
         cout << "NO" << endl;
         return 0;
      }
   }
}