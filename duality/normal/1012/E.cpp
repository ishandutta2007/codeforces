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

int a[200000],b[200000];
vi pos[200000];
int p[200000],nxt[200000];
int parent[200000];
int find(int n) {
    if (parent[n] != n) parent[n] = find(parent[n]);
    return parent[n];
}
int visited[200000];
vi cycles[200000];
int main() {
    int i;
    int n,s;
    scanf("%d %d",&n,&s);
    for (i = 0; i < n; i++) scanf("%d",&a[i]),b[i] = a[i];
    sort(b,b+n);
    for (i = 0; i < n; i++) a[i] = lower_bound(b,b+n,a[i])-b;
    for (i = 0; i < n; i++) b[i] = a[i];
    sort(b,b+n);

    int j,c = 0;
    for (i = 0; i < n; i++) {
        if (a[i] != b[i]) pos[b[i]].pb(i),c++;
        parent[i] = i,p[i] = -1;
    }
    if (c > s) {
        printf("-1\n");
        return 0;
    }
    for (i = 0; i < n; i++) {
        if (a[i] == b[i]) nxt[i] = i;
        else nxt[i] = pos[a[i]].back(),pos[a[i]].pop_back();
        int pa = find(i),pb = find(nxt[i]);
        if (pa != pb) parent[pa] = pb;
    }
    for (i = 0; i < n; i++) {
        if (a[i] == b[i]) continue;
        if (p[a[i]] != -1) {
            int pa = find(p[a[i]]),pb = find(i);
            if (pa != pb) {
                int t = nxt[p[a[i]]];
                nxt[p[a[i]]] = nxt[i];
                nxt[i] = t;
                parent[pa] = pb;
            }
        }
        p[a[i]] = i;
    }
    int cc = 0;
    for (i = 0; i < n; i++) {
        if (!visited[i] && (i != nxt[i])) {
            int u = i;
            do cycles[cc].pb(u),visited[u] = 1,u = nxt[u]; while (u != i);
            cc++;
        }
    }
    int x = min(s-c,cc);
    printf("%d\n",cc-x+min(x,2));
    int sum = 0;
    if (x > 0) {
        for (i = 0; i < x; i++) sum += cycles[i].size();
        printf("%d\n",sum);
        for (i = 0; i < x; i++) {
            for (j = 0; j < cycles[i].size(); j++) printf("%d ",cycles[i][j]+1);
        }
        printf("\n");
        if (x > 1) {
            printf("%d\n",x);
            for (i = x-1; i >= 0; i--) printf("%d ",cycles[i][0]+1);
            printf("\n");
        }
    }
    for (i = x; i < cc; i++) {
        printf("%d\n",cycles[i].size());
        for (j = 0; j < cycles[i].size(); j++) printf("%d ",cycles[i][j]+1);
        printf("\n");
    }

    return 0;
}