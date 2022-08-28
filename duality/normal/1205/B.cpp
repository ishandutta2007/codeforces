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

LLI a[100000];
vpii edges;
vi sorted;
vi adjList[200];
int dist[200];
queue<int> Q;
int main() {
    int i;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%I64d",&a[i]);

    int j;
    for (i = 0; i < 62; i++) {
        vi v;
        for (j = 0; j < n; j++) {
            if (a[j] & (1LL << i)) v.pb(j);
        }
        if (v.size() >= 3) {
            printf("3\n");
            return 0;
        }
        else if (v.size() == 2) edges.pb(mp(v[0],v[1]));
    }
    for (i = 0; i < edges.size(); i++) sorted.pb(edges[i].first),sorted.pb(edges[i].second);
    sort(sorted.begin(),sorted.end());
    sorted.resize(unique(sorted.begin(),sorted.end())-sorted.begin());
    for (i = 0; i < edges.size(); i++) {
        edges[i].first = lower_bound(sorted.begin(),sorted.end(),edges[i].first)-sorted.begin();
        edges[i].second = lower_bound(sorted.begin(),sorted.end(),edges[i].second)-sorted.begin();
    }
    sort(edges.begin(),edges.end());
    edges.resize(unique(edges.begin(),edges.end())-edges.begin());
    int ans = 1e9;
    for (i = 0; i < edges.size(); i++) {
        for (j = i+1; j < edges.size(); j++) {
            adjList[edges[j].first].pb(edges[j].second);
            adjList[edges[j].second].pb(edges[j].first);
        }
        fill(dist,dist+sorted.size(),-1);
        dist[edges[i].first] = 0,Q.push(edges[i].first);
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();

            for (j = 0; j < adjList[u].size(); j++) {
                int v = adjList[u][j];
                if (dist[v] == -1) {
                    dist[v] = dist[u]+1;
                    Q.push(v);
                }
            }
        }
        if (dist[edges[i].second] != -1) ans = min(ans,dist[edges[i].second]+1);
        for (j = 0; j < sorted.size(); j++) adjList[j].clear();
    }
    if (ans == 1e9) printf("-1\n");
    else printf("%d\n",ans);

    return 0;
}