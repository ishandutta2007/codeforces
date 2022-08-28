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

int a[200000];
vi pos[200001];
int tree[1 << 19],lazy[1 << 19];
int prop(int s,int e,int i) {
    if (lazy[i] != 0) tree[i] = lazy[i];
    if (s != e) {
        if (lazy[i] != 0) lazy[2*i+1] = lazy[2*i+2] = lazy[i];
    }
    lazy[i] = 0;
    return 0;
}
int update(int s,int e,int as,int ae,int i,int num) {
    prop(s,e,i);
    if ((s > ae) || (e < as)) return 0;
    else if ((s >= as) && (e <= ae)) {
        lazy[i] = num;
        prop(s,e,i);
        return 0;
    }

    int mid = (s+e) / 2;
    update(s,mid,as,ae,2*i+1,num),update(mid+1,e,as,ae,2*i+2,num);
    return 0;
}
vi v;
int getAll(int s,int e,int i) {
    prop(s,e,i);
    if (s == e) {
        v.pb(tree[i]);
        return 0;
    }

    int mid = (s+e) / 2;
    getAll(s,mid,2*i+1),getAll(mid+1,e,2*i+2);
    return 0;
}
int main() {
    int i;
    int n,q;
    scanf("%d %d",&n,&q);
    for (i = 0; i < n; i++) scanf("%d",&a[i]),pos[a[i]].pb(i);

    int p = -1;
    if (!pos[0].empty()) p = pos[0][0];
    else {
        if (pos[q].empty()) {
            printf("NO\n");
            return 0;
        }
        else p = pos[q][0];
    }
    update(0,n-1,0,n-1,0,1);
    for (i = 1; i <= q; i++) {
        if (pos[i].empty()) update(0,n-1,p,p,0,i);
        else update(0,n-1,pos[i][0],pos[i].back(),0,i);
    }
    getAll(0,n-1,0);
    for (i = 0; i < n; i++) {
        if ((a[i] != 0) && (a[i] != v[i])) {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    for (i = 0; i < n; i++) printf("%d ",v[i]);
    printf("\n");

    return 0;
}