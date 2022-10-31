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

    #define MAXN 300005
    int n,          // input
    t[MAXN],        // output
    ttr[MAXN],      // temp
    n2;             // output
    vi adj[MAXN],   // input
    adjtr[MAXN],    // temp
    adj2[MAXN];     // output


    void scc_dfs1(int v, int nr, vi &vis) {
       t[v] = 1;
       FOREACH(it,adj[v]) if (t[*it] == -1) scc_dfs1(*it, nr, vis);
       vis.pb(v);
    }
    void scc_dfs2(int v, int nr, vi &vistr) {
       ttr[v] = 1;
       vistr[v] = nr;
       FOREACH(it,adjtr[v]) {
          if (ttr[*it] == -1) scc_dfs2(*it, nr, vistr);
          else if (nr > vistr[*it]) adj2[ttr[*it]+1].pb((vistr[*it] = nr)+1);
       }
       ttr[v] = nr;
    }
    void scc() {
       vi vis, vistr(n+1,-1);
       FORI(i,n) {
          adjtr[i].clear();
          adj2[i].clear();
       }
       FORI(i,n) FOREACH(it,adj[i]) adjtr[*it].pb(i); // graf transponowany
       
       FORI(i,n) t[i] = -1;
       n2 = 0;
       REPD(j,n,1) if (t[j] == -1) scc_dfs1(j, n2++, vis);
       
       FORI(i,n) ttr[i] = -1;
       n2 = 0;
       REPD(j,n-1,0) if (ttr[vis[j]] == -1) scc_dfs2(vis[j], n2++, vistr);
       
       FORI(i,n) t[i] = ttr[i]+1;
    }


    vi adjorig[MAXN];
    int from[MAXN], to[MAXN];
    bool done[MAXN], doneedge[MAXN];
    int dodane = 0;

    void dfs (int skad, int v) {
       //DBG(mp(skad,v))
       if (skad != -1) {
          ++dodane;
          adj[skad].pb(v);
       }
       if (done[v]) return;
       done[v] = 1;
       FOREACH(it,adjorig[v]) {
          if (!doneedge[*it]) {
             doneedge[*it] = 1;
             int otherend = to[*it];
             if (otherend == v) otherend = from[*it];
             dfs(v,otherend);
          }
       }
    }

    int main () {
       scanf("%d",&n);
       wez(m)
       FOR(i,m) {
          scanf("%d %d",from+i,to+i);
          adjorig[from[i]].pb(i);
          adjorig[to[i]].pb(i);
       }
       
       FORI(i,n) done[i] = 0;
       FOR(i,m) doneedge[i] = 0;
       dfs(-1,1);
       
       if (dodane != m) {
          //cerr << "dodane != m" << endl;
          pisz(0);
          return 0;
       }
       
       scc();
       
       if (n2 != 1) {
          //cerr << "n2 != 1" << endl;
          pisz(0);
          return 0;
       }
       
       FORI(i,n) FOREACH(it,adj[i]) printf("%d %d\n",i,*it);
    }