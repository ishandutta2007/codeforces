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

int n;
pii nodes[500];
vpii edges;
vi adjList[500];
int good[500];
int parent[500],size[500];
int doDFS(int u,int p) {
    int i;
    parent[u] = p,size[u] = 1;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (good[v] && (v != p)) size[u] += doDFS(v,u);
    }
    return size[u];
}
vi sub[500];
int doDFS2(int u,int p,int c) {
    int i;
    sub[c].pb(u);
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (good[v] && (v != p)) doDFS2(v,u,c);
    }
    return 0;
}
int solve(vi v,int u) {
    if (v.size() == 1) return v[0];
    int i,j;
    fill(good,good+n,0);
    for (i = 0; i < v.size(); i++) good[v[i]] = 1;
    doDFS(v[0],-1);
    for (i = 0; i < v.size(); i++) {
        for (j = 0; j < adjList[v[i]].size(); j++) {
            int x = adjList[v[i]][j];
            if (!good[x]) continue;
            if ((x != parent[v[i]]) && (size[x] > v.size()/2)) break;
            else if ((x == parent[v[i]]) && (v.size()-size[v[i]] > v.size()/2)) break;
        }
        if (j == adjList[v[i]].size()) break;
    }
    int c = v[i],d = 0,r;
    for (i = 0; i < adjList[c].size(); i++) {
        int x = adjList[c][i];
        if (good[x]) sub[d].clear(),doDFS2(x,c,d++);
    }
    cout << 1 << endl << u+1 << endl << v.size()-1 << endl;
    for (i = 0; i < d; i++) {
        for (j = 0; j < sub[i].size(); j++) cout << sub[i][j]+1 << " ";
    }
    cout << endl << c+1 << endl;
    cin >> r;
    if (r == v.size()-1) return c;
    int s = 0,e = d-1;
    while (s < e) {
        int m = (s+e) / 2;

        int sum = 0;
        for (i = s; i <= m; i++) sum += sub[i].size();
        cout << 1 << endl << u+1 << endl << sum << endl;
        for (i = s; i <= m; i++) {
            for (j = 0; j < sub[i].size(); j++) cout << sub[i][j]+1 << " ";
        }
        cout << endl << c+1 << endl;
        cin >> r;
        if (r == sum) s = m+1;
        else e = m;
    }
    return solve(sub[s],u);
}
int main() {
    cin >> n;

    int i,j;
    nodes[0] = mp(n,0);
    for (i = 1; i < n; i++) {
        int r;
        cout << 1 << endl << 1 << endl << n-1 << endl;
        for (j = 1; j < n; j++) cout << j+1 << " ";
        cout << endl << i+1 << endl;
        cin >> r;
        nodes[i] = mp(r,i);
    }
    sort(nodes,nodes+n,greater<pii>());
    for (i = 1; i < n; i++) {
        vi v;
        for (j = 0; j < i; j++) v.pb(nodes[j].second);
        int p = solve(v,nodes[i].second);
        edges.pb(mp(p,nodes[i].second));
        adjList[p].pb(nodes[i].second),adjList[nodes[i].second].pb(p);
    }
    cout << "ANSWER" << endl;
    for (i = 0; i < edges.size(); i++) cout << edges[i].first+1 << " " << edges[i].second+1 << endl;

    return 0;
}