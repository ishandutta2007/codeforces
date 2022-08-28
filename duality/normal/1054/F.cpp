#define DEBUG 0

#include <bits/stdc++.h>
using namespace std;

#if DEBUG
// basic debugging macros
int __i__,__j__;
#define printLine(l) for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl
#define printLine2(l,c) for(__i__=0;__i__<l;__i__++){cout<<c;}cout<<endl
#define printVar(n) cout<<#n<<": "<<n<<endl
#define printArr(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<endl
#define print2dArr(a,r,c) cout<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<endl;}
#define print2dArr2(a,r,c,l) cout<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<setw(l)<<setfill(' ')<<a[__i__][__j__]<<" ";}cout<<endl;}

// advanced debugging class
// debug 1,2,'A',"test";
class _Debug {
    public:
        template<typename T>
        _Debug& operator,(T val) {
            cout << val << endl;
            return *this;
        }
};
#define debug _Debug(),
#else
#define printLine(l)
#define printLine2(l,c)
#define printVar(n)
#define printArr(a,l)
#define print2dArr(a,r,c)
#define print2dArr2(a,r,c,l)
#define debug
#endif

// define
#define MAX_VAL 999999999
#define MAX_VAL_2 999999999999999999LL
#define EPS 1e-6
#define mp make_pair
#define pb push_back

// typedef
typedef unsigned int UI;
typedef long long int LLI;
typedef unsigned long long int ULLI;
typedef unsigned short int US;
typedef pair<int,int> pii;
typedef pair<LLI,LLI> plli;
typedef vector<int> vi;
typedef vector<LLI> vlli;
typedef vector<pii> vpii;
typedef vector<plli> vplli;

// ---------- END OF TEMPLATE ----------
#define x first
#define y second

pii p[1000];
vpii h,v;
vi adjList[2000];
int match[2000];
int visited[2000];
int augment(int u) {
    if (visited[u]) return 0;

    int i;
    visited[u] = 1;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if ((match[v] == -1) || augment(match[v])) {
            match[u] = v,match[v] = u;
            return 1;
        }
    }

    return 0;
}
int ind[2000];
queue<int> Q;
pair<pii,int> order[2000];
int Mh[2000],Mv[2000];
vpii hor,ver;
int main() {
    int i;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d %d",&p[i].x,&p[i].y);

    int j;
    for (i = 0; i < n; i++) {
        int mi = -1;
        for (j = 0; j < n; j++) {
            if ((p[j].y == p[i].y) && (p[j].x > p[i].x)) {
                if ((mi == -1) || (p[j].x < p[mi].x)) mi = j;
            }
        }
        if (mi != -1) h.pb(mp(i,mi));
        mi = -1;
        for (j = 0; j < n; j++) {
            if ((p[j].x == p[i].x) && (p[j].y > p[i].y)) {
                if ((mi == -1) || (p[j].y < p[mi].y)) mi = j;
            }
        }
        if (mi != -1) v.pb(mp(i,mi));
    }
    for (i = 0; i < h.size(); i++) {
        for (j = 0; j < v.size(); j++) {
            if ((p[h[i].first].x < p[v[j].first].x) && (p[v[j].first].x < p[h[i].second].x) \
                && (p[v[j].first].y < p[h[i].first].y) && (p[h[i].first].y < p[v[j].second].y)) {

                adjList[i].pb(j+h.size());
                adjList[j+h.size()].pb(i);
            }
        }
    }
    for (i = 0; i < h.size()+v.size(); i++) match[i] = -1;
    for (i = 0; i < h.size(); i++) {
        for (j = 0; j < h.size()+v.size(); j++) visited[j] = 0;
        augment(i);
    }
    fill(ind,ind+h.size()+v.size(),-1);
    for (i = 0; i < h.size()+v.size(); i++) {
        if (match[i] == -1) ind[i] = 1,Q.push(i);
    }
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        if (ind[u] == 1) {
            for (i = 0; i < adjList[u].size(); i++) {
                int v = adjList[u][i];
                if (ind[v] == -1) ind[v] = 0,Q.push(v);
            }
        }
        else {
            if ((match[u] != -1) && (ind[match[u]] == -1)) ind[match[u]] = 1,Q.push(match[u]);
        }
    }
    for (i = 0; i < n; i++) Mh[i] = Mv[i] = -1;
    for (i = 0; i < h.size()+v.size(); i++) {
        if (ind[i] == -1) ind[i] = (i < h.size());
        if (ind[i]) {
            if (i < h.size()) Mh[h[i].first] = h[i].second;
            else Mv[v[i-h.size()].first] = v[i-h.size()].second;
        }
    }
    fill(visited,visited+n,0);
    for (i = 0; i < n; i++) order[i] = mp(p[i],i);
    sort(order,order+n);
    for (i = 0; i < n; i++) {
        int w = order[i].second;
        if (visited[w]) continue;
        int u = w;
        visited[u] = 1;
        while (Mh[u] != -1) u = Mh[u],visited[u] = 1;
        hor.pb(mp(w,u));
    }
    fill(visited,visited+n,0);
    for (i = 0; i < n; i++) order[i] = mp(mp(p[i].y,p[i].x),i);
    sort(order,order+n);
    for (i = 0; i < n; i++) {
        int w = order[i].second;
        if (visited[w]) continue;
        int u = w;
        visited[u] = 1;
        while (Mv[u] != -1) u = Mv[u],visited[u] = 1;
        ver.pb(mp(w,u));
    }
    printf("%d\n",hor.size());
    for (i = 0; i < hor.size(); i++) printf("%d %d %d %d\n",p[hor[i].first].x,p[hor[i].first].y,p[hor[i].second].x,p[hor[i].second].y);
    printf("%d\n",ver.size());
    for (i = 0; i < ver.size(); i++) printf("%d %d %d %d\n",p[ver[i].first].x,p[ver[i].first].y,p[ver[i].second].x,p[ver[i].second].y);

    return 0;
}