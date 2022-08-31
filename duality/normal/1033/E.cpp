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

map<vi,int> M;
int query(vi v) {
    if (v.size() <= 1) return 0;
    sort(v.begin(),v.end());
    if (M.count(v)) return M[v];
    int i;
    cout << "? " << v.size() << endl;
    for (i = 0; i < v.size(); i++) cout << v[i]+1 << " ";
    cout << endl;
    int m;
    cin >> m;
    M[v] = m;
    return m;
}
vi tree[600];
vector<vi> com;
vi yes;
int findCom(int l,int r,int x) {
    if (l == r) {
        yes.pb(l);
        return 0;
    }

    int i,j;
    int m = (l+r) / 2;
    vi v;
    for (i = l; i <= m; i++) {
        for (j = 0; j < com[i].size(); j++) v.pb(com[i][j]);
    }
    int a = query(v);
    v.pb(x);
    int b = query(v);
    if (b > a) findCom(l,m,x);
    v.clear();
    for (i = m+1; i <= r; i++) {
        for (j = 0; j < com[i].size(); j++) v.pb(com[i][j]);
    }
    a = query(v);
    v.pb(x);
    b = query(v);
    if (b > a) findCom(m+1,r,x);
    return 0;
}
int findEdge(vi &vv,int l,int r,int x) {
    if (l == r) return vv[l];

    int i;
    int m = (l+r) / 2;
    vi v;
    for (i = l; i <= m; i++) v.pb(vv[i]);
    int a = query(v);
    v.pb(x);
    int b = query(v);
    if (b > a) return findEdge(vv,l,m,x);
    else return findEdge(vv,m+1,r,x);
}
int colour[600];
int doDFS(int u,int p,int c) {
    int i;
    colour[u] = c;
    for (i = 0; i < tree[u].size(); i++) {
        int v = tree[u][i];
        if (v != p) doDFS(v,u,!c);
    }
    return 0;
}
vi path;
int getPath(int u,int p,int e) {
    path.pb(u);
    if (u == e) return 1;
    int i;
    for (i = 0; i < tree[u].size(); i++) {
        int v = tree[u][i];
        if (v != p) {
            if (getPath(v,u,e)) return 1;
        }
    }
    path.pop_back();
    return 0;
}
int main() {
    int n;
    cin >> n;

    int i,j,k;
    com.pb(vi());
    com.back().pb(0);
    for (i = 1; i < n; i++) {
        vi v;
        for (j = 0; j < i; j++) v.pb(j);
        int a = query(v);
        v.pb(i);
        int b = query(v);
        if (a == b) com.pb(vi()),com.back().pb(i);
        else {
            findCom(0,com.size()-1,i);
            for (j = 0; j < yes.size(); j++) {
                int u = findEdge(com[yes[j]],0,com[yes[j]].size()-1,i);
                tree[i].pb(u),tree[u].pb(i);
                if (j > 0) {
                    for (k = 0; k < com[yes[j]].size(); k++) com[yes[0]].pb(com[yes[j]][k]);
                    com[yes[j]].clear();
                }
            }
            com[yes[0]].pb(i);
            while (com.back().empty()) com.pop_back();
            for (j = 0; j < com.size(); j++) {
                if (com[j].empty()) {
                    swap(com[j],com.back());
                    while (com.back().empty()) com.pop_back();
                }
            }
        }
        yes.clear();
    }
    doDFS(0,-1,0);
    vi l,r;
    for (i = 0; i < n; i++) {
        if (colour[i]) r.pb(i);
        else l.pb(i);
    }
    if (query(l) > 0) {
        for (i = 0; i < l.size(); i++) {
            vi v;
            for (j = 0; j < l.size(); j++) {
                if (j != i) v.pb(l[j]);
            }
            int a = query(v);
            v.pb(l[i]);
            int b = query(v);
            if (b > a) {
                v.pop_back();
                int u = findEdge(v,0,v.size()-1,l[i]);
                getPath(u,-1,l[i]);
                break;
            }
        }
        printf("N %d\n",path.size());
        for (i = 0; i < path.size(); i++) printf("%d ",path[i]+1);
        printf("\n");
    }
    else if (query(r) > 0) {
        for (i = 0; i < r.size(); i++) {
            vi v;
            for (j = 0; j < r.size(); j++) {
                if (j != i) v.pb(r[j]);
            }
            int a = query(v);
            v.pb(r[i]);
            int b = query(v);
            if (b > a) {
                v.pop_back();
                int u = findEdge(v,0,v.size()-1,r[i]);
                getPath(u,-1,r[i]);
                break;
            }
        }
        printf("N %d\n",path.size());
        for (i = 0; i < path.size(); i++) printf("%d ",path[i]+1);
        printf("\n");
    }
    else {
        printf("Y %d\n",l.size());
        for (i = 0; i < l.size(); i++) printf("%d ",l[i]+1);
        printf("\n");
    }

    return 0;
}