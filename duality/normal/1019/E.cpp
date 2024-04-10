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

struct edge { int v; LLI m,b; };
vector<edge> adjList[100000];
struct line { LLI m,b; };
bool comp(line a,line b) {
    if (a.m == b.m) return a.b < b.b;
    else return a.m < b.m;
}
int bad(line a,line b,line c) {
    return (long double) (b.b-a.b)/(a.m-b.m) >= (long double) (c.b-b.b)/(b.m-c.m);
}
int size[100000],visited[100000];
vector<line> all,hull;
int doDFS(int u,int p) {
    int i;
    size[u] = 1;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i].v;
        if ((v != p) && !visited[v]) size[u] += doDFS(v,u);
    }
    return size[u];
}
int centroid(int u) {
    int i,r = u,p = -1;
    doDFS(u,-1);
    while (1) {
        int h = -1;
        for (i = 0; i < adjList[u].size(); i++) {
            int v = adjList[u][i].v;
            if ((v != p) && !visited[v] && ((h == -1) || (size[v] > size[h]))) h = v;
        }
        if (((h == -1) || (size[h] <= size[r]/2)) && ((size[r]-size[u] <= size[r]/2))) break;
        else p = u,u = h;
    }
    return u;
}
vector<line> lines[100000],hulls[100000];
int doDFS2(int u,int p,LLI m,LLI b,int c) {
    int i;
    lines[c].pb((line){m,b});
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i].v;
        if ((v != p) && !visited[v]) doDFS2(v,u,m+adjList[u][i].m,b+adjList[u][i].b,c);
    }
    return 0;
}
int decompose(int u) {
    int i,j,k;
    int c = centroid(u),d = 0;
    for (i = 0; i < adjList[c].size(); i++) {
        int v = adjList[c][i].v;
        if (!visited[v]) {
            doDFS2(v,c,adjList[c][i].m,adjList[c][i].b,d);
            sort(lines[d].begin(),lines[d].end(),comp);
            for (j = 0; j < lines[d].size(); j++) {
                while (!hulls[d].empty() && (hulls[d].back().m == lines[d][j].m)) hulls[d].pop_back();
                while ((hulls[d].size() >= 2) && bad(hulls[d][hulls[d].size()-2],hulls[d].back(),lines[d][j])) hulls[d].pop_back();
                hulls[d].pb(lines[d][j]);
            }
            for (j = 0; j < hulls[d].size(); j++) all.pb(hulls[d][j]);
            lines[d++].clear();
        }
    }
    priority_queue<pii> H;
    for (i = 0; i < d; i++) H.push(mp(-hulls[i].size(),i));
    while (H.size() >= 2) {
        int a = H.top().second;
        H.pop();
        int b = H.top().second;
        H.pop();

        i = j = 0;
        while ((i < hulls[a].size()-1) || (j < hulls[b].size()-1)) {
            all.pb((line){hulls[a][i].m+hulls[b][j].m,hulls[a][i].b+hulls[b][j].b});
            if (i == hulls[a].size()-1) j++;
            else if (j == hulls[b].size()-1) i++;
            else {
                if ((long double) (hulls[a][i+1].b-hulls[a][i].b)/(hulls[a][i].m-hulls[a][i+1].m) < \
                    (long double) (hulls[b][j+1].b-hulls[b][j].b)/(hulls[b][j].m-hulls[b][j+1].m)) i++;
                else j++;
            }
        }
        all.pb((line){hulls[a][i].m+hulls[b][j].m,hulls[a][i].b+hulls[b][j].b});
        vector<line> hull;
        i = j = 0;
        while ((i < hulls[a].size()) || (j < hulls[b].size())) {
            line l;
            if (i == hulls[a].size()) l = hulls[b][j],j++;
            else if (j == hulls[b].size()) l = hulls[a][i],i++;
            else if (comp(hulls[a][i],hulls[b][j])) l = hulls[a][i],i++;
            else l = hulls[b][j],j++;
            while (!hull.empty() && (hull.back().m == l.m)) hull.pop_back();
            while ((hull.size() >= 2) && bad(hull[hull.size()-2],hull.back(),l)) hull.pop_back();
            hull.pb(l);
        }
        hulls[a] = hull,hulls[b].clear();
        H.push(mp(-hulls[a].size(),a));
    }
    for (j = 0; j < d; j++) hulls[j].clear();
    visited[c] = 1;
    for (i = 0; i < adjList[c].size(); i++) {
        int v = adjList[c][i].v;
        if (!visited[v]) decompose(v);
    }
    return 0;
}
int main() {
    int i;
    int n,m;
    int u,v,a,b;
    scanf("%d %d",&n,&m);
    for (i = 0; i < n-1; i++) {
        scanf("%d %d %d %d",&u,&v,&a,&b);
        u--,v--;
        adjList[u].pb((edge){v,a,b});
        adjList[v].pb((edge){u,a,b});
    }
    if (n == 1) {
        for (i = 0; i < m; i++) printf("0%c",(i == m-1) ? '\n':' ');
        return 0;
    }
    decompose(0);

    sort(all.begin(),all.end(),comp);
    for (i = 0; i < all.size(); i++) {
        while (!hull.empty() && (hull.back().m == all[i].m)) hull.pop_back();
        while ((hull.size() >= 2) && bad(hull[hull.size()-2],hull.back(),all[i])) hull.pop_back();
        hull.pb(all[i]);
    }
    int p = 0;
    for (i = 0; i < m; i++) {
        while ((p < hull.size()-1) && (hull[p].m*i+hull[p].b <= hull[p+1].m*i+hull[p+1].b)) p++;
        printf("%I64d%c",hull[p].m*i+hull[p].b,(i == m-1) ? '\n':' ');
    }

    return 0;
}