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
using namespace std;
#define pb push_back
#define INF (int)1e9
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define sz size()
#define fi first
#define se second
#define wez(n) int (n); scanf("%d",&(n));
#define wez2(n,m) int (n),(m); scanf("%d %d",&(n),&(m));
#define wez3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k));
inline void pisz(int n) { printf("%d\n",n); }
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){FOR(i,t.size())s<<t[i]<<" ";return s; }
#define IN(x,y) ((y).find((x))!=(y).end()) 
#define DBG(vari) cout<<#vari<<" = "<<vari<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));

map<pair<string,string>,int> m;
map<string,int> val;
string myname;

bool mycomp (const string &a, const string &b) {
   if (val[a] != val[b]) return val[a] > val[b];
   return a<b;
}

int main () {
   ios_base::sync_with_stdio(0);
   cin >> myname;
   
   set<string> s;
   
   int n;
   cin >> n;
   while (n--) {
      string name1, action;
      cin >> name1 >> action;
      if (action == "likes") {
         string name2;
         cin >> name2;
         name2 = name2.substr(0,name2.length()-2);
        // DBG(name2)
         
         m[mp(name1,name2)] += 5;
         m[mp(name2,name1)] += 5;
         s.insert(name1);
         s.insert(name2);
         
         string syf;
         cin >> syf;
      } else {
         int pts = (action=="commented") ? 10 : 15;
         string name2, syf;
         cin >> syf >> name2 >> syf;
         name2 = name2.substr(0,name2.length()-2);
        // DBG(name2)

         m[mp(name1,name2)] += pts;
         m[mp(name2,name1)] += pts;

         s.insert(name1);
         s.insert(name2);
      }
   }
   
   vector<string> v2(ALL(s));
   FOR(i,v2.size()) {
      val[v2[i]] = 0;
      if (IN(mp(myname,v2[i]),m)) val[v2[i]]= m[mp(myname,v2[i])];
   }
   sort(ALL(v2),mycomp);
   FOR(i,v2.size()) if (v2[i] != myname) cout << v2[i] << endl;
}