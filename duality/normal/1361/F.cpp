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
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int n,P[200000],W[200000];
int mm[400000],parent[400000],num;
LLI inv[400000],ans = 0;
ordered_set L[400000],R[400000];
int build(int s,int e) {
    if (s == e) return s;

    int i,m = s;
    for (i = s; i < e; i++) {
        if (W[i] < W[m]) m = i;
    }
    int l = build(s,m),r = build(m+1,e);
    parent[l] = parent[r] = num,mm[num] = m;
    if (l < n) L[num].insert(P[l]);
    else {
        for (auto it = L[l].begin(); it != L[l].end(); it++) L[num].insert(*it);
        for (auto it = R[l].begin(); it != R[l].end(); it++) L[num].insert(*it);
    }
    if (r < n) inv[num] += L[num].order_of_key(P[r]),R[num].insert(P[r]);
    else {
        for (auto it = L[r].begin(); it != L[r].end(); it++) inv[num] += L[num].order_of_key(*it),R[num].insert(*it);
        for (auto it = R[r].begin(); it != R[r].end(); it++) inv[num] += L[num].order_of_key(*it),R[num].insert(*it);
    }
    ans += min(inv[num],(LLI) ((LLI) L[num].size()*R[num].size()-inv[num]));
    return num++;
}
int main() {
    int i;
    int q,x,y;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d",&P[i]);
    for (i = 0; i < n-1; i++) scanf("%d",&W[i]);
    num = n,parent[build(0,n-1)] = -1;
    scanf("%d",&q);
    for (i = 0; i < q; i++) {
        scanf("%d %d",&x,&y);
        x--,y--;
        if (x != y) {
            swap(P[x],P[y]);
            int u = parent[x];
            while (u != -1) {
                if (L[u].find(P[y]) != L[u].end()) {
                    ans -= min(inv[u],(LLI) ((LLI) L[u].size()*R[u].size()-inv[u]));
                    L[u].erase(P[y]),inv[u] -= R[u].size()-R[u].order_of_key(P[y]);
                    ans += min(inv[u],(LLI) ((LLI) L[u].size()*R[u].size()-inv[u]));
                }
                if (R[u].find(P[y]) != R[u].end()) {
                    ans -= min(inv[u],(LLI) ((LLI) L[u].size()*R[u].size()-inv[u]));
                    R[u].erase(P[y]),inv[u] -= L[u].order_of_key(P[y]);
                    ans += min(inv[u],(LLI) ((LLI) L[u].size()*R[u].size()-inv[u]));
                }
                u = parent[u];
            }
            u = parent[y];
            while (u != -1) {
                if (L[u].find(P[x]) != L[u].end()) {
                    ans -= min(inv[u],(LLI) ((LLI) L[u].size()*R[u].size()-inv[u]));
                    L[u].erase(P[x]),inv[u] -= R[u].size()-R[u].order_of_key(P[x]);
                    ans += min(inv[u],(LLI) ((LLI) L[u].size()*R[u].size()-inv[u]));
                }
                if (R[u].find(P[x]) != R[u].end()) {
                    ans -= min(inv[u],(LLI) ((LLI) L[u].size()*R[u].size()-inv[u]));
                    R[u].erase(P[x]),inv[u] -= L[u].order_of_key(P[x]);
                    ans += min(inv[u],(LLI) ((LLI) L[u].size()*R[u].size()-inv[u]));
                }
                u = parent[u];
            }
            u = parent[x];
            while (u != -1) {
                if (x <= mm[u]) {
                    ans -= min(inv[u],(LLI) ((LLI) L[u].size()*R[u].size()-inv[u]));
                    L[u].insert(P[x]),inv[u] += R[u].size()-R[u].order_of_key(P[x]);
                    ans += min(inv[u],(LLI) ((LLI) L[u].size()*R[u].size()-inv[u]));
                }
                else {
                    ans -= min(inv[u],(LLI) ((LLI) L[u].size()*R[u].size()-inv[u]));
                    R[u].insert(P[x]),inv[u] += L[u].order_of_key(P[x]);
                    ans += min(inv[u],(LLI) ((LLI) L[u].size()*R[u].size()-inv[u]));
                }
                u = parent[u];
            }
            u = parent[y];
            while (u != -1) {
                if (y <= mm[u]) {
                    ans -= min(inv[u],(LLI) ((LLI) L[u].size()*R[u].size()-inv[u]));
                    L[u].insert(P[y]),inv[u] += R[u].size()-R[u].order_of_key(P[y]);
                    ans += min(inv[u],(LLI) ((LLI) L[u].size()*R[u].size()-inv[u]));
                }
                else {
                    ans -= min(inv[u],(LLI) ((LLI) L[u].size()*R[u].size()-inv[u]));
                    R[u].insert(P[y]),inv[u] += L[u].order_of_key(P[y]);
                    ans += min(inv[u],(LLI) ((LLI) L[u].size()*R[u].size()-inv[u]));
                }
                u = parent[u];
            }
        }
        printf("%I64d\n",ans);
    }

    return 0;
}