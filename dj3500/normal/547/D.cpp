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

const int N = 400400, P = 200100;
char res[N];
struct Edge {
    int a, b, num;
    bool used;
    Edge (int _a, int _b, int _num) : a(_a), b(_b), num(_num), used(0) {}
    void ustaw (bool col) {
        res[num] = col ? 'r' : 'b';
        used = 1;
    }
};
vector<Edge*> adj[N], all;

void go (int v, bool col) {
    while (!adj[v].empty() && adj[v].back()->used) adj[v].pop_back();
    if (adj[v].empty()) return;
    Edge *e = adj[v].back();
    e->ustaw(col);
    int nxt = e->a + e->b - v;
    go(nxt, !col);
}

int main () {
    wez(m)
    FORI(i,m) {
        wez2(a,b)
        b += P;
        Edge *e = new Edge(a,b,i);
        adj[a].pb(e);
        adj[b].pb(e);
        all.pb(e);
    }
    res[m+1] = 0;
    while (1) {
        while (!all.empty() && all.back()->used) all.pop_back();
        if (all.empty()) break;
        Edge *e = all.back();
        e->ustaw(1);
        go(e->a, 0);
        go(e->b, 0);
    }
    printf("%s", res+1);
}