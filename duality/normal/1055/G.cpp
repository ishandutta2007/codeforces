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

int px[200],py[200],x[200],y[200],r[200];
struct edge { int v,c,r; };
vector<edge> adjList[402];
int addEdge(int u,int v,int c) {
    adjList[u].pb((edge){v,c,adjList[v].size()});
    adjList[v].pb((edge){u,0,adjList[u].size()-1});
    return 0;
}
vpii vv,hull;
int ccw(pii a,pii b,pii c) {
    return (LLI) (b.x-a.x)*(c.y-a.y) >= (LLI) (b.y-a.y)*(c.x-a.x);
}
int dist[402];
queue<int> Q;
int doBFS(int n) {
    int i;
    fill(dist,dist+n,-1);
    dist[0] = 0,Q.push(0);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        for (i = 0; i < adjList[u].size(); i++) {
            int v = adjList[u][i].v;
            if ((adjList[u][i].c > 0) && (dist[v] == -1)) {
                dist[v] = dist[u]+1;
                Q.push(v);
            }
        }
    }
    return dist[1] != -1;
}
int work[402];
int doDFS(int u,int f) {
    if (u == 1) return f;
    int &i = work[u];
    for (; i < adjList[u].size(); i++) {
        int v = adjList[u][i].v;
        if ((adjList[u][i].c > 0) && (dist[v] == dist[u]+1)) {
            int df = doDFS(v,min(f,adjList[u][i].c));
            if (df > 0) {
                adjList[u][i].c -= df;
                adjList[v][adjList[u][i].r].c += df;
                return df;
            }
        }
    }
    return 0;
}
int main() {
    int i;
    int n,w,m;
    scanf("%d %d",&n,&w);
    for (i = 0; i < n; i++) scanf("%d %d",&px[i],&py[i]);
    scanf("%d",&m);
    for (i = 0; i < m; i++) scanf("%d %d %d",&x[i],&y[i],&r[i]);

    int j,k;
    int diam = *max_element(px,px+n)-*min_element(px,px+n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) vv.pb(mp(px[i]-px[j],py[i]-py[j]));
    }
    sort(vv.begin(),vv.end());
    vv.resize(unique(vv.begin(),vv.end())-vv.begin());
    for (i = 0; i < vv.size(); i++) {
        while ((hull.size() >= 2) && ccw(hull[hull.size()-2],hull.back(),vv[i])) hull.pop_back();
        hull.pb(vv[i]);
    }
    int l = hull.size();
    for (i = vv.size()-2; i >= 0; i--) {
        while ((hull.size() > l) && ccw(hull[hull.size()-2],hull.back(),vv[i])) hull.pop_back();
        hull.pb(vv[i]);
    }
    for (i = 0; i < m; i++) {
        if (x[i]-r[i] < diam) addEdge(0,2*i+2,1e9);
        if (w-(x[i]+r[i]) < diam) addEdge(2*i+3,1,1e9);
        addEdge(2*i+2,2*i+3,1);
    }
    for (i = 0; i < m; i++) {
        for (j = 0; j < m; j++) {
            if (i != j) {
                pii v = mp(x[j]-x[i],y[j]-y[i]);
                for (k = 0; k < hull.size()-1; k++) {
                    if (ccw(mp(0,0),v,hull[k]) && ccw(mp(0,0),hull[k+1],v)) {
                        LLI area = (LLI) (hull[k+1].x-hull[k].x)*(v.y-hull[k].y)-(LLI) (hull[k+1].y-hull[k].y)*(v.x-hull[k].x);
                        if (area <= 0) break;
                        LLI dot1 = (LLI) (hull[k+1].x-hull[k].x)*(v.x-hull[k].x)+(LLI) (hull[k+1].y-hull[k].y)*(v.y-hull[k].y);
                        LLI dot2 = (LLI) (hull[k].x-hull[k+1].x)*(v.x-hull[k+1].x)+(LLI) (hull[k].y-hull[k+1].y)*(v.y-hull[k+1].y);
                        if ((dot1 >= 0) && (dot2 >= 0)) {
                            LLI d = (LLI) (hull[k+1].x-hull[k].x)*(hull[k+1].x-hull[k].x)+(LLI) (hull[k+1].y-hull[k].y)*(hull[k+1].y-hull[k].y);
                            d *= (LLI) (r[i]+r[j])*(r[i]+r[j]);
                            if (area*area < d) break;
                        }
                    }
                    LLI d = (LLI) (hull[k].x-v.x)*(hull[k].x-v.x)+(LLI) (hull[k].y-v.y)*(hull[k].y-v.y);
                    if (d < (LLI) (r[i]+r[j])*(r[i]+r[j])) break;
                }
                if (k < hull.size()-1) addEdge(2*i+3,2*j+2,1);
            }
        }
    }
    int mf = 0,f;
    while (doBFS(2*m+2)) {
        fill(work,work+2*m+2,0);
        while ((f=doDFS(0,1e9)) > 0) mf += f;
    }
    printf("%d\n",mf);

    return 0;
}