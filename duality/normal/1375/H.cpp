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

int num;
int a[1 << 12],b[1 << 12],k[1 << 16];
vpii sol;
vi tree[1 << 13];
map<pii,int> M[1 << 13];
int build(int s,int e,int i) {
    if (s == e) {
        tree[i].pb(b[s]);
        M[i][mp(0,0)] = b[s];
        return 0;
    }

    int mid = (s+e) / 2;
    build(s,mid,2*i+1),build(mid+1,e,2*i+2);
    tree[i].resize(e-s+1);
    merge(tree[2*i+1].begin(),tree[2*i+1].end(),tree[2*i+2].begin(),tree[2*i+2].end(),tree[i].begin());
    return 0;
}
int query(int s,int e,int l,int r,int i) {
    l = lower_bound(tree[i].begin(),tree[i].end(),l)-tree[i].begin();
    r = upper_bound(tree[i].begin(),tree[i].end(),r)-tree[i].begin()-1;
    if (l > r) return -1;
    else if (M[i].count(mp(l,r))) return M[i][mp(l,r)];

    int mid = (s+e) / 2;
    int a = query(s,mid,tree[i][l],tree[i][r],2*i+1),b = query(mid+1,e,tree[i][l],tree[i][r],2*i+2);
    if (a == -1) M[i][mp(l,r)] = b;
    else if (b == -1) M[i][mp(l,r)] = a;
    else {
        sol.pb(mp(a,b));
        M[i][mp(l,r)] = num++;
    }
    return M[i][mp(l,r)];
}
int main() {
    int i;
    int n,q,l,r;
    scanf("%d %d",&n,&q),num = n;
    for (i = 0; i < n; i++) scanf("%d",&a[i]),b[--a[i]] = i;
    build(0,n-1,0);
    for (i = 0; i < q; i++) {
        scanf("%d %d",&l,&r);
        l--,r--;
        k[i] = query(0,n-1,l,r,0);
    }
    printf("%d\n",num);
    for (i = 0; i < sol.size(); i++) printf("%d %d\n",sol[i].first+1,sol[i].second+1);
    for (i = 0; i < q; i++) printf("%d ",k[i]+1);
    printf("\n");

    return 0;
}