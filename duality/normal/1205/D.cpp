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

vi adjList[1000];
int parent[1000],size[1000];
int doDFS(int u,int p) {
    int i;
    parent[u] = p,size[u] = 1;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) size[u] += doDFS(v,u);
    }
    return size[u];
}
int works[1000];
vector<pair<int,set<int> > > vv;
int in[1000];
int doDFS2(int u,int p,vi vv) {
    int i,j,c = 1;
    printf("%d %d %d\n",u+1,p+1,vv[0]);
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v == p) continue;
        vi vv2;
        for (j = 0; j < size[v]; j++) vv2.pb(vv[c++]-vv[0]);
        doDFS2(v,u,vv2);
    }
    return 0;
}
int main() {
    int i;
    int n,u,v;
    scanf("%d",&n);
    for (i = 0; i < n-1; i++) {
        scanf("%d %d",&u,&v);
        u--,v--;
        adjList[u].pb(v);
        adjList[v].pb(u);
    }
    doDFS(0,-1);
    if (n == 1) return 0;

    int j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < adjList[i].size(); j++) {
            int v = adjList[i][j];
            if ((v != parent[i]) && (size[v] > n/2)) break;
            else if ((v == parent[i]) && (n-size[i] > n/2)) break;
        }
        if (j == adjList[i].size()) break;
    }
    int c = i;
    for (i = 0; i < n; i++) {
        if ((i+1)*(n-i)-1 >= 2*n*n/9) works[i] = 1;
    }
    doDFS(c,-1);
    for (i = 0; i < adjList[c].size(); i++) {
        int v = adjList[c][i];
        if (works[size[v]]) break;
        else {
            set<int> S;
            S.insert(v);
            vv.pb(mp(size[v],S));
        }
    }
    vi part;
    if (i < adjList[c].size()) part.pb(adjList[c][i]);
    else {
        while (1) {
            sort(vv.begin(),vv.end());
            reverse(vv.begin(),vv.end());
            for (auto it = vv.back().second.begin(); it != vv.back().second.end(); it++) vv[vv.size()-2].second.insert(*it);
            vv[vv.size()-2].first += vv.back().first;
            vv.pop_back();
            if (works[vv.back().first]) break;
        }
        for (auto it = vv.back().second.begin(); it != vv.back().second.end(); it++) part.pb(*it);
    }
    vi part2;
    int sum = 0;
    for (i = 0; i < part.size(); i++) in[part[i]] = 1;
    for (i = 0; i < adjList[c].size(); i++) {
        if (!in[adjList[c][i]]) part2.pb(adjList[c][i]);
        else sum += size[adjList[c][i]];
    }
    printVar(sum);
    int x = 1;
    for (i = 0; i < part.size(); i++) {
        vi vv;
        for (j = 0; j < size[part[i]]; j++) vv.pb(x++);
        doDFS2(part[i],c,vv);
    }
    x = 1;
    for (i = 0; i < part2.size(); i++) {
        vi vv;
        for (j = 0; j < size[part2[i]]; j++) vv.pb((sum+1)*(x++));
        doDFS2(part2[i],c,vv);
    }
    printArr(part,part.size());
    printArr(part2,part2.size());

    return 0;
}