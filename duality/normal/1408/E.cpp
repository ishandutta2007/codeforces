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

int a[100000],b[100000];
vector<pair<int,pii> > edges;
int parent[200000];
int find(int n) {
    if (parent[n] != n) parent[n] = find(parent[n]);
    return parent[n];
}
int main() {
    int i,j;
    int m,n,s,x;
    LLI sum = 0;
    scanf("%d %d",&m,&n);
    for (i = 0; i < m; i++) scanf("%d",&a[i]);
    for (i = 0; i < n; i++) scanf("%d",&b[i]);
    for (i = 0; i < m; i++) {
        scanf("%d",&s);
        for (j = 0; j < s; j++) scanf("%d",&x),x--,edges.pb(mp(a[i]+b[x],mp(i,x+m))),sum += a[i]+b[x];
    }

    for (i = 0; i < m+n; i++) parent[i] = i;
    sort(edges.begin(),edges.end());
    reverse(edges.begin(),edges.end());
    for (i = 0; i < edges.size(); i++) {
        int u = edges[i].second.first,v = edges[i].second.second;
        if (find(u) != find(v)) sum -= edges[i].first,parent[find(u)] = find(v);
    }
    printf("%I64d\n",sum);

    return 0;
}