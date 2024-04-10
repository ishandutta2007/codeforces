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

int x[2000],y[2000],a[2000];
vi v;
int p;
bool comp(int a,int b) {
    return (LLI) (x[a]-x[p])*(y[b]-y[p]) > (LLI) (x[b]-x[p])*(y[a]-y[p]);
}
int parent[2000];
int find(int n) {
    if (parent[n] != n) parent[n] = find(parent[n]);
    return parent[n];
}
int merge(int a,int b) {
    a = find(a),b = find(b);
    if (a != b) parent[a] = b;
    return 0;
}
vpii ans;
int main() {
    int i;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d %d %d",&x[i],&y[i],&a[i]),a[i]--;

    p = -1;
    for (i = 0; i < n; i++) {
        if ((a[i] != i) && ((p == -1) || (mp(x[i],y[i]) < mp(x[p],y[p])))) p = i;
    }
    if (p == -1) {
        printf("0\n");
        return 0;
    }
    for (i = 0; i < n; i++) {
        parent[i] = i;
        if ((i != p) && (a[i] != i)) v.pb(i);
    }
    sort(v.begin(),v.end(),comp);
    for (i = 0; i < v.size(); i++) merge(v[i],a[v[i]]);
    for (i = 1; i < v.size(); i++) {
        if (find(v[i]) != find(v[i-1])) {
            merge(v[i],v[i-1]);
            ans.pb(mp(v[i],v[i-1]));
            swap(a[v[i]],a[v[i-1]]);
        }
    }
    int u = p;
    while (a[u] != p) {
        ans.pb(mp(p,a[u]));
        u = a[u];
    }
    printf("%d\n",ans.size());
    for (i = 0; i < ans.size(); i++) printf("%d %d\n",ans[i].first+1,ans[i].second+1);

    return 0;
}