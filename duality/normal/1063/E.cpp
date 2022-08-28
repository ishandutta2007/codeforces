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

int a[1000],p[1000],visited[1000];
char ans[1000][1000];
int main() {
    int i;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d",&a[i]),p[--a[i]] = i;

    int j;
    vi v;
    for (i = 0; i < n; i++) {
        if (a[i] != i) v.pb(i);
    }
    if (v.empty()) {
        printf("%d\n",n);
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) printf(".");
            printf("\n");
        }
        return 0;
    }
    for (i = 0; i < v.size(); i++) {
        if (a[v[i]] > a[v.back()]) swap(v[i],v.back());
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) ans[i][j] = '.';
    }
    debug "here";
    printArr(v,v.size());
    int c = 0;
    int u = p[v.back()];
    visited[v.back()] = 1;
    while (u != v.back()) {
        visited[u] = 1;
        ans[n-c-1][u] = ans[n-c-1][a[u]] = (a[u] < u) ? '\\':'/',c++;
        u = p[u];
    }
    debug "here";
    int pp = c;
    c++;
    ans[n-pp-1][a[v.back()]] = '/';
    assert(pp <= n-1);
    int l = -1,l2;
    int e = a[v.back()];
    sort(v.begin(),v.end()-1);
    for (i = 0; i < v.size(); i++) {
        if (!visited[v[i]]) {
            int u = v[i];
            ans[n-pp-1][u] = '/';
            if (l != -1) {
                ans[n-c-1][l2] = ans[n-c-1][u] = (l2 < u) ? '\\':'/',c++;
            }
            l = a[u],l2 = a[u];
            do {
                visited[u] = 1;
                if (p[u] != v[i]) ans[n-c-1][u] = ans[n-c-1][p[u]] = (p[u] > u) ? '\\':'/',c++;
                u = p[u];
            } while (u != v[i]);
        }
    }
    if (l != -1) ans[n-c-1][l] = ans[n-c-1][e] = (l < e) ? '\\':'/',c++;
    assert(c <= n);
    printf("%d\n",n-1);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) printf("%c",ans[i][j]);
        printf("\n");
    }

    return 0;
}