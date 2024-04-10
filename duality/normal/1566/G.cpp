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

set<pair<LLI,int> > adjList[200000];
map<pii,LLI> edges;
set<pair<LLI,pii> > S;
set<pair<LLI,int> > S2;
int distinct(int a,int b,int c,int d) {
    return (a != b) && (a != c) && (a != d) && (b != c) && (b != d) && (c != d);
}
LLI getAns() {
    LLI ans = 9e18;
    if (!S2.empty()) ans = min(ans,S2.begin()->first);
    int x = 0;
    vector<pair<LLI,pii> > vv;
    for (pair<LLI,pii> p: S) {
        vv.pb(p);
        x++;
        if (x >= 20) break;
    }
    int i,j;
    for (i = 0; i < vv.size(); i++) {
        for (j = i+1; j < vv.size(); j++) {
            if (distinct(vv[i].second.first,vv[i].second.second,vv[j].second.first,vv[j].second.second))
                ans = min(ans,(LLI) vv[i].first+vv[j].first);
        }
    }
    return ans;
}
int good(int v,pair<LLI,int> x) {
    int c = 0;
    for (pair<LLI,int> p: adjList[v]) {
        if (p == x) return 1;
        c++;
        if (c >= 3) break;
    }
    return 0;
}
int add(int i) {
    int x = 0;
    LLI sum = 0;
    for (pair<LLI,int> p: adjList[i]) {
        if (good(p.second,mp(p.first,i))) S.insert(mp(p.first,mp(min(i,p.second),max(i,p.second))));
        sum += p.first;
        x++;
        if (x >= 3) break;
    }
    if (x == 3) S2.insert(mp(sum,i));
    return 0;
}
int del(int i) {
    int x = 0;
    LLI sum = 0;
    for (pair<LLI,int> p: adjList[i]) {
        S.erase(mp(p.first,mp(min(i,p.second),max(i,p.second))));
        sum += p.first;
        x++;
        if (x >= 3) break;
    }
    if (x == 3) S2.erase(mp(sum,i));
    return 0;
}
int main() {
    int i;
    int n,m,q;
    int t,u,v;
    LLI w;
    scanf("%d %d",&n,&m);
    for (i = 0; i < m; i++) {
        scanf("%d %d %I64d",&u,&v,&w);
        w = w*((LLI) 1e9)+i;
        u--,v--;
        if (u > v) swap(u,v);
        adjList[u].insert(mp(w,v));
        adjList[v].insert(mp(w,u));
        edges[mp(u,v)] = w;
    }
    for (i = 0; i < n; i++) add(i);
    scanf("%d",&q);
    printf("%I64d\n",getAns()/((LLI) 1e9));
    for (i = m; i < m+q; i++) {
        scanf("%d",&t);
        if (t == 0) {
            scanf("%d %d",&u,&v);
            u--,v--;
            if (u > v) swap(u,v);
            w = edges[mp(u,v)];
            edges.erase(mp(u,v));
            del(u),del(v);
            adjList[u].erase(mp(w,v));
            adjList[v].erase(mp(w,u));
            add(u),add(v);
        }
        else {
            scanf("%d %d %I64d",&u,&v,&w);
            u--,v--;
            if (u > v) swap(u,v);
            w = w*((LLI) 1e9)+i;
            edges[mp(u,v)] = w;
            del(u),del(v);
            adjList[u].insert(mp(w,v));
            adjList[v].insert(mp(w,u));
            add(u),add(v);
        }
        printf("%I64d\n",getAns()/((LLI) 1e9));
    }

    return 0;
}