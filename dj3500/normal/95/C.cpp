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
#define INF 2147483647
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

const ll infty = 1000000000000000000LL;
int n;
ll ww[1006][1006];
 
int acts;
struct cmp
{
    bool operator() (const int &a, const int &b) const
    {
        if (ww[acts][a] < ww[acts][b]) return true;
        if (ww[acts][a] > ww[acts][b]) return false;
        return a<b;
    }
};
 
 
 
 
void dijkstra(int s, vector< pair<int,ll> > *adj) {
    FOR(i,n+1) ww[s][i] = infty;
    acts = s;
 
    ww[s][s] = 0;
    set<int, cmp> kopiec;
    for (int i=0; i<=n; i++) kopiec.insert(i);
 
    while( !kopiec.empty() )
    {
        int u = *(kopiec.begin());
        kopiec.erase(kopiec.begin());
 
        for (int i=0; i<adj[u].size(); i++)
        {
            int v = adj[u][i].first;
            ll c = adj[u][i].second;
            if (ww[s][u]+c < ww[s][v]) {
                kopiec.erase(kopiec.find(v));
                ww[s][v] = ww[s][u]+c;
                kopiec.insert(v);
            }
        }
    }
 
 
}
vector< pair<int,ll> > adj1[1006], adj2[1006];


int main () {
   wez2(nn,m)
   wez2(x,y)
   FOR(i,m) {
      wez3(a,b,c)
      adj1[a].pb(mp(b,c));
      adj1[b].pb(mp(a,c));
   }
   
   n = nn;
   
   FORI(i,n) dijkstra(i,adj1);
   //FORI(i,n) DBG(vector<ll>(ww[i]+1,ww[i]+n+1))
   
   FORI(i,n) {
      wez2(ti,ci)
      FORI(j,n) if (i != j) {
         if (ww[i][j] <= ti) {
            adj2[i].pb(mp(j,ci));
         }
      }
   }
   dijkstra(x,adj2);
   
   if (ww[x][y] == infty) printf("-1\n");
   else cout << ww[x][y] << endl;
}