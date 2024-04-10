#define DEBUG 1

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

struct edge { int u,v; char a,b; };
vector<edge> edges;
vector<string> ss[105];
int occ[26],occ2[26];
set<pii> done;
int query(int l,int r) {
    if (done.count(mp(l,r))) return 0;
    done.insert(mp(l,r));
    cout << "? " << l+1 << " " << r+1 << endl;
    int i,j,k,x = r-l+1;
    string s;
    for (i = 0; i < 105; i++) ss[i].clear();
    for (i = 0; i < x*(x+1)/2; i++) {
        cin >> s;
        ss[s.size()].pb(s);
    }
    memset(occ,0,sizeof(occ));
    for (i = 0; i < ss[1].size(); i++) occ[ss[1][i][0]-'a']++;
    vector<pair<char,char> > vv;
    for (i = 2; i <= (x+1)/2; i++) {
        memset(occ2,0,sizeof(occ2));
        for (j = 0; j < ss[i].size(); j++) {
            for (k = 0; k < ss[i][j].size(); k++) occ2[ss[i][j][k]-'a']++;
        }
        //printArr(occ2,6);
        for (j = 0; j < vv.size(); j++) {
            occ2[vv[j].first-'a'] -= j+1;
            occ2[vv[j].second-'a'] -= j+1;
        }
        vector<char> v;
        for (j = 0; j < 26; j++) {
            if (i*occ[j] > occ2[j]) {
                for (k = 0; k < i*occ[j]-occ2[j]; k++) v.pb(j+'a');
            }
        }
        edges.pb((edge){l+i-2,r-i+2,v[0],v[1]});
        vv.pb(mp(v[0],v[1]));
        occ[v[0]-'a']--,occ[v[1]-'a']--;
    }
    if (x & 1) {
        for (i = 0; i < 26; i++) {
            if (occ[i] > 0) break;
        }
        edges.pb((edge){(l+r)/2,(l+r)/2,i+'a',i+'a'});
    }
    else {
        vector<char> v;
        for (i = 0; i < 26; i++) {
            for (j = 0; j < occ[i]; j++) v.pb(i+'a');
        }
        edges.pb((edge){(l+r-1)/2,(l+r+1)/2,v[0],v[1]});
    }
    return 0;
}
int getEdge(int u,int v) {
    int i;
    for (i = 0; i < edges.size(); i++) {
        if ((edges[i].u == u) && (edges[i].v == v)) return edges[i].a+edges[i].b;
    }
    return 0;
}
char ans[100];
vpii adjList[100];
int doDFS(int u) {
    int i;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i].first;
        if (ans[v] == '?') {
            ans[v] = adjList[u][i].second-ans[u];
            doDFS(v);
        }
    }
    return 0;
}
int main() {
    int i;
    int n;
    cin >> n;

    query(0,n-1);
    if (n == 1) {
        cout << "! " << edges[0].a << endl;
        return 0;
    }
    int c;
    //for(i=0;i<edges.size();i++)cout<<edges[i].u<<","<<edges[i].v<<","<<edges[i].a<<","<<edges[i].b<<endl;
    if (n & 1) query(0,(n-3)/2),query((n-3)/2,n-1),c = (n-3)/2;
    else query(0,(n-2)/2),query((n-2)/2,n-1),c = (n-2)/2;
    //for(i=0;i<edges.size();i++)cout<<edges[i].u<<","<<edges[i].v<<","<<edges[i].a<<","<<edges[i].b<<endl;
    memset(ans,'?',sizeof(ans));
    for (i = 0; i < edges.size(); i++) {
        if (edges[i].u == edges[i].v) ans[edges[i].u] = edges[i].a;
        adjList[edges[i].u].pb(mp(edges[i].v,edges[i].a+edges[i].b));
        adjList[edges[i].v].pb(mp(edges[i].u,edges[i].a+edges[i].b));
    }
    int x = getEdge(0,c);
    int y = getEdge(c,n-1);
    int z = getEdge(0,n-1);
    int all = (x+y+z)/2;
    ans[0] = all-y,ans[n-1] = all-x,ans[c] = all-z;
    for (i = 0; i < n; i++) {
        if (ans[i] != '?') doDFS(i);
    }
    cout << "! ";
    for (i = 0; i < n; i++) cout << ans[i];
    cout << endl;

    return 0;
}