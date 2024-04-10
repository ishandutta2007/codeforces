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

LLI a[300000];
int parent[300000];
int uu[300000],vv[300000];
set<pii> poss[300000];
int find(int n) {
    if (parent[n] != n) parent[n] = find(parent[n]);
    return parent[n];
}
vi ans;
queue<int> Q;
int main() {
    int i;
    int n,m,x;
    int u,v;
    scanf("%d %d %d",&n,&m,&x);
    for (i = 0; i < n; i++) scanf("%I64d",&a[i]);
    for (i = 0; i < m; i++) {
        scanf("%d %d",&u,&v);
        u--,v--;
        uu[i] = u,vv[i] = v;
        poss[u].insert(mp(v,i));
        poss[v].insert(mp(u,i));
    }

    for (i = 0; i < n; i++) parent[i] = i;
    for (i = 0; i < n; i++) {
        if (a[i] >= x) Q.push(i);
    }
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        auto it = poss[u].begin();
        while ((a[find(u)] >= x) && (it != poss[u].end())) {
            if (find(it->first) == find(u)) it = poss[u].erase(it);
            else {
                ans.pb(it->second);
                int p = find(it->first),q = find(u);
                parent[p] = q;
                a[q] += a[p]-x;
                if (poss[q].size() < poss[p].size()) swap(poss[p],poss[q]);
                for (auto it2 = poss[p].begin(); it2 != poss[p].end(); it2++) poss[q].insert(*it2);
                poss[p].clear();
                if (a[q] >= x) Q.push(q);
                break;
            }
        }
    }
    for (i = 0; i < m; i++) {
        if (find(uu[i]) != find(vv[i])) {
            if (a[find(uu[i])]+a[find(vv[i])] >= x) {
                ans.pb(i);
                int p = find(uu[i]),q = find(vv[i]);
                parent[p] = q;
                a[q] += a[p]-x;
            }
        }
    }
    for (i = 0; i < n; i++) {
        if (find(i) != find(0)) break;
    }
    if (i == n) {
        printf("YES\n");
        for (i = 0; i < ans.size(); i++) printf("%d\n",ans[i]+1);
    }
    else printf("NO\n");

    return 0;
}